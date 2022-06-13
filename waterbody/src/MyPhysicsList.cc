#include "MyPhysicsList.hh"

#include "G4EmStandardPhysics.hh"
#include "G4DecayPhysics.hh"

MyPhysicsList::MyPhysicsList(): G4VModularPhysicsList()
{
  RegisterPhysics(new G4EmStandardPhysics());
  RegisterPhysics(new G4DecayPhysics());
}

MyPhysicsList:: ~MyPhysicsList(){}
