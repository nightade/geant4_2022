#include "SensitiveDetector.hh"

#include "G4VTouchable.hh"
#include "G4SystemOfUnits.hh"

SensitiveDetector::SensitiveDetector(G4String name) : G4VSensitiveDetector(name) {}
SensitiveDetector::~SensitiveDetector() {}

G4bool SensitiveDetector::ProcessHits(G4Step* aStep, G4TouchableHistory* R0hist)
{
  if (R0hist) {G4cout << ":v" << G4endl;}
  NumberManager* numan = NumberManager::Instance();

  // ========== Particle Filter
  G4Track *track = aStep->GetTrack();
  G4String particleName = track->GetParticleDefinition()->GetParticleName();
  G4String particleDesired = "e-";

  if (particleName != particleDesired)
  {
    G4cout << "It is" << particleName << G4endl;
    return false;
  }
  
  // ========== Kinetic Energy Collection
  G4StepPoint* preStepPoint = aStep->GetPreStepPoint();
  G4double kin = preStepPoint->GetKineticEnergy();
  numan->AddupKin(kin);

  // ========== Position Collection
  const G4VTouchable* touchable = preStepPoint->GetTouchable();
  G4VPhysicalVolume* HitPV = touchable->GetVolume();
  G4ThreeVector posDetector = HitPV->GetTranslation();

  // ========== Into the ROOT
  G4AnalysisManager* man = G4AnalysisManager::Instance();
  G4double sensorUnit = numan->GetSensorUnit();
  man->FillNtupleDColumn(0, posDetector[0] / sensorUnit);
  man->FillNtupleDColumn(1, posDetector[1] / sensorUnit);
  man->FillNtupleDColumn(2, posDetector[2] / sensorUnit);
  man->FillNtupleDColumn(3, kin / eV);
  man->AddNtupleRow(0);

  numan->AddupSDHitCount();

  // Prevent detecting the same particle for multiple times
  track->SetTrackStatus(fStopAndKill);

  return true;
}