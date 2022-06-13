#include "DetectorMessenger.hh"
#include "DetectorConstruction.hh"

#include "G4UIdirectory.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWith3VectorAndUnit.hh"
#include "G4UIcmdWithoutParameter.hh"

DetectorMessenger::DetectorMessenger(DetectorConstruction* det)
 : fDetectorConstruction(det)
{
  fDirectory = new G4UIdirectory("/det/");
  fDirectory->SetGuidance("Detector construction control");

  fCmdChamberMaterial = new G4UIcmdWithAString("/det/setChamberMaterial",this);
  fCmdChamberMaterial->SetGuidance("Change Material of the Target.");
  fCmdChamberMaterial->SetParameterName("Material_Name",false);
  fCmdChamberMaterial->AvailableForStates(G4State_PreInit,G4State_Idle);

  fCmdTargetMaterial = new G4UIcmdWithAString("/det/setTargetMaterial",this);
  fCmdTargetMaterial->SetGuidance("Change Material of the Chamber.");
  fCmdTargetMaterial->SetParameterName("Material_Name",false);
  fCmdTargetMaterial->AvailableForStates(G4State_PreInit,G4State_Idle);

  fCmdChamberSize = new G4UIcmdWith3VectorAndUnit("/det/setChamberSize",this);
  fCmdChamberSize->SetGuidance("Change Size of the Chamber.");
  fCmdChamberSize->SetUnitCategory("Length");
  fCmdChamberSize->SetParameterName("X", "Y", "Z", "Unit", false);
  fCmdChamberSize->AvailableForStates(G4State_PreInit,G4State_Idle);

  fCmdTargetSize = new G4UIcmdWith3VectorAndUnit("/det/setTargetrSize",this);
  fCmdTargetSize->SetGuidance("Change Size of the Target.");
  fCmdTargetSize->SetUnitCategory("Length");
  fCmdTargetSize->SetParameterName("X", "Y", "Z", "Unit", false);
  fCmdTargetSize->AvailableForStates(G4State_PreInit,G4State_Idle);

  fCmdChamberPos = new G4UIcmdWith3VectorAndUnit("/det/setChamberPos",this);
  fCmdChamberPos->SetGuidance("Change Position of the Chamber.");
  fCmdChamberPos->SetUnitCategory("Length");
  fCmdChamberPos->SetParameterName("X", "Y", "Z", "Unit", false);
  fCmdChamberPos->AvailableForStates(G4State_PreInit,G4State_Idle);

  fCmdTargetPos = new G4UIcmdWith3VectorAndUnit("/det/setTargetPos",this);
  fCmdTargetPos->SetGuidance("Change Position of the Target.");
  fCmdTargetPos->SetUnitCategory("Length");
  fCmdTargetPos->SetParameterName("X", "Y", "Z", "Unit", false);
  fCmdTargetPos->AvailableForStates(G4State_PreInit,G4State_Idle);

  fCmdviewMatList = new G4UIcmdWithoutParameter("/det/viewMaterialList",this);
  fCmdTargetPos->SetGuidance("View an entire list of G4Materials");
  fCmdTargetPos->AvailableForStates(G4State_PreInit,G4State_Idle);
}

DetectorMessenger::~DetectorMessenger()
{
  delete fCmdChamberMaterial;
  delete fCmdChamberSize;
  delete fCmdChamberPos;
    
  delete fCmdTargetMaterial;
  delete fCmdTargetSize;
  delete fCmdTargetPos;

  delete fCmdviewMatList;  
}

void DetectorMessenger::SetNewValue(G4UIcommand* command,G4String newValue)
{
  if( command == fCmdChamberMaterial )
   { fDetectorConstruction->SetTargetMaterial(newValue);}

  if( command == fCmdTargetMaterial )
   { fDetectorConstruction->SetTargetMaterial(newValue);}

  if( command == fCmdChamberSize )
  { fDetectorConstruction->SetChamberSize(fCmdChamberSize->GetNew3VectorValue(newValue)); }

  if( command == fCmdTargetSize )
  { fDetectorConstruction->SetTargetSize(fCmdTargetSize->GetNew3VectorValue(newValue)); }

  if( command == fCmdChamberPos )
  { fDetectorConstruction->SetChamberPos(fCmdChamberPos->GetNew3VectorValue(newValue)); }

  if( command == fCmdTargetPos )
  { fDetectorConstruction->SetTargetPos(fCmdTargetPos->GetNew3VectorValue(newValue)); }

  if( command == fCmdviewMatList )
  { fDetectorConstruction->ViewMaterialList(); }
}

