#pragma once
#include "Ship.h"
class CargoShip : public Ship {
	double loadCapacity;
public:
	CargoShip(double eP, double d, std::string sN, std::string hP, int cN, double lC);
	std::string Info() const override;
};

