#include "G4VModularPhysicsList.hh"

#include <vector>
#include <algorithm>

using std::vector;
using std::find;

class PhysListMessenger;

class PhysicsList: public G4VModularPhysicsList
{
public:
  PhysicsList();
  virtual ~PhysicsList();

  void ViewList();
  G4VPhysicsConstructor* GetPhysConst(G4String);

private:
  vector<G4VPhysicsConstructor*> fPhysMenu;
  PhysListMessenger* fPhysListMessenger = nullptr;
};