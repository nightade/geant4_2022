#include "PrimaryGeneratorAction.hh"
#include "NumberManager.hh"

#include "G4LogicalVolumeStore.hh" 
#include "G4LogicalVolume.hh"

#include "G4Box.hh"
#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction(): G4VUserPrimaryGeneratorAction() {
  // G4int_n_particle = 1; Examples init. this to pass below
  fParticleGun = new G4ParticleGun(1);
  
  G4ParticleDefinition* particle
    = G4ParticleTable::GetParticleTable()->FindParticle("e-");
  fParticleGun->SetParticleDefinition(particle);
  
  G4double px = 0.35 * G4UniformRand();
  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(px, 0.,-1.));
  fParticleGun->SetParticleEnergy(15.7*eV);
}

// This function is called at the beginning of each event!
PrimaryGeneratorAction::~PrimaryGeneratorAction(){ delete fParticleGun; }

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent){
  // G4LogicalVolume* LV = G4LogicalVolumeStore::GetInstance()->GetVolume("ShieldLV");
  // G4Box* Box = dynamic_cast<G4Box*>(LV->GetSolid());
  // G4double Z0 = Box->GetZHalfLength();

  G4ThreeVector port = NumberManager::Instance()->GetBeamPort();
  // G4double r0 = port[0] * std::sqrt(G4UniformRand())/2; // port[0] = Diameter
  // G4double t0 = (360*deg) * (G4UniformRand()-0.5);
  // G4double x0 = r0 * std::cos(t0);
  // G4double y0 = r0 * std::sin(t0);
  G4double x0 = port[0] * (G4UniformRand()-0.5);
  G4double y0 = port[1] * (G4UniformRand()-0.5);
  G4double z0 = port[2];

  fParticleGun->SetParticlePosition(G4ThreeVector(x0,y0,z0));
  fParticleGun->GeneratePrimaryVertex(anEvent);
}