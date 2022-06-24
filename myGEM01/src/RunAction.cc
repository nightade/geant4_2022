#include "RunAction.hh"
#include "SensitiveDetector.hh"

// #include "G4LogicalVolumeStore.hh" 
// #include "G4LogicalVolume.hh"


RunAction::RunAction() {
  G4AnalysisManager* man = G4AnalysisManager::Instance();

  G4String name = G4String("Hits");
  man->CreateNtuple(name, name);
  man->CreateNtupleDColumn("fX");
  man->CreateNtupleDColumn("fY");
  man->CreateNtupleDColumn("fZ");
  man->CreateNtupleDColumn("edep");
  man->FinishNtuple(0);
}
RunAction::~RunAction() { delete G4AnalysisManager::Instance(); }

void RunAction::BeginOfRunAction(const G4Run*)
{
  G4AnalysisManager* man = G4AnalysisManager::Instance();
  NumberManager* numan = NumberManager::Instance();

  numan->AddupRunCount();
  // name = name.append(std::to_string(numan->GetRunCount()));
  man->OpenFile("output.root");

}

void RunAction::EndOfRunAction(const G4Run*)
{
  G4AnalysisManager* man = G4AnalysisManager::Instance();
  NumberManager* numan = NumberManager::Instance();

  man->Write();
  man->CloseFile();

  G4cout << ">> Your SD has detected " << numan->GetSDHitCount() << " Hits." << G4endl;
  numan->SetSDHitCount0();
}