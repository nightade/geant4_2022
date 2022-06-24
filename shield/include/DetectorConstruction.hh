#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
#include "G4ThreeVector.hh"
// class G4ThreeVector;
class G4VPhysicalVolume;  
class G4LogicalVolume;
class G4Material;
class DetectorMessenger;
// class G4GlobalMagFieldMessenger;

class DetectorConstruction: public G4VUserDetectorConstruction
{
public:
  DetectorConstruction();
  ~DetectorConstruction() override; 
  
  virtual G4VPhysicalVolume* Construct() override;
  void ConstructSDandField() override;

  // Command Methods
  void SetChamberMaterial(G4String); // Chamber
  void SetChamberSize(G4ThreeVector);
  void SetChamberPos(G4ThreeVector);
  
  void SetTargetMaterial(G4String); // Target
  void SetTargetSize(G4ThreeVector);
  void SetTargetPos(G4ThreeVector);

  void ViewMaterialList();

  // Getters
  G4LogicalVolume* GetScoringVolume() const { return fScoringVolume; }

private:
  void DefineMaterials();
  G4VPhysicalVolume* DefineVolumes();

  // Static Members
  // static G4GlobalMagFieldMessenger*  fMagFieldMessenger;
   
  // Members
  G4LogicalVolume* fScoringVolume = nullptr; // <--Mandatory

  G4LogicalVolume*  fLogicChamber = nullptr;
  G4LogicalVolume* fLogicTarget = nullptr;
  G4LogicalVolume* fLogicShield = nullptr;
  G4LogicalVolume* fLogicSensitive = nullptr;

  G4Material* fWorldMaterial = nullptr;
  G4Material* fChamberMaterial = nullptr;
  G4Material* fTargetMaterial = nullptr;
  G4Material* fShieldMaterial = nullptr;

  // (X-size, Y-size, Z-size)
  // Reminder: Construct() requires half of those values
  G4ThreeVector fChamberSize;
  G4ThreeVector fTargetSize;
  G4ThreeVector fShieldSize;

  // Reminder: the position points to the center of the volume
  G4ThreeVector fChamberPos;
  G4ThreeVector fTargetPos;
  G4ThreeVector fShieldPos;

  DetectorMessenger* fMessenger = nullptr;
};