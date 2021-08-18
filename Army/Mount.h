#ifndef MOUNT_H
#define MOUNT_H
#include <iostream>

class Unit;

class Mount {
public:
	std::string name;
	Unit* owner;
	int speed;

	Mount(Unit* owner, int speed = 3);
	~Mount();

};
#endif
