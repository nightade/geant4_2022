#include "G4VUserDetectorConstruction.hh"
// #include "G4AnalysisManager.hh"
#include "globals.hh"

class G4VPhysicalVolume;  
class G4LogicalVolume;

class MyDetectorConstruction: public G4VUserDetectorConstruction
{
public:
  MyDetectorConstruction();

  virtual ~MyDetectorConstruction() override; 
  virtual G4VPhysicalVolume* Construct() override;
  void ConstructSDandField() override;

  // Getters
  G4LogicalVolume* GetScoringVolume() const { return fScoringVolume; }

protected:
  G4LogicalVolume* fScoringVolume = nullptr;
  G4LogicalVolume* logicalDetector = nullptr;
};