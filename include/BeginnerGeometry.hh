#ifndef GEOMETRY
#define GEOMETRY 1

#include "G4VUserDetectorConstruction.hh"

class BeginnerDetectorConstruction : public G4VUserDetectorConstruction {
public:
	virtual G4VPhysicalVolume* Construct();
};

#endif // !GEOMETRY
