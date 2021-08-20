#include "Battlefield.h"
#include "Exceptions.h"
#define DEBUG 0

std::vector<Location*>* square = nullptr;

Battlefield::Battlefield()
{
	InitSquare();
}

void Battlefield::InitSquare()
{
	std::vector<Location*>* tmp = new std::vector<Location*>(64);
	
	if (DEBUG) std::cout << "initSquare works" << std::endl;
	for (int i = 0; i < 64; i++) {
		int row = i / 8;
		int col = i % 8;
		tmp->at(i) = new Location(Point(row, col));
		if (DEBUG) std::cout << "i=>" << i << " row=>" << row << " col=>"
			<< col << std::endl;
		if (DEBUG) std::cout << tmp->at(i)->getAddress() << std::endl;  
	}
	square = tmp;
}

Location* Battlefield::getFreeLocation() {
	if (DEBUG) std::cout << "getFreeLocation works" << std::endl;
	for (int i = 0; i < square->size(); i++) {
		if (square->at(i)->getToken() == nullptr) {
			return square->at(i);
		}
	}
	throw new NotFreeLocationException();
};

Location* Battlefield::getPointLocation(const Point& point)
{
	if (DEBUG) std::cout << "getPointLocation works" << std::endl;
	for (int i = 0; i < square->size(); i++)
	{
		if (square->at(i)->getAddress() == point)
		{
			if (DEBUG) std::cout << "i => " << i << std::endl;
			return square->at(i);
		}
	}
	throw new NotLocationException();
};

Location* Battlefield::getValidLocation(const Point& point) {
	if (DEBUG) std::cout << "setValidLocation works" << std::endl;
	if (DEBUG) std::cout << "point" << point << std::endl;
	Location* tempLocation = getPointLocation(point);

	if (tempLocation->isFreeAddress())
	{
		if (DEBUG) std::cout << "Is free" << point << std::endl;
		return tempLocation;
	}
	if (DEBUG) std::cout << "This address is not available, I am looking for free..." << std::endl;
	return getFreeLocation();
}
void Battlefield::printBattlefield()
{
	std::cout << std::endl;
	std::cout << "           BATTLEFIELD\n" << std::endl;
	std::cout << "      0   1   2   3   4   5   6   7" << std::endl;
	std::cout << "------------------------------------" << std::endl;
	for (int i = 0, j = 0; j < 8; j++) {
		std::cout << j << " | ";
		for (int k = 0; k < 8; k++) {
			std::cout << *square->at(i);
			i += 1;
		}
		std::cout << std::endl;
	}
};
