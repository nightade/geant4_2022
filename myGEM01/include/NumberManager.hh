#include "globals.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"

class NumberManager
{
public:
  static NumberManager* Instance();
  ~NumberManager();

  G4ThreeVector GetBeamPort();
  G4double GetSensorUnit();
  G4int GetSDHitCount();
  G4int GetRunCount();

  void SetBeamPort(G4ThreeVector);
  void SetSensorUnit(G4double);
  void AddupSDHitCount();
  void AddupRunCount();
  void SetSDHitCount0();

private:
  NumberManager();
  static NumberManager* instance;
  
  G4ThreeVector fBeamPort;
  G4double fSensorUnit;

  G4int fSDHitCount = 0;
  G4int fRunCount = 0;
};