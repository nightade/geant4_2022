#include "SteppingAction.hh"
#include "NumberManager.hh"
#include "DetectorConstruction.hh"

#include "G4Step.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"
#include "G4TrackVector.hh"

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

  if (volume != fScoringVolume)
  {
    auto SecVec = step->GetSecondaryInCurrentStep(); 
    G4int sizeSecVec = SecVec->size();
    if (sizeSecVec > 0)
    {
      // G4cout << "[!!!] Secondary Produced! - ";
      for (auto iter = SecVec->begin(); iter != SecVec->end(); iter++)
      {
        G4String name = (*iter)->GetParticleDefinition()->GetParticleName();
        G4double skin = (*iter)->GetKineticEnergy();
        
        // G4cout << "KE: " << (*iter)->GetKineticEnergy() / CLHEP::eV << " [eV]" << G4endl;
        if(name=="e-")
        {
          fNuman->AddupSecondECount();
          fNuman->AddupSecondKin(skin);
        }
        if((*iter)->IsBelowThreshold())
        { G4cout << "~~~~~~~~~~~~~ This secondary is below threshold!" << G4endl; }
      }
    }
    return;
  }

  G4double edep = step->GetTotalEnergyDeposit();
  fNuman->AddupEdep(edep);

}