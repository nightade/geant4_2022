#include "G4ElectricField.hh"
#include "G4UniformElectricField.hh"

class G4FieldManager;
class G4ChordFinder;
class G4EquationOfMotion;
class G4Mag_EqRhs;
class G4EqMagElectricField;
class G4MagIntegratorStepper;
class G4MagInt_Driver;

class F02ElectricFieldSetup
{
public:
  F02ElectricFieldSetup(G4ThreeVector);  //  The value of the field
  F02ElectricFieldSetup();               //  A zero field - true value set later

  virtual ~F02ElectricFieldSetup();

   // Methods to set parameters or select 
  void SetStepperType( G4int i) { fStepperType = i ; CreateStepper(); }
  void SetMinStep(G4double minStep) { fMinStep = minStep ; }

  G4ThreeVector GetConstantFieldValue();

  void UpdateIntegrator();
   // Prepare all the classes required for tracking - from stepper 
   //    to Chord-Finder
   //   NOTE:  field and equation must have been created before calling this.
   
protected:
  G4FieldManager*         GetGlobalFieldManager();

  void CreateStepper();
   // Implementation method - should not be exposed

private:
  G4double                fMinStep;
  G4bool                  fVerbose;

  G4FieldManager*         fFieldManager;

  G4ChordFinder*          fChordFinder;

  G4EqMagElectricField*   fEquation;

  G4ElectricField*        fEMfield;
 
  G4ThreeVector           fElFieldValue;

  G4MagIntegratorStepper* fStepper;
  G4MagInt_Driver*        fIntgrDriver;

  G4int                   fStepperType;
};