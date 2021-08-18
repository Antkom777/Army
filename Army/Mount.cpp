#include "Mount.h"
#define DEBUG 0


Mount::Mount(Unit* owner, int speed)
	:owner(owner), speed(speed) {
		this->name = "Horse";
	} 
Mount::~Mount() {}

