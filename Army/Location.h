#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <vector>
#include "Unit.h"
#include "Point.h"

class Unit;
class Point;

class Location {
  private:
    Point address;
    Unit* token;

  public:

  	Location(const Point& point, Unit* unit = NULL);
  	~Location();

    static std::vector<Location*>* square;
    static std::vector<Location*>* initSquare();
    static Location* getFreeLocation();
    bool isFreeAddress();
    Unit* getToken();
    int getIndex(const Point& point);
    void setToken(Unit* unit);
    const Point& getAddress();
    static Location* getPointLocation(const Point& point);
    static Location* getValidLocation(const Point& point); 
    static void printLocation();
};

std::ostream& operator<<(std::ostream& out, Location& location);

#endif