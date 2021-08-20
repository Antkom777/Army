#pragma once
#include <vector>
#include "Location.h"

class Battlefield
{
public:
	static Battlefield& getInstance() {
		static Battlefield instance;
		return instance;
	}
	Location* Battlefield::getValidLocation(const Point& point);
	void printBattlefield();

private:
	Battlefield();
	Battlefield(const Battlefield&);
	Battlefield& operator= (Battlefield&);
	Location* getFreeLocation();
	Location* getPointLocation(const Point& point);

	std::vector<Location*>* square;
	void InitSquare();
};
