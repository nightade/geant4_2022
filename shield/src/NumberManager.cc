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

G4ThreeVector NumberManager::GetBeamPort() { return fBeamPort; }
G4double NumberManager::GetSensorUnit() { return fSensorUnit; }
G4int NumberManager::GetSDHitCount() { return fSDHitCount; }
G4int NumberManager::GetRunCount() { return fRunCount; }

void NumberManager::SetBeamPort(G4ThreeVector vec) { fBeamPort = vec; }
void NumberManager::SetSensorUnit(G4double unit) { fSensorUnit = unit; }
void NumberManager::AddupSDHitCount() { fSDHitCount = fSDHitCount + 1; }
void NumberManager::AddupRunCount() { fRunCount = fRunCount + 1; }
void NumberManager::SetSDHitCount0() { fSDHitCount = 0; }