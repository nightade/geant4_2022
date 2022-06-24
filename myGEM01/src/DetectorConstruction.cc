#include "DetectorConstruction.hh"
#include "DetectorMessenger.hh"
#include "SensitiveDetector.hh"
#include "F02ElectricFieldSetup.hh"

#include "G4RunManager.hh" // remove this later
#include "G4NistManager.hh"

// #include "G4ThreeVector.hh"
#include "G4Material.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Cons.hh"
#include "G4UnionSolid.hh"
#include "G4SubtractionSolid.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4AutoDelete.hh"


DetectorConstruction::DetectorConstruction() : fMessenger(new DetectorMessenger(this))
{
  G4cout << ">> [DetectorConstruction] Class Constructed!" << G4endl;
}
DetectorConstruction::~DetectorConstruction() { delete fMessenger; }

G4VPhysicalVolume* DetectorConstruction::Construct()
{
  G4cout << ">> [DetectorConstruction] Method 'Construct' has been called." << G4endl;

  DefineMaterials();  
  return DefineVolumes();
}

void DetectorConstruction::DefineMaterials()
{
  G4NistManager* nist = G4NistManager::Instance();

  fWorldMaterial = nist->FindOrBuildMaterial("G4_Ar");
  fChamberMaterial = nist->FindOrBuildMaterial("G4_Ar");
  fTargetMaterial = fChamberMaterial;
  fGEMMaterial = nist->FindOrBuildMaterial("G4_Kapton");
  fFoilMaterial = nist->FindOrBuildMaterial("G4_Cu");

  G4cout << ">> [DetectorConstruction] Materials have been defined as follows" << G4endl;
  G4cout << ">> ... World   : " << fWorldMaterial->GetName() << G4endl;
  G4cout << ">> ... Chamber : " << fChamberMaterial->GetName() << G4endl;
  G4cout << ">> ... Target  : " << fTargetMaterial->GetName() << G4endl;
  G4cout << ">> ... GEM     : " << fGEMMaterial->GetName() << G4endl;
  G4cout << ">> ... Foil     : " << fFoilMaterial->GetName() << G4endl;
}

G4VPhysicalVolume* DetectorConstruction::DefineVolumes()
{
  // CONTROL PANEL ===================================== 
  fChamberSize = G4ThreeVector(100*um, 100*um, 120*um);
  fChamberPos = G4ThreeVector();
  G4ThreeVector WorldSize = 1.2 * fChamberSize;
  
  fTargetSize = G4ThreeVector(fChamberSize[0], fChamberSize[1], 5*um);
  fTargetPos = G4ThreeVector(0, 0, -(fChamberSize[2] + fTargetSize[2])/2);

  G4double holeDiam1 = 70*um;
  G4double holeDiam2 = 30*um;

  G4ThreeVector gemSize = G4ThreeVector(fChamberSize[0], fChamberSize[1], 50*um);
  G4ThreeVector foilSize = G4ThreeVector(fChamberSize[0], fChamberSize[1], 5*um);
  G4ThreeVector gemUnitZ = G4ThreeVector(0, 0, gemSize[2]/4);
  G4ThreeVector foilPos = G4ThreeVector(0, 0, (gemSize[2] + foilSize[2])/2);

  G4ThreeVector sensorSize = G4ThreeVector(5*um, 5*um, fTargetSize[2]);
  G4double sensorUnit = 1*um;
  G4String strSensorUnit = " [um] ";

  G4ThreeVector port = G4ThreeVector(0, 0, fChamberSize[2]/2);
  NumberManager::Instance()->SetBeamPort(port);
  NumberManager::Instance()->SetSensorUnit(sensorUnit);

  // Set LV's & PV's ===================================== 
  G4Box* worldSolid = new G4Box("WorldBox",
                                0.5*WorldSize[0], 0.5*WorldSize[1], 0.5*WorldSize[2]);
  G4LogicalVolume* worldLV = new G4LogicalVolume(worldSolid, fWorldMaterial, "WorldLV");
  G4VPhysicalVolume* worldPV = new G4PVPlacement(0, G4ThreeVector(), worldLV, "WorldPV", 0, false, 0, true);

  G4Box* chamberSolid = new G4Box("ChamberBox",
                                0.5*fChamberSize[0], 0.5*fChamberSize[1], 0.5*fChamberSize[2]);
  fLogicChamber = new G4LogicalVolume(chamberSolid, fChamberMaterial, "ChamberLV");
  new G4PVPlacement(0, fChamberPos, fLogicChamber, "ChamberPV", worldLV, false, 0, true);

  G4Box* targetSolid = new G4Box("TargetBox",
                                0.5*fTargetSize[0], 0.5*fTargetSize[1], 0.5*fTargetSize[2]);
  fLogicTarget = new G4LogicalVolume(targetSolid, fTargetMaterial, "TargetLV");
  new G4PVPlacement(0, fTargetPos, fLogicTarget, "TargetPV", worldLV, false, 0, true);

  G4double dDiam = holeDiam1-holeDiam2;
  G4Box* gemBox = new G4Box("GemBOX", 0.5*gemSize[0], 0.5*gemSize[1], 0.5*gemSize[2]);  
  G4Cons* gemCon1 = new G4Cons("GemCON1", 0, 0.5*(holeDiam1 + dDiam), 0, 0.5*holeDiam2,
                              2*gemUnitZ[2], 0, 360*deg);
  G4Cons* gemCon2 = new G4Cons("GemCON2", 0, 0.5*holeDiam2, 0, 0.5*(holeDiam1 + dDiam),
                              2*gemUnitZ[2], 0, 360*deg);
  G4UnionSolid* gemHole = new G4UnionSolid("GemHole", gemCon1, gemCon2, 0, 4*gemUnitZ);

  G4SubtractionSolid* gemSolid = new G4SubtractionSolid("GemSolid", gemBox, gemHole, 0, -2*gemUnitZ);
  fLogicGEM = new G4LogicalVolume(gemSolid, fGEMMaterial, "GemLV");
  new G4PVPlacement(0, G4ThreeVector(), fLogicGEM, "GemPV", fLogicChamber, false, 0, true);

  G4Box* foilBox = new G4Box("FoilBOX", 0.5*foilSize[0], 0.5*foilSize[1], 0.5*foilSize[2]);  
  G4Tubs* foilTub = new G4Tubs("Foil", 0, 0.5*holeDiam1, foilSize[2], 0, 360*deg);
  G4SubtractionSolid* foilSolid = new G4SubtractionSolid("FoilSolid", foilBox, foilTub);
  fLogicFoil = new G4LogicalVolume(foilSolid, fFoilMaterial, "FoildLV");
  new G4PVPlacement(0, foilPos, fLogicFoil, "FoilPV", fLogicChamber, false, 0, true);
  new G4PVPlacement(0, -foilPos, fLogicFoil, "FoilPV", fLogicChamber, false, 1, true);

  G4VisAttributes* wireframeAtt = new G4VisAttributes();
  G4VisAttributes* KaptonAtt = new G4VisAttributes(G4Colour(0.8, 0.8, 0.8, 0.4));
  G4VisAttributes* FoilAtt = new G4VisAttributes(G4Colour(0.9, 0.72, 0.08, 0.4));
  wireframeAtt->SetForceWireframe(true);
  KaptonAtt->SetForceSolid(true);
  FoilAtt->SetForceSolid(true);

  worldLV->SetVisAttributes(false);
  fLogicTarget->SetVisAttributes(false);
  fLogicGEM->SetVisAttributes(KaptonAtt);
  fLogicFoil->SetVisAttributes(FoilAtt);

  // Set Target as scoring volume
  fScoringVolume = fLogicTarget;

  // Sensitive Detector
  G4Box* sensorSolid = new G4Box("sensorBox",
                                0.5*sensorSize[0], 0.5*sensorSize[1], 0.5*sensorSize[2]);
  fLogicSensitive = new G4LogicalVolume(sensorSolid, fChamberMaterial, "sensorLV");
  
  int sensorHalfNumX = int(fTargetSize[0] / (2*sensorSize[0]));
  int sensorHalfNumY = int(fTargetSize[1] / (2*sensorSize[1]));
  for(int i=-sensorHalfNumX; i < sensorHalfNumX; i++){
    for(int j=-sensorHalfNumY; j < sensorHalfNumY; j++){
      new G4PVPlacement(
        0,
        fTargetPos + G4ThreeVector((i+0.5)*sensorSize[0], (j+0.5)*sensorSize[1], 0),
        fLogicSensitive,
        "sensorPV",
        worldLV,
        2*sensorHalfNumX*i + j,
        true);
    }
  }

  G4cout << ">> [DetectorConstruction] Volumes have been defined as follows" << G4endl;
  G4cout << "... Chamber : " << fChamberSize / sensorUnit << strSensorUnit << G4endl;
  G4cout << "... Target : " << fTargetSize / sensorUnit << strSensorUnit;
  G4cout << "at " << fTargetPos / sensorUnit << strSensorUnit  << G4endl;

  return worldPV;
}

void DetectorConstruction::ConstructSDandField()
{
  G4String SDname = "MySensitiveDetector";
  SensitiveDetector* sensDet = new SensitiveDetector(SDname);
  if (fLogicSensitive != NULL){
    fLogicSensitive->SetSensitiveDetector(sensDet);
  }

  if (!fFieldSetup) { 
    fFieldSetup = new F02ElectricFieldSetup(); // Default : (0, 0.1GV/cm, 0)
    G4AutoDelete::Register(fFieldSetup); //Kernel will delete the messenger
  }
}

// ===== Command Methods =====
  void DetectorConstruction::SetChamberMaterial(G4String newmatName)
  {
    G4NistManager* nist = G4NistManager::Instance();
    G4Material* newMaterial = nist->FindOrBuildMaterial(newmatName);
    if(newMaterial)
    {
      fChamberMaterial = newMaterial;
      fLogicChamber->SetMaterial(newMaterial);
      fLogicSensitive->SetMaterial(newMaterial);
      G4cout << ">> Chamber Material has been changed to " << newmatName << G4endl;
    } else
    {
      G4cout << ">> WARNING! " << newmatName << "not found from the nist list" << G4endl;
    }
  }
  void DetectorConstruction::SetChamberSize(G4ThreeVector newSize)
  {
    delete fLogicChamber->GetSolid();
    fChamberSize = newSize;
    G4Box* newSolid = new G4Box("ChamberBox",
                                0.5*fChamberSize[0], 0.5*fChamberSize[1], 0.5*fChamberSize[2]);
    fLogicChamber->SetSolid(newSolid);
  }
  void DetectorConstruction::SetChamberPos(G4ThreeVector newPos)
  {
    G4cout << ">> WIP (you sure you need this command tho?)" << G4endl;
    G4cout << newPos << G4endl;
  }
  
  void DetectorConstruction::SetTargetMaterial(G4String newmatName)
  {
    G4NistManager* nist = G4NistManager::Instance();
    G4Material* newMaterial = nist->FindOrBuildMaterial(newmatName);
    if(newMaterial)
    {
      fChamberMaterial = newMaterial;
      fLogicTarget->SetMaterial(newMaterial);
      G4cout << ">> Target Material has been changed to " << newmatName << G4endl;
    } else
    {
      G4cout << ">> WARNING! " << newmatName << "not found from the nist list" << G4endl; 
    }
  }
  void DetectorConstruction::SetTargetSize(G4ThreeVector newSize)
  {
    delete fLogicTarget->GetSolid();
    fTargetSize = newSize;
    G4Box* newSolid = new G4Box("TargetBox",
                              0.5*fTargetSize[0], 0.5*fTargetSize[1], 0.5*fTargetSize[2]);
    fLogicTarget->SetSolid(newSolid);
  }
  void DetectorConstruction::SetTargetPos(G4ThreeVector newPos)
  {
    G4cout << ">> WIP (you sure you need this command tho?)" << G4endl;
    G4cout << newPos << G4endl;
  }

  void DetectorConstruction::ViewMaterialList()
  { G4cout << *(G4Material::GetMaterialTable()) << G4endl; }