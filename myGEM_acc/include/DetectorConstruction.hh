#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
#include "G4ThreeVector.hh"

class G4VPhysicalVolume;  
class G4LogicalVolume;
class G4Material;
class F02ElectricFieldSetup;

class DetectorConstruction: public G4VUserDetectorConstruction
{
public:
  DetectorConstruction();
  ~DetectorConstruction() override; 
  
  virtual G4VPhysicalVolume* Construct() override;
  void ConstructSDandField() override;

  // Getters
  G4LogicalVolume* GetScoringVolume() const { return fScoringVolume; }

private:   
  // Members
  G4LogicalVolume* fScoringVolume = nullptr; // Mandatory

  G4Material* fWorldMaterial = nullptr;
  G4Material* fChamberMaterial = nullptr;
  G4Material* fTargetMaterial = nullptr;
  G4Material* fGEMMaterial = nullptr;

  G4LogicalVolume* fLogicWorld = nullptr;
  G4LogicalVolume* fLogicChamber = nullptr;
  G4LogicalVolume* fLogicTarget = nullptr;
  G4LogicalVolume* fLogicGEM = nullptr;
  G4LogicalVolume* fLogicSensitive = nullptr; // Used in ConstrucSDnF

  // (X-size, Y-size, Z-size)
  // Reminder: Construct() requires half of those values
  G4ThreeVector fChamberSize;
  G4ThreeVector fTargetSize;

  // Reminder: the position points to the center of the volume
  G4ThreeVector fChamberPos;
  G4ThreeVector fTargetPos;

  F02ElectricFieldSetup* fFieldSetup = nullptr;
};