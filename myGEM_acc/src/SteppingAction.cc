#include "SteppingAction.hh"
#include "NumberManager.hh"
#include "DetectorConstruction.hh"

#include "G4Step.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"

SteppingAction::SteppingAction() : fNuman(NumberManager::Instance()) {}

SteppingAction::~SteppingAction() {}

void SteppingAction::UserSteppingAction(const G4Step* step)
{
  if (!fScoringVolume) {
    const DetectorConstruction* detConstruction
      = static_cast<const DetectorConstruction*>
        (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
    fScoringVolume = detConstruction->GetScoringVolume();
  }

  G4LogicalVolume* volume
    = step->GetPreStepPoint()->GetTouchableHandle()
      ->GetVolume()->GetLogicalVolume();

  if (volume != fScoringVolume) return;

  // ========== THE ACTION ========= //
  G4double edep = step->GetTotalEnergyDeposit();
  fNuman->AddupEdep(edep);
}