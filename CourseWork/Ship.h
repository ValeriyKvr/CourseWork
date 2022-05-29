#pragma once
#include <string>

class Ship {
	double enginePower, displacement;
	std::string shipName, homePort;
	int crewNumber;
public:
	Ship(double eP, double d, std::string sN, std::string hP, int cN);
	virtual std::string Info() const;
	int GetCrewNumber() const;
};