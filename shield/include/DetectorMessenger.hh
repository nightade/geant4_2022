#include "globals.hh"
#include "G4UImessenger.hh"

class G4UIdirectory;
class G4UIcmdWithAString;
class G4UIcmdWith3VectorAndUnit;
class G4UIcmdWithoutParameter;
class DetectorConstruction;

// /det/setChamberMaterial <name>
// /det/setChamberSize <vector> <unit>
// /det/setChamberPos <vector> <unit>
// /det/setTargetMaterial <name>
// /det/setTargetSize <vector> <unit>
// /det/setTargetPos <vector> <unit>
// /det/viewMaterialList

class DetectorMessenger: public G4UImessenger
{
public:
  DetectorMessenger(DetectorConstruction* );
  ~DetectorMessenger() override;

  void SetNewValue(G4UIcommand*, G4String) override;

private:
  DetectorConstruction*  fDetectorConstruction = nullptr;
  G4UIdirectory*         fDirectory = nullptr;

  G4UIcmdWithAString*    fCmdChamberMaterial = nullptr;
  G4UIcmdWithAString*    fCmdTargetMaterial = nullptr;

  G4UIcmdWith3VectorAndUnit* fCmdChamberSize = nullptr;
  G4UIcmdWith3VectorAndUnit* fCmdTargetSize = nullptr;

  G4UIcmdWith3VectorAndUnit* fCmdChamberPos = nullptr;
  G4UIcmdWith3VectorAndUnit* fCmdTargetPos = nullptr;

  G4UIcmdWithoutParameter* fCmdviewMatList = nullptr;
};