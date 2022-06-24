#include "globals.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"

class NumberManager
{
public:
  static NumberManager* Instance();
  ~NumberManager();

  // ========== GETTERS ========== //
  inline G4ThreeVector GetBeamPort() { return fBeamPort; }
  inline G4double GetSensorUnit() { return fSensorUnit; }
  inline G4int GetSDHitCount() { return fSDHitCount; }
  inline G4int GetRunCount() { return fRunCount; }

  inline G4double GetEdep() { return fEdep; }
  inline G4double GetKinStat() { return fKin/fSDHitCount; }
  inline G4ThreeVector GetEField() { return fEField; }

  // ========== SET & ADDUP ========== //
  inline void SetBeamPort(G4ThreeVector vec) { fBeamPort = vec; }
  inline void SetSensorUnit(G4double unit) { fSensorUnit = unit; }
  inline void AddupSDHitCount() { fSDHitCount = fSDHitCount + 1; }
  inline void AddupRunCount() { fRunCount = fRunCount + 1; }
  inline void SetValuesZero() { fSDHitCount = 0; fEdep = 0; fKin = 0; fKin2 = 0; }

  inline void AddupEdep(G4double edep) { fEdep = fEdep + edep; }
  inline void AddupKin(G4double kin) { fKin = fKin + kin; }

  inline void SetEField(G4ThreeVector vecE) { fEField = vecE; }

private:
  NumberManager();
  static NumberManager* instance;
  
  G4ThreeVector fBeamPort;
  G4double fSensorUnit;

  G4int fSDHitCount = 0;
  G4int fRunCount = 0;

  G4double fEdep = 0;
  G4double fKin = 0;
  G4double fKin2 = 0;

  G4ThreeVector fEField = G4ThreeVector();
};