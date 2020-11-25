#include "BeginnerGeometry.hh"
#include "G4Box.hh"
#include "G4SystemOfUnits.hh"
#include "G4LogicalVolume.hh"
#include "G4NistManager.hh"
#include "G4PVPlacement.hh"

G4VPhysicalVolume* BeginnerDetectorConstruction::Construct() {
	auto nist = G4NistManager::Instance();
	// Solid
	auto solid_world = new G4Box("world", 0.5 * m, 0.5 * m, 0.5 * m);
	// Logic
	auto logic_world = new G4LogicalVolume(solid_world, nist->FindOrBuildMaterial("G4_AIR"), "world");
	// Physics
	auto physical_world = new G4PVPlacement(
		0,
		G4ThreeVector(0, 0, 0),
		logic_world,
		"world",
		0,
		false,
		0,
		true
	);
	return physical_world;
}
