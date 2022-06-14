#include "PhysicsList.hh"

#include "G4EmStandardPhysics.hh"
#include "G4DecayPhysics.hh"
#include "MyEmPenelopePhysics.hh"
#include "G4SystemOfUnits.hh"

PhysicsList::PhysicsList(): G4VModularPhysicsList()
{
  defaultCutValue = 2.*um;
  
  //RegisterPhysics(new G4EmStandardPhysics());
  RegisterPhysics(new G4EmPenelopePhysics());
  RegisterPhysics(new G4DecayPhysics());
  // fEmPenelope = new G4EmPenelopePhysics;
}

PhysicsList::~PhysicsList()
{
  // delete fEmPenelope;
}

// void PhysicsList::ConstructParticle() { fEmPenelope->ConstructParticle(); }

// void PhysicsList::ConstructProcess() { fEmPenelope->ConstructProcess(); }

void PhysicsList::SetCuts()
{
  SetCutsWithDefault();
}
