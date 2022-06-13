#include "SensitiveDetector.hh"

#include "G4VTouchable.hh"
#include "G4SystemOfUnits.hh"

SensitiveDetector::SensitiveDetector(G4String name) : G4VSensitiveDetector(name) {}
SensitiveDetector::~SensitiveDetector() {}

G4bool SensitiveDetector::ProcessHits(G4Step* aStep, G4TouchableHistory* R0hist)
{
  if (R0hist) {G4cout << ":v" << G4endl;}
  NumberManager* numan = NumberManager::Instance();

  // G4double edep = aStep->GetTotalEnergyDeposit();
  // if (edep==0.) { return false; }

  G4StepPoint* preStepPoint = aStep->GetPreStepPoint();
  G4double kin = preStepPoint->GetKineticEnergy();
  numan->AddupKin(kin);

  const G4VTouchable* touchable = preStepPoint->GetTouchable();
  G4VPhysicalVolume* HitPV = touchable->GetVolume();
  G4ThreeVector posDetector = HitPV->GetTranslation();

  G4AnalysisManager* man = G4AnalysisManager::Instance();
  G4double sensorUnit = numan->GetSensorUnit();
  man->FillNtupleDColumn(0, posDetector[0] / sensorUnit);
  man->FillNtupleDColumn(1, posDetector[1] / sensorUnit);
  man->FillNtupleDColumn(2, posDetector[2] / sensorUnit);
  man->FillNtupleDColumn(3, kin / eV);
  man->AddNtupleRow(0);

  numan->AddupSDHitCount();

  G4Track *track = aStep->GetTrack();
  track->SetTrackStatus(fStopAndKill);

  return true;
}