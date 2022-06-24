#include "MyPrimaryGeneratorAction.hh"

// From here it looks up LV if (!EnvelopeBox)
#include "G4LogicalVolumeStore.hh" 
#include "G4LogicalVolume.hh"

#include "G4Box.hh"
#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

MyPrimaryGeneratorAction::MyPrimaryGeneratorAction(): G4VUserPrimaryGeneratorAction() {
  // G4int_n_particle = 1; Examples init. this to pass below
  fParticleGun = new G4ParticleGun(1);
  
  G4ParticleDefinition* particle
    = G4ParticleTable::GetParticleTable()->FindParticle("e-");
  fParticleGun->SetParticleDefinition(particle);
  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));
  fParticleGun->SetParticleEnergy(5.*MeV); // Default Value
}

// This function is called at the beginning of each event!
MyPrimaryGeneratorAction::~MyPrimaryGeneratorAction(){ delete fParticleGun; }

void MyPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent){
  G4double x0 = 1*cm * (G4UniformRand()-0.5);
  G4double y0 = 1*cm * (G4UniformRand()-0.5);
  G4double z0 = -5*m;

  fParticleGun->SetParticlePosition(G4ThreeVector(x0,y0,z0));
  fParticleGun->GeneratePrimaryVertex(anEvent);
}


