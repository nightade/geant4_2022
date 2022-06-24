#include "MyDetectorConstruction.hh"
#include "MySD.hh"

#include "G4RunManager.hh" // Why do we need this here?
#include "G4NistManager.hh"

#include "G4Material.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

MyDetectorConstruction::MyDetectorConstruction() {}
MyDetectorConstruction::~MyDetectorConstruction() {}

//==========================================================
G4VPhysicalVolume* MyDetectorConstruction::Construct()
{
  G4NistManager* nist = G4NistManager::Instance();

  // World : Air Box 5m x 5m x 10m
  G4ThreeVector worldPos = G4ThreeVector();
  //
  G4Material* worldMat = nist->FindOrBuildMaterial("G4_AIR");
  G4Box* worldSolid = new G4Box("WorldBox", 1*m, 1*m, 5*m);
  G4LogicalVolume* worldLV = new G4LogicalVolume(worldSolid, worldMat, "WorldLV");
  G4VPhysicalVolume* worldPV = new G4PVPlacement(0, worldPos, worldLV, "WorldPV", 0, false, 0, true);

  //Envelope
  G4ThreeVector envPos = G4ThreeVector();

  G4Material* envMat = nist->FindOrBuildMaterial("G4_AIR");
  G4Box* envSolid = new G4Box("EnvBox", 1*m, 1*m, 5*m);
  G4LogicalVolume* envLV = new G4LogicalVolume(envSolid, envMat, "EnvLV");
  new G4PVPlacement(0, envPos, envLV, "EnvPV", worldLV, false, 0, true);

  // Target
  G4ThreeVector tarPos = G4ThreeVector(0, 0, 2*m);
  //
  G4Material* tarMat = nist->FindOrBuildMaterial("G4_PARAFFIN");
  G4Box* tarSolid = new G4Box("TarBox", (48/2)*cm, (170/2)*cm, (5/2)*cm);
  G4LogicalVolume* tarLV = new G4LogicalVolume(tarSolid, tarMat, "TarLV");
  new G4PVPlacement(0, tarPos, tarLV, "TarPV", envLV, false, 0, true);
  
  // Set Target as scoring volume
  fScoringVolume = tarLV;

  // Sensitive Detector
  G4double cell_w = 1*cm;
  G4double cell_h = 1*cm;
  G4double cell_z = 1*cm;
  G4Box* cellSolid = new G4Box("CellBox", cell_w/2, cell_h/2, cell_z/2);
  logicalDetector = new G4LogicalVolume(cellSolid, envMat, "CellLV");
  for(int i=-24; i < 24; i++){
    for(int j=-85; j < 85; j++){
      new G4PVPlacement(
        0,
        tarPos + G4ThreeVector((i+0.5)*cell_w, (j+0.5)*cell_h, (5/2)*cm + cell_z),
        logicalDetector,
        "CellPV",
        envLV,
        48*i + j,
        true);
    }
  }
  
  // G4cout << G4endl << "The materials defined are : " << G4endl << G4endl;
  // G4cout << *(G4Material::GetMaterialTable()) << G4endl;

  // Always return worldPV!!
  return worldPV;
}

void MyDetectorConstruction::ConstructSDandField()
{
  G4String SDname = "SensitiveDetector";
  MyTrackerSD* sensDet = new MyTrackerSD(SDname);
  if (logicalDetector != NULL){
    logicalDetector->SetSensitiveDetector(sensDet);
  }
}