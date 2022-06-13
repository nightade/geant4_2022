#include "globals.hh"
#include "G4UImessenger.hh"

class G4UIdirectory;
class G4UIcmdWithAString;
class G4UIcmdWith3VectorAndUnit;
class G4UIcmdWithoutParameter;
class PhysicsList;

// /physics/viewlist
// /physics/register <str_name>
// /physics/remove <str_name>

class PhysListMessenger: public G4UImessenger
{
public:
  PhysListMessenger(PhysicsList* );
  ~PhysListMessenger() override;

  void SetNewValue(G4UIcommand*, G4String) override;

private:
  PhysicsList*  fPList = nullptr;
  G4UIdirectory*         fDirectory = nullptr;

  G4UIcmdWithoutParameter* fCmdViewPList = nullptr;

  G4UIcmdWithAString*    fCmdRegister = nullptr;
  G4UIcmdWithAString*    fCmdRemove = nullptr;
};