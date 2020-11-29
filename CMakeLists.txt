cmake_minimum_required(VERSION 2.6)
project(G4Beginner)

find_package(Geant4 REQUIRED ui_all vis_all)

include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB header ${PROJECT_SOURCE_DIR}/include/*.hh)

add_executable(G4Beginner G4Beginner.cc ${sources} ${header})
target_link_libraries(G4Beginner ${Geant4_LIBRARIES})

set(G4Beginner_SCRIPTS
	auto.mac
	vis.mac
)

foreach(_script ${G4Beginner_SCRIPTS})
	configure_file(
		${PROJECT_SOURCE_DIR}/${_script}
		${PROJECT_BINARY_DIR}/${_script}
		COPYONLY
	)
endforeach()
