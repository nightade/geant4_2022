#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "NumberManager.hh"
#include "QGSP_BERT.hh"
// #include "PhysicsList.hh"

#include <iostream>
#include "G4RunManager.hh"

#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"


int main(int argc, char** argv)
{
	G4RunManager* g4man = new G4RunManager();
	G4UIExecutive* ui = new G4UIExecutive(argc, argv);
	NumberManager* numan = NumberManager::Instance();
	
	g4man->SetUserInitialization(new DetectorConstruction);
	g4man->SetUserInitialization(new QGSP_BERT);
	// g4man->SetUserInitialization(new PhysicsList);
	g4man->SetUserAction(new PrimaryGeneratorAction);
	g4man->SetUserAction(new RunAction);

	g4man->Initialize();

	G4VisManager *visManager = new G4VisExecutive();
	visManager->Initialize();
	
	G4UImanager *UImanager = G4UImanager::GetUIpointer();
	UImanager->ApplyCommand("/control/execute init_vis.mac");

	ui->SessionStart();

	delete ui;
	delete visManager;
	delete g4man;
	delete numan;

	return 0;
}
