#include "F02ElectricFieldSetup.hh"

#include "G4UniformElectricField.hh"
#include "G4UniformMagField.hh"
#include "G4MagneticField.hh"
#include "G4FieldManager.hh"
#include "G4TransportationManager.hh"
#include "G4EquationOfMotion.hh"
#include "G4EqMagElectricField.hh"
#include "G4Mag_UsualEqRhs.hh"
#include "G4MagIntegratorStepper.hh"
#include "G4MagIntegratorDriver.hh"
#include "G4ChordFinder.hh"

#include "G4ExplicitEuler.hh"
#include "G4ImplicitEuler.hh"
#include "G4SimpleRunge.hh"
#include "G4SimpleHeum.hh"
#include "G4ClassicalRK4.hh"
#include "G4HelixExplicitEuler.hh"
#include "G4HelixImplicitEuler.hh"
#include "G4HelixSimpleRunge.hh"
#include "G4CashKarpRKF45.hh"
#include "G4RKG3_Stepper.hh"

#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"

//  Constructors:

F02ElectricFieldSetup::F02ElectricFieldSetup()
 : fMinStep(0.010*mm),  // minimal step of 10 microns
   fFieldManager(0),
   fChordFinder(0),
   fEquation(0),
   fEMfield(0),
   fElFieldValue(),
   fStepper(0),
   fIntgrDriver(0),
   fStepperType(4)    // ClassicalRK4 -- the default stepper
{
  fEMfield = new G4UniformElectricField(
                   G4ThreeVector(0., 0., 100000.0*kilovolt/cm));
  fEquation = new G4EqMagElectricField(fEMfield);

  fFieldManager = GetGlobalFieldManager();

  UpdateIntegrator();
}

F02ElectricFieldSetup::F02ElectricFieldSetup(G4ThreeVector fieldVector)
  : fMinStep(0.010*mm),  // minimal step of 10 microns
    fFieldManager(0),
    fChordFinder(0),
    fEquation(0),
    fEMfield(0),
    fElFieldValue(),
    fStepper(0),
    fIntgrDriver(0),
    fStepperType(4)    // ClassicalRK4 -- the default stepper
{
  fEMfield = new G4UniformElectricField(fieldVector);
  fEquation = new G4EqMagElectricField(fEMfield);

  fFieldManager = GetGlobalFieldManager();
  UpdateIntegrator();  
}

F02ElectricFieldSetup::~F02ElectricFieldSetup()
{
  // G4cout << " F02ElectricFieldSetup - dtor called. " << G4endl;
  
  delete fChordFinder;  fChordFinder= nullptr;
  delete fStepper;      fStepper = nullptr;
  delete fEquation;     fEquation = nullptr;
  delete fEMfield;      fEMfield = nullptr;
}

void F02ElectricFieldSetup::UpdateIntegrator()
{
  // Register this field to 'global' Field Manager and
  // Create Stepper and Chord Finder with predefined type, minstep (resp.)

  // It must be possible to call 'again' after an alternative stepper
  //   has been chosen, or other changes have been made
  assert(fEquation!=nullptr);

  G4cout<< " F02ElectricFieldSetup: The minimal step is equal to "
        << fMinStep/mm << " mm" << G4endl;

  if (fChordFinder) {
     delete fChordFinder;
     fChordFinder= nullptr;
     // The chord-finder's destructor deletes the driver
     fIntgrDriver= nullptr;
  }
  
  // Currently driver does not 'own' stepper      ( 17.05.2017 J.A. )
  //   -- so this stepper is still a valid object after this

  if( fStepper ) {
     delete fStepper;
     fStepper = nullptr;
  }
  
  // Create the new objects, in turn for all relevant classes
  //  -- Careful to call this after all old objects are destroyed, and
  //      pointers nullified.
  CreateStepper();  // Note that this method deleted the existing Stepper!
  // G4cout << "F02ElectricFieldSetup::UpdateIntegrator> "
  //        << "New value of stepper ptr= " << fStepper << G4endl;
  assert(fStepper != nullptr);

  if( fStepper ) {
     fIntgrDriver = new G4MagInt_Driver(fMinStep,
                                        fStepper,
                                        fStepper->GetNumberOfVariables());
     if( fIntgrDriver ){ 
        fChordFinder = new G4ChordFinder(fIntgrDriver);
     }
  }

  fFieldManager->SetChordFinder(fChordFinder);
  fFieldManager->SetDetectorField(fEMfield);
}

void F02ElectricFieldSetup::CreateStepper()
{
  // Deletes the existing stepper
  //   and creates a new stepper object of the chosen stepper type

  const G4int nvar = 8;

  auto oldStepper= fStepper;

  switch ( fStepperType )
  {
    case 0:
      fStepper = new G4ExplicitEuler( fEquation, nvar );
      G4cout<<"G4ExplicitEuler is calledS"<<G4endl;
      break;
    case 1:
      fStepper = new G4ImplicitEuler( fEquation, nvar );
      G4cout<<"G4ImplicitEuler is called"<<G4endl;
      break;
    case 2:
      fStepper = new G4SimpleRunge( fEquation, nvar );
      G4cout<<"G4SimpleRunge is called"<<G4endl;
      break;
    case 3:
      fStepper = new G4SimpleHeum( fEquation, nvar );
      G4cout<<"G4SimpleHeum is called"<<G4endl;
      break;
    case 4:
      fStepper = new G4ClassicalRK4( fEquation, nvar );
      G4cout<<"G4ClassicalRK4 is called"<<G4endl;
      break;
    case 5:
      fStepper = new G4CashKarpRKF45( fEquation, nvar );
      G4cout<<"G4CashKarpRKF45 is called"<<G4endl;
      break;
    case 6:
      fStepper = 0; // new G4RKG3_Stepper( fEquation, nvar );
      G4cout<<"G4RKG3_Stepper is not currently working for Electric Field"
            <<G4endl;
      break;
    case 7:
      fStepper = 0; // new G4HelixExplicitEuler( fEquation );
      G4cout<<"G4HelixExplicitEuler is not valid for Electric Field"<<G4endl;
      break;
    case 8:
      fStepper = 0; // new G4HelixImplicitEuler( fEquation );
      G4cout<<"G4HelixImplicitEuler is not valid for Electric Field"<<G4endl;
      break;
    case 9:
      fStepper = 0; // new G4HelixSimpleRunge( fEquation );
      G4cout<<"G4HelixSimpleRunge is not valid for Electric Field"<<G4endl;
      break;
    default:  /* fStepper = 0; // Older code */
      fStepper = new G4ClassicalRK4( fEquation, nvar );
      G4cout<<"G4ClassicalRK4 (default) is called"<<G4endl;
      break;
  }

  delete oldStepper;
  // Now must make sure it is 'stripped' from the dependent object(s)
  //  ... but the next line does this anyway - by informing
  //      the driver (if it exists) about the new stepper.

  // Always inform the (existing) driver about the new stepper
  if( fIntgrDriver )
      fIntgrDriver->RenewStepperAndAdjust( fStepper );
}

G4FieldManager*  F02ElectricFieldSetup::GetGlobalFieldManager()
{
  return G4TransportationManager::GetTransportationManager()
           ->GetFieldManager();
}