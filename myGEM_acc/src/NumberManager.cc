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


// ========== SET & ADDUP ========== //
