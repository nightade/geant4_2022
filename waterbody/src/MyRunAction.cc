#include "MyRunAction.hh"

MyRunAction::MyRunAction() {}
MyRunAction::~MyRunAction() {}

void MyRunAction::BeginOfRunAction(const G4Run*)
{
  G4cout << G4endl << G4endl << G4endl << G4endl << "uwu...<3" << G4endl;
  G4AnalysisManager* man = G4AnalysisManager::Instance();

  man->OpenFile("output.root");
  man->CreateNtuple("Hits", "Hits");
  man->CreateNtupleDColumn("fX");
  man->CreateNtupleDColumn("fY");
  man->CreateNtupleDColumn("fZ");
  man->CreateNtupleDColumn("edep");
  man->FinishNtuple(0);
}

void MyRunAction::EndOfRunAction(const G4Run*)
{
  G4AnalysisManager* man = G4AnalysisManager::Instance();

  man->Write();
  man->CloseFile();
}