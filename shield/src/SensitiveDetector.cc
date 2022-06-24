#include "SensitiveDetector.hh"

#include "G4VTouchable.hh"
#include "G4SystemOfUnits.hh"

// #include "G4VSensitiveDetector.hh"

SensitiveDetector::SensitiveDetector(G4String name) : G4VSensitiveDetector(name) {}
SensitiveDetector::~SensitiveDetector() {}

G4bool SensitiveDetector::ProcessHits(G4Step* aStep, G4TouchableHistory* R0hist)
{
  if (R0hist) {G4cout << ":v" << G4endl;}
  NumberManager* numan = NumberManager::Instance();

  G4double edep = aStep->GetTotalEnergyDeposit();

  G4Track *track = aStep->GetTrack();
  track->SetTrackStatus(fStopAndKill);

  G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
  //G4StepPoint *postStepPoint = aStep->GetPostStepPoint();

  // G4ThreeVector posPhoton = preStepPoint->GetPosition();

  const G4VTouchable *touchable = preStepPoint->GetTouchable();
  // G4int copyNo = touchable->GetCopyNumber();

  G4VPhysicalVolume* HitPV = touchable->GetVolume();
  G4ThreeVector posDetector = HitPV->GetTranslation();

  G4AnalysisManager* man = G4AnalysisManager::Instance();
  G4double unit = numan->GetSensorUnit();
  man->FillNtupleDColumn(0, posDetector[0] / unit);
  man->FillNtupleDColumn(1, posDetector[1] / unit);
  man->FillNtupleDColumn(2, posDetector[2] / unit);
  man->FillNtupleDColumn(3, edep / MeV);
  man->AddNtupleRow(0);

  numan->AddupSDHitCount();
  return true;
}