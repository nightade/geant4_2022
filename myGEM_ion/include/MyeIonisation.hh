//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************

#include "G4VEnergyLossProcess.hh"
#include "G4Electron.hh"
#include "G4Positron.hh"
#include "G4VEmModel.hh"

class G4Material;
class G4ParticleDefinition;

class G4eIonisation : public G4VEnergyLossProcess
{

public:

  explicit G4eIonisation(const G4String& name = "eIoni");

  ~G4eIonisation() override;

  G4bool IsApplicable(const G4ParticleDefinition& p) final;

  // print documentation in html format
  void ProcessDescription(std::ostream&) const override;

  // hide assignment operator
  G4eIonisation & operator=(const G4eIonisation &right) = delete;
  G4eIonisation(const G4eIonisation&) = delete;

protected:

  void InitialiseEnergyLossProcess(const G4ParticleDefinition*,
  			           const G4ParticleDefinition*) override;

  G4double MinPrimaryEnergy(const G4ParticleDefinition*,
			    const G4Material*, G4double cut) final;

private:

  const G4ParticleDefinition* theElectron;

  G4bool isElectron;
  G4bool isInitialised;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......