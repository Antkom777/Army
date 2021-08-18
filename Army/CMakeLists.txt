# CMakeList.txt : CMake project for Army, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set (SOURCES 
	"Army.cpp"
	"Point.cpp"
	"Mount.cpp"
	"Location.cpp"
	"Weapon.cpp"
	"State.cpp"
	"Unit.h"
)

set (HEADERS
	"Army.h"
	"Point.h"
	"Mount.h"
	"Location.h"
	"Weapon.h"
	"Exceptions.h"
	"State.h"
	"Unit.cpp"
)
# Add source to this project's executable.
add_executable (Army ${SOURCES} ${HEADERS})

# TODO: Add tests and install targets if needed.
