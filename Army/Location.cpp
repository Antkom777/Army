#include <string>
#include "Location.h"
#include "Exceptions.h"

#define DEBUG 0

std::vector<Location*>* Location::square = Location::initSquare();

Location::Location(const Point& point, Unit* unit){
  if (DEBUG) std::cout << "Location constructor works" << std::endl;
  this->address = point;
  this->token = unit;
};

Location::~Location(){};

std::vector<Location*>* Location::initSquare() {
  if (DEBUG) std::cout << "initSquare constructor works" << std::endl;
  std::vector<Location*>* temp = new std::vector<Location*>(64); 
  if (DEBUG) std::cout << "vector created" << std::endl;
  for(int i = 0; i < 64; i++) {
    int j = i / 8;
    int k = i % 8;
    temp->at(i)  = new Location(Point(j,k)); 
    if (DEBUG) std::cout << "i=>" << i <<" j=>" << j <<" k=>" 
        <<k << std::endl;
    if (DEBUG) std::cout << temp->at(i)->getAddress() << std::endl;
  }
  if (DEBUG) std::cout << "OK, address =>" << temp <<  std::endl;
  return temp; 
};


bool Location::isFreeAddress(){
  if (DEBUG) std::cout << "isFreeAddress works" << std::endl;
  if (this->getToken() == NULL) {
    if (DEBUG)  std::cout << "isFreeAddress works TRUE"<< std::endl;
    return true;
  } else {
    if (DEBUG) std::cout << "isFreeAddress works FALSE"<< std::endl;
    return false;
  }
};

Location* Location::getFreeLocation() {
    if (DEBUG) std::cout << "getFreeLocation works" << std::endl;
    for (int i = 0; i < square->size(); i++) {
      if (Location::square->at(i)->getToken() == NULL) {
        return Location::square->at(i);
      } 
    }  
    throw new NotFreeLocationException();
};

Unit* Location::getToken(){
  return this->token;
};

void Location::setToken(Unit* unit){
  this->token = unit;
};

const Point& Location::getAddress(){
  return this->address;
};

Location* Location::getPointLocation(const Point& point) {
    if (DEBUG) std::cout << "getPointLocation works" << std::endl;
      for (int i = 0; i < Location::square->size(); i++) {
      if (Location::square->at(i)->getAddress() == point) {
        if (DEBUG) std::cout << "i => " << i << std::endl;
        return Location::square->at(i);
      } 
    }  
    throw new NotLocationException();
};

int Location::getIndex(const Point& point) {
      if (DEBUG) std::cout << "getIndex works" << std::endl;
      for (int i = 0; i < Location::square->size(); i++) {
      std::cout << " Index:"<< Location::square->at(i)->getAddress()<< std::endl;
      if (Location::square->at(i)->getAddress() == point) {
        if (DEBUG) std::cout << "i => " << i << std::endl;
        return i;
      } 
    }  
    throw new NotLocationException();
};

Location* Location::getValidLocation(const Point& point) {
  if (DEBUG) std::cout << "setValidLocation works" << std::endl;
  if (DEBUG) std::cout << "point" << point << std::endl;
  Location* tempLocation = Location::getPointLocation(point);

  if (tempLocation->isFreeAddress()) {
    if (DEBUG) std::cout << "Is free" << point << std::endl;
    return tempLocation;    
  } 
  // std::cout << "This address is not available, I am looking for free..." << std::endl;
  return Location::getFreeLocation();
}
void Location::printLocation(){
std::cout << std::endl;
std::cout << "           BATTLEFIELD\n" <<std::endl;
std::cout << "      0   1   2   3   4   5   6   7" <<std::endl;
std::cout << "------------------------------------" <<std::endl; 
  for(int i = 0, j = 0; j < 8; j++) {
    std::cout << j <<" | ";  
      for(int k = 0; k < 8; k++) {
          std::cout <<  *(Location::square->at(i));
          i += 1;
      }
    std::cout << std::endl;     
  }  
};
std::ostream& operator<<(std::ostream& out, Location& location) {
  if (location.getToken() == NULL) {
    out << "[  ]"; 
  } else {
    std::cout <<"[" << location.getToken()->getState()->label << "]";
  }

  return out;
}