#include "G4VSensitiveDetector.hh"
#include "G4Step.hh"

#include "G4AnalysisManager.hh"

class G4Step;

class MyTrackerSD : public G4VSensitiveDetector
{
public:
  MyTrackerSD(G4String name);
  virtual ~MyTrackerSD() override;
// private:
  virtual G4bool ProcessHits(G4Step* aStep, G4TouchableHistory* R0hist) override;
};