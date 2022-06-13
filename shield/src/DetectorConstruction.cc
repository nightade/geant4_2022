#include "DetectorConstruction.hh"
#include "DetectorMessenger.hh"
#include "SensitiveDetector.hh"

#include "G4RunManager.hh" // remove this later
#include "G4NistManager.hh"

// #include "G4ThreeVector.hh"
#include "G4Material.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

#include "G4VisAttributes.hh"
#include "G4Colour.hh"

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

  fWorldMaterial = nist->FindOrBuildMaterial("G4_Galactic");
  fChamberMaterial = nist->FindOrBuildMaterial("G4_Galactic");
  fShieldMaterial = nist->FindOrBuildMaterial("G4_Be");
  fTargetMaterial = nist->FindOrBuildMaterial("G4_Galactic");

  G4cout << ">> [DetectorConstruction] Materials have been defined as follows" << G4endl;
  G4cout << ">> ... World : " << fWorldMaterial->GetName() << G4endl;
  G4cout << ">> ... Chamber : " << fChamberMaterial->GetName() << G4endl;
  G4cout << ">> ... Target : " << fTargetMaterial->GetName() << G4endl;
}

G4VPhysicalVolume* DetectorConstruction::DefineVolumes()
{
  // CONTROL PANEL ===================================== 
  fChamberSize = G4ThreeVector(6*cm, 6*cm, 6*cm);
  fChamberPos = G4ThreeVector();
  G4ThreeVector WorldSize = 1.2 * fChamberSize;
  
  G4double gapShlTar = 0.5*cm;
  fShieldSize = G4ThreeVector(3*cm, 3*cm, 0.5*cm); // =(R, R, Z)
  fShieldPos = G4ThreeVector(0, 0, (-fShieldSize[2]-gapShlTar)/2);
  
  fTargetSize = G4ThreeVector(6*cm, 6*cm, 5*mm); // Does not exist
  fTargetPos = G4ThreeVector(0, 0, (fTargetSize[2]+gapShlTar)/2);

// depended <- ForLoop, SD.cc
  G4double dSensorUnit = 1*mm;
  G4String sSensorUnit = " [mm] ";
  G4ThreeVector sensorSize = G4ThreeVector(1*mm, 1*mm, 5*mm);
  G4double sensorPosZ = fTargetPos[2];

  G4ThreeVector port = G4ThreeVector(fShieldSize[0],
                                fShieldSize[1], -fShieldSize[2]-gapShlTar/2);
  NumberManager::Instance()->SetSensorUnit(dSensorUnit);
  NumberManager::Instance()->SetBeamPort(port);

  // Set LV's & PV's ===================================== 
  G4Box* worldSolid = new G4Box("WorldBox",
                                0.5*WorldSize[0], 0.5*WorldSize[1], 0.5*WorldSize[2]);
  G4LogicalVolume* worldLV = new G4LogicalVolume(worldSolid, fWorldMaterial, "WorldLV");
  G4VPhysicalVolume* worldPV = new G4PVPlacement(0, G4ThreeVector(), worldLV, "WorldPV", 0, false, 0, true);

  G4Box* chamberSolid = new G4Box("ChamberBox",
                                0.5*fChamberSize[0], 0.5*fChamberSize[1], 0.5*fChamberSize[2]);
  fLogicChamber = new G4LogicalVolume(chamberSolid, fChamberMaterial, "ChamberLV");
  new G4PVPlacement(0, fChamberPos, fLogicChamber, "ChamberPV", worldLV, false, 0, true);
  
  G4Tubs* shieldSolid = new G4Tubs("ShieldDisc", 0, 0.5*fShieldSize[0],
                                0.5*fShieldSize[2], 0.*deg, 360*deg);
  fLogicShield = new G4LogicalVolume(shieldSolid, fShieldMaterial, "ShieldLV");
  new G4PVPlacement(0, fShieldPos, fLogicShield, "ShieldPV", fLogicChamber, false, 0, true);

  G4Box* targetSolid = new G4Box("  TargetBox",
                                0.5*fTargetSize[0], 0.5*fTargetSize[1], 0.5*fTargetSize[2]);
  fLogicTarget = new G4LogicalVolume(targetSolid, fTargetMaterial, "TargetLV");
  new G4PVPlacement(0, fTargetPos, fLogicTarget, "TargetPV", fLogicChamber, false, 0, true);
  
  G4VisAttributes* shieldAtt = new G4VisAttributes(G4Colour(0.2, 0.2, 0.2, 0.5));
  G4VisAttributes* chamberAtt = new G4VisAttributes(G4Colour(1.0, 1.0, 1.0));
  // G4VisAttributes* targetAtt = new G4VisAttributes(G4Colour(0.8, 0.8, 0.8, 0.7));
  chamberAtt->SetForceWireframe(true);
  shieldAtt->SetForceSolid(true);
  // targetAtt->SetForceSolid(true);

  worldLV->SetVisAttributes(false);
  fLogicTarget->SetVisAttributes(false);
  fLogicChamber->SetVisAttributes(chamberAtt);
  fLogicShield->SetVisAttributes(shieldAtt);
  // fLogicTarget->SetVisAttributes(targetAtt);

  // Set Target as scoring volume
  fScoringVolume = fLogicTarget;

  // Sensitive Detector
  G4Box* sensorSolid = new G4Box("sensorBox",
                                0.5*sensorSize[0], 0.5*sensorSize[1], 0.5*sensorSize[2]);
  fLogicSensitive = new G4LogicalVolume(sensorSolid, fChamberMaterial, "sensorLV");
  
  int sensorHalfNumX = int(fTargetSize[0] / (2*dSensorUnit));
  int sensorHalfNumY = int(fTargetSize[1] / (2*dSensorUnit));
  for(int i=-sensorHalfNumX; i < sensorHalfNumX; i++){
    for(int j=-sensorHalfNumY; j < sensorHalfNumY; j++){
      new G4PVPlacement(
        0,
        fTargetPos + G4ThreeVector((i+0.5)*sensorSize[0], (j+0.5)*sensorSize[1], sensorPosZ),
        fLogicSensitive,
        "sensorPV",
        fLogicChamber,
        2*sensorHalfNumX*i + j,
        true);
    }
  }

  G4cout << ">> [DetectorConstruction] Volumes have been defined as follows" << G4endl;
  G4cout << "... Chamber : " << fChamberSize / dSensorUnit << sSensorUnit << G4endl;
  G4cout << "... Target : " << fTargetSize / dSensorUnit << sSensorUnit;
  G4cout << "at " << fTargetPos / dSensorUnit << sSensorUnit  << G4endl;

  return worldPV;
}

void DetectorConstruction::ConstructSDandField()
{
  G4String SDname = "MySensitiveDetector";
  SensitiveDetector* sensDet = new SensitiveDetector(SDname);
  if (fLogicSensitive != NULL){
    fLogicSensitive->SetSensitiveDetector(sensDet);
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