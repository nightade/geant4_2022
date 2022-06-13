#include "MyDetectorConstruction.hh"
// #include "MyActionInitialization.hh"
#include "MyPhysicsList.hh"
#include "MyPrimaryGeneratorAction.hh"
#include "MyRunAction.hh"

#include <iostream>
#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"


int main(int argc, char** argv)
{
	G4RunManager *g4man = new G4RunManager();
	G4UIExecutive *ui = new G4UIExecutive(argc, argv);
	
	g4man->SetUserInitialization(new MyDetectorConstruction);
	g4man->SetUserInitialization(new MyPhysicsList);
	g4man->SetUserAction(new MyPrimaryGeneratorAction);
	g4man->SetUserAction(new MyRunAction);

	g4man->Initialize();

	G4VisManager *visManager = new G4VisExecutive();
	visManager->Initialize();
	
	G4UImanager *UImanager = G4UImanager::GetUIpointer();
	UImanager->ApplyCommand("/control/execute init_vis.mac");

	ui->SessionStart();

	delete ui;
	delete visManager;
	delete g4man;

	return 0;
}
