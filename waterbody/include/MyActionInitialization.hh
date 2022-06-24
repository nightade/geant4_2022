#include "G4VUserActionInitialization.hh"
#include "MyRunAction.hh"

class MyActionInitialization: public G4VUserActionInitialization
{
public:
  MyActionInitialization();
  virtual ~MyActionInitialization() override;
  
  virtual void Build() const override;
};
