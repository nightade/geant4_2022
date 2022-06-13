#include "PhysicsList.hh"
#include "PhysListMessenger.hh"

// QGSP_BERT
#include "G4EmStandardPhysics.hh"   // G4EmStandard
#include "G4EmExtraPhysics.hh"      // G4GammaLeptoNuclearPhys
#include "G4DecayPhysics.hh"        // Decay
#include "G4HadronElasticPhysics.hh" // hElasticWEL_CHIPS_XS
#include "G4HadronPhysicsQGSP_BERT.hh" // hInelastic QGSP_BERT
#include "G4StoppingPhysics.hh"     // stoppint
#include "G4IonPhysics.hh"          // ionInelasticFTFP_BIC

#include "G4HadronPhysicsFTFP_BERT.hh"
#include "G4HadronPhysicsFTFP_BERT_HP.hh"

PhysicsList::PhysicsList(): G4VModularPhysicsList()
{
  fPhysListMessenger = new PhysListMessenger(this);

  // ===== Available Physics Process ======
  fPhysMenu.push_back(new G4EmStandardPhysics);
  fPhysMenu.push_back(new G4EmExtraPhysics);
  fPhysMenu.push_back(new G4DecayPhysics);
  fPhysMenu.push_back(new G4HadronElasticPhysics);
  fPhysMenu.push_back(new G4HadronPhysicsQGSP_BERT);
  fPhysMenu.push_back(new G4StoppingPhysics);
  fPhysMenu.push_back(new G4IonPhysics);
  fPhysMenu.push_back(new G4HadronPhysicsFTFP_BERT);
  
  vector<G4int> defaultMenu;
  defaultMenu.push_back(0);
  defaultMenu.push_back(2);

  for (const auto &index : defaultMenu)
  {
    RegisterPhysics(fPhysMenu[index]);
  }
  ViewList();
}

PhysicsList::~PhysicsList()
{
  delete fPhysListMessenger;
  for (const auto &item : fPhysMenu) { delete item; }
}

void PhysicsList::ViewList()
{
  G4cout << ">> [PhysicsList] Physics Processes:" << G4endl;
  for (const auto &item : fPhysMenu)
  {
    G4String name = item->GetPhysicsName();
    G4cout << name;
    for (G4int i = 0;; i++)
    {
      G4VPhysicsConstructor* process = const_cast<G4VPhysicsConstructor*> (GetPhysics(i));
      if (process == nullptr) break;
      if (process->GetPhysicsName() == name) { G4cout << "... Registered!"; }
    }
    G4cout << G4endl;
  }
  G4cout << G4endl;
}

G4VPhysicsConstructor* PhysicsList::GetPhysConst(G4String sProcess)
{
  G4VPhysicsConstructor* PhysConst = nullptr;
  for (const auto &item : fPhysMenu)
  {
    if(item->GetPhysicsName() == sProcess) { PhysConst = item; }
  }
  return PhysConst;
}