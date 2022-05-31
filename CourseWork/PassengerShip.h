#pragma once
#include "Ship.h"
class PassengerShip : public Ship {
	int numberOfPassengers, numberOfBoats, boatCapacity;
public:
	PassengerShip(double eP, double d, std::string sN, std::string hP, int cN, int nOP, int nOB, int bC);
	bool isEnoughBoats() const;
	int increaseBoats();
	std::string info() const override;
};

