#ifndef SOURCE
#define SOURCE 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"

class G4Event;
class G4ParticleGun;

class BeginnerGeneratorAction : public G4VUserPrimaryGeneratorAction {
public:
	BeginnerGeneratorAction();
	~BeginnerGeneratorAction();
	virtual void GeneratePrimaries(G4Event*);
private:
	G4ParticleGun* particleGun;
};

#endif // !SOURCE
