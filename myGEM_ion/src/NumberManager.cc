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
G4double NumberManager::GetKinStat(G4bool stdv=false)
{
    if(!stdv) { return fKin/fSDHitCount; }
    else { return std::sqrt(fKin2/fSDHitCount); }
    }

// ========== SET & ADDUP ========== //
void NumberManager::SetBeamPort(G4ThreeVector vec) { fBeamPort = vec; }
void NumberManager::SetSensorUnit(G4double unit) { fSensorUnit = unit; }
void NumberManager::AddupSDHitCount() { fSDHitCount = fSDHitCount + 1; }
void NumberManager::AddupRunCount() { fRunCount = fRunCount + 1; }
void NumberManager::SetValuesZero()
{ fSDHitCount = 0; fEdep = 0; fKin = 0; fKin2 = 0; }

void NumberManager::AddupEdep(G4double edep) { fEdep = fEdep + edep; }
void NumberManager::AddupKin(G4double kin)
{ fKin = fKin + kin; fKin2 = fKin2 + kin*kin; }