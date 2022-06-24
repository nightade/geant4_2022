#include "PhysicsList.hh"

#include "G4DecayPhysics.hh"
#include "G4SystemOfUnits.hh"

#include "G4EmStandardPhysics.hh"
#include "G4EmStandardPhysics_option3.hh"
#include "MyEmLivermorePhysics.hh"
#include "G4EmPenelopePhysics.hh"


PhysicsList::PhysicsList(): G4VModularPhysicsList()
{ 
  // fEm = new G4EmStandardPhysics();
  // fEm = new G4EmStandardPhysics_option3();
  fEm = new G4EmLivermorePhysics();
  // fEm = new G4EmPenelopePhysics();
  RegisterPhysics(fEm);
  // RegisterPhysics(new G4EmPenelopePhysics());
  // RegisterPhysics(new G4DecayPhysics());

  G4ProductionCutsTable::GetProductionCutsTable()->SetEnergyRange(0.8*eV, 1*GeV);
  SetDefaultCutValue(2*um);
}

PhysicsList::~PhysicsList() {}

// void PhysicsList::ConstructParticle() { fEm->ConstructParticle(); }
// void PhysicsList::ConstructProcess() { fEm->ConstructProcess(); }

void PhysicsList::SetCuts()
{
  SetCutsWithDefault();
}
