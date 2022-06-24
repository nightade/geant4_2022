#include "G4VUserPrimaryGeneratorAction.hh"

#include "G4ParticleGun.hh"
#include "globals.hh"

class G4ParticleGun;
class G4Event;
class G4Box;

class MyPrimaryGeneratorAction: public G4VUserPrimaryGeneratorAction {
public:
  MyPrimaryGeneratorAction();
  virtual ~MyPrimaryGeneratorAction() override;

  virtual void GeneratePrimaries(G4Event*) override;
  const G4ParticleGun* GetParticleGun() const { return fParticleGun; }

private:
  G4ParticleGun* fParticleGun = nullptr;
  G4Box* fEnvelopeBox = nullptr;
};
