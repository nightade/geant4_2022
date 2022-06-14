#include "NumberManager.hh"

NumberManager* NumberManager::instance = 0;
NumberManager* NumberManager::Instance()
{
    if(!instance)
    {
        static NumberManager numan;
        instance = &numan;
    }
    return instance;
}
NumberManager::NumberManager() {}
NumberManager::~NumberManager() {}

// ========== GETTERS ========== //
G4ThreeVector NumberManager::GetBeamPort() { return fBeamPort; }
G4double NumberManager::GetSensorUnit() { return fSensorUnit; }
G4int NumberManager::GetSDHitCount() { return fSDHitCount; }
G4int NumberManager::GetRunCount() { return fRunCount; }

G4double NumberManager::GetEdep() { return fEdep; }
G4double NumberManager::GetKinStat() { return fKin/fSDHitCount; }

// ========== SET & ADDUP ========== //
void NumberManager::SetBeamPort(G4ThreeVector vec) { fBeamPort = vec; }
void NumberManager::SetSensorUnit(G4double unit) { fSensorUnit = unit; }
void NumberManager::AddupSDHitCount() { fSDHitCount = fSDHitCount + 1; }
void NumberManager::AddupRunCount() { fRunCount = fRunCount + 1; }
void NumberManager::SetValuesZero()
{ fSDHitCount = 0; fEdep = 0; fKin = 0; }

void NumberManager::AddupEdep(G4double edep) { fEdep = fEdep + edep; }
void NumberManager::AddupKin(G4double kin)
{
  fKin = fKin + kin;
}