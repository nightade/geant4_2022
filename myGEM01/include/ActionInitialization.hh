#include "G4VUserActionInitialization.hh"
#include "RunAction.hh"

class ActionInitialization: public G4VUserActionInitialization
{
public:
  ActionInitialization();
  virtual ~ActionInitialization() override;
  
  virtual void Build() const override;
};