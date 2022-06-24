#include "G4UserSteppingAction.hh"
#include "globals.hh"

class G4LogicalVolume;
class NumberManager;

class SteppingAction : public G4UserSteppingAction
{
  public:
    SteppingAction();
    ~SteppingAction() override;

    void UserSteppingAction(const G4Step*) override;

  private:
    NumberManager* fNuman = nullptr;
    G4LogicalVolume* fScoringVolume = nullptr;
};