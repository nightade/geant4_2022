#include "G4VModularPhysicsList.hh"

class PhysicsList: public G4VModularPhysicsList
{
public:
  PhysicsList();
  virtual ~PhysicsList();

  // void ConstructParticle();
  // void ConstructProcess();
  void SetCuts();

private:
  G4VPhysicsConstructor* fEm = nullptr;
};