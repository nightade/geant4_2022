#include "PhysicsList.hh"

#include "G4EmStandardPhysics.hh"
#include "G4DecayPhysics.hh"
#include "MyEmPenelopePhysics.hh"

PhysicsList::PhysicsList(): G4VModularPhysicsList()
{
  // RegisterPhysics(new G4EmStandardPhysics());
  RegisterPhysics(new G4EmPenelopePhysics());
  // RegisterPhysics(new G4DecayPhysics());
}

PhysicsList:: ~PhysicsList(){}