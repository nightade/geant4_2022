#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"

ActionInitialization::ActionInitialization(): G4VUserActionInitialization(){}

ActionInitialization::~ActionInitialization() {}

void ActionInitialization::Build() const {
  SetUserAction(new PrimaryGeneratorAction());

  G4cout << G4endl << G4endl << G4endl << G4endl << "uwu...<3" << G4endl;

  // RunAction* runAction = new RunAction();
  // SetUserAction(runAction);
  SetUserAction(new RunAction);
}
