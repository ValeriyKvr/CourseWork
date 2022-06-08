#pragma once
#include "OrdinaryShip.h"
class CargoShip : public Ship {
	double loadCapacity;
public:
	CargoShip(double eP, double d, std::string sN, std::string hP, int cN, std::vector<CrewMember> m, double lC);
	std::string infoShip() const override;
};

