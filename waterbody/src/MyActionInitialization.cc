#include "MyActionInitialization.hh"
#include "MyPrimaryGeneratorAction.hh"

MyActionInitialization::MyActionInitialization(): G4VUserActionInitialization(){}

MyActionInitialization::~MyActionInitialization() {}

void MyActionInitialization::Build() const {
  SetUserAction(new MyPrimaryGeneratorAction());

  G4cout << G4endl << G4endl << G4endl << G4endl << "uwu...<3" << G4endl;

  // MyRunAction* runAction = new MyRunAction();
  // SetUserAction(runAction);
  SetUserAction(new MyRunAction);
}
