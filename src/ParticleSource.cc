#include "ParticleSource.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"

BeginnerGeneratorAction::BeginnerGeneratorAction() {
	particleGun = new G4ParticleGun(1);
	auto table = G4ParticleTable::GetParticleTable();
	particleGun->SetParticleDefinition(table->FindParticle("e-"));
	particleGun->SetParticleMomentumDirection(G4ThreeVector(0, 0, 1));
	particleGun->SetParticleEnergy(10 * MeV);
}

BeginnerGeneratorAction::~BeginnerGeneratorAction() {
	delete particleGun;
}

void BeginnerGeneratorAction::GeneratePrimaries(G4Event* e) {
	particleGun->GeneratePrimaryVertex(e);
}