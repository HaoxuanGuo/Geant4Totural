#include "QGSP_BERT_HP.hh"
#include "G4MTRunManager.hh"
#include "BeginnerGeometry.hh"
#include "ParticleSource.hh"
#include "G4VUserActionInitialization.hh"
#include "G4UImanager.hh"

class BeginnerActionInitialization : public G4VUserActionInitialization {
public:
    virtual void Build() const{
        SetUserAction(new BeginnerGeneratorAction);
    }
};

int main(void){
    auto runManager = new G4MTRunManager;

    runManager->SetUserInitialization(new BeginnerDetectorConstruction());
    runManager->SetUserInitialization(new QGSP_BERT_HP());
    runManager->SetUserInitialization(new BeginnerActionInitialization());

    auto UImanager = G4UImanager::GetUIpointer();
    UImanager->ApplyCommand("/run/initialize");
    UImanager->ApplyCommand("/run/beamOn 100");

    delete runManager;
    return 0;
}