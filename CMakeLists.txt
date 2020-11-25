cmake_minimum_required(VERSION 2.6)
project(G4Beginner)

find_package(Geant4 REQUIRED)

include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB header ${PROJECT_SOURCE_DIR}/include/*.hh)

add_executable(G4Beginner G4Beginner.cc ${sources} ${header})
target_link_libraries(G4Beginner ${Geant4_LIBRARIES})
