#include "PhysListMessenger.hh"
#include "PhysicsList.hh"

#include "G4UIdirectory.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWith3VectorAndUnit.hh"
#include "G4UIcmdWithoutParameter.hh"

PhysListMessenger::PhysListMessenger(PhysicsList* pList)
 : fPList(pList)
{
  fDirectory = new G4UIdirectory("/physics/");
  fDirectory->SetGuidance("Control the list of associated physics processes");

  fCmdViewPList = new G4UIcmdWithoutParameter("/physics/viewlist",this);
  fCmdViewPList->SetGuidance("View an entire list of registered processes");
  fCmdViewPList->AvailableForStates(G4State_PreInit,G4State_Idle);

  fCmdRegister = new G4UIcmdWithAString("/physics/register",this);
  fCmdRegister->SetGuidance("Register a process to the list.");
  fCmdRegister->SetParameterName("Process",false);
  fCmdRegister->AvailableForStates(G4State_PreInit,G4State_Idle);

  fCmdRemove = new G4UIcmdWithAString("/physics/remove",this);
  fCmdRemove->SetGuidance("Remove a process from the list.");
  fCmdRemove->SetParameterName("Process",false);
  fCmdRemove->AvailableForStates(G4State_PreInit,G4State_Idle);
}

PhysListMessenger::~PhysListMessenger()
{
  delete fCmdViewPList;
  delete fCmdRegister;
  delete fCmdRemove;
}

void PhysListMessenger::SetNewValue(G4UIcommand* command,G4String newValue)
{
  G4int id = fPList->GetInstanceID();
  auto physVec = (fPList->GetSubInstanceManager().offset[id]).physicsVector;

  if( command == fCmdViewPList )
  { fPList->ViewList(); }

  if( command == fCmdRegister )
  {
    G4VPhysicsConstructor* process = fPList->GetPhysConst(newValue);
    if(process == nullptr) { G4cout << newValue << " : Process Not found!!!" << G4endl << G4endl; }
    else
    {
      fPList->ViewList();
      G4cout << newValue << " : successfully added!!!" << G4endl << G4endl;
      physVec->push_back(process);
    }
  }

  if( command == fCmdRemove )
  {
    G4bool success = false;
    for (G4int i = 0;; i++)
    {
      G4VPhysicsConstructor* process = const_cast<G4VPhysicsConstructor*> (fPList->GetPhysics(i));

      if (process->GetPhysicsName() == newValue)
      {
        auto target = physVec->begin() + i;
        physVec->erase(target);
        success = true;
        break;
      }
    }
    if(success) { G4cout << newValue << " : successfully removed!!!" << G4endl << G4endl; }
    else { G4cout << newValue << " : not found!!!" << G4endl << G4endl; }
  }
}