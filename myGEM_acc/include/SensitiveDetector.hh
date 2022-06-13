#include "NumberManager.hh"

#include "G4VSensitiveDetector.hh"
#include "G4Step.hh"
#include "G4AnalysisManager.hh"

class G4Step;

class SensitiveDetector : public G4VSensitiveDetector
{
public:
  SensitiveDetector(G4String name);
  virtual ~SensitiveDetector() override;
  virtual G4bool ProcessHits(G4Step* aStep, G4TouchableHistory* R0hist) override;

  G4int GetHitNum();
  void SetHitNum();

protected:
  G4int fHitCount = 0;
};