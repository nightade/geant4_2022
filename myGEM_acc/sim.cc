#include "DetectorConstruction.hh"
#include "PhysicsList.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "SteppingAction.hh"
#include "NumberManager.hh"
#include "QGSP_BERT.hh"

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
    // g4man->SetUserInitialization(new ActionInitialization());

	// G4VModularPhysicsList* physicslist = new QGSP_BERT;
	G4VModularPhysicsList* physicslist = new PhysicsList;
	g4man->SetUserInitialization(physicslist);

	g4man->SetUserAction(new PrimaryGeneratorAction);
	g4man->SetUserAction(new RunAction);
	g4man->SetUserAction(new SteppingAction);
	
	g4man->Initialize();

	G4VisManager *visManager = new G4VisExecutive();
	visManager->Initialize();
	
	G4UImanager *UImanager = G4UImanager::GetUIpointer();
	if (!ui)
	{
      // batch mode
	  G4String command = "/control/execute ";
	  G4String fileName = argv[1];
	  UImanager->ApplyCommand(command+fileName);
    }
    else
	{
      // interactive mode
      UImanager->ApplyCommand("/control/execute init_vis.mac");
      ui->SessionStart();
      delete ui;
    }

	ui->SessionStart();

	delete ui;
	delete visManager;
	delete g4man;
	delete numan;

	return 0;
}
