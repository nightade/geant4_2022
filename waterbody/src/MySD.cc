#include "MySD.hh"
#include "G4VTouchable.hh"

// #include "G4VSensitiveDetector.hh"

MyTrackerSD::MyTrackerSD(G4String name) : G4VSensitiveDetector(name) {}
MyTrackerSD::~MyTrackerSD() {}

G4bool MyTrackerSD::ProcessHits(G4Step* aStep, G4TouchableHistory* R0hist)
{
  if (R0hist) {G4cout << ":v" << G4endl;}
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
  G4cout << "Detector position: " << posDetector << G4endl;

  G4AnalysisManager* man = G4AnalysisManager::Instance();
  man->FillNtupleDColumn(0, posDetector[0]);
  man->FillNtupleDColumn(1, posDetector[1]);
  man->FillNtupleDColumn(2, posDetector[2]);
  man->FillNtupleDColumn(3, edep);
  man->AddNtupleRow(0);
  return true;
}
