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
	"Unit.cpp"
	"Axe.cpp"
	"Bow.cpp"
	"Claws.cpp"
	"Dagger.cpp"
	"Fangs.cpp"
	"Staff.h"
	"Sword.h"
)

set (HEADERS
	"Army.h"
	"Point.h"
	"Mount.h"
	"Location.h"
	"Weapon.h"
	"Exceptions.h"
	"State.h"
	"Unit.h"
	"Axe.h"
	"Bow.h"
	"Claws.h"
	"Dagger.h"
	"Fangs.h"
	"Staff.h"
	"Sword.h"
)
# Add source to this project's executable.
add_executable (Army ${SOURCES} ${HEADERS})
