#pragma once
#include "CrewMember.h"
#include <string>
#include <vector>

class Ship {
	double enginePower, displacement;
	std::string shipName, homePort;
	int crewNumber;
	std::vector<CrewMember> members;
public:
	Ship(double eP, double d, std::string sN, std::string hP, int cN, std::vector<CrewMember> m);
	virtual std::string infoShip() const;
	bool isMasterPresent() const;
	double getEnginePower() const;
	double getDispalcement() const;
	std::string getShipName() const;
	std::string getHomePort() const;
	int getCrewNumber() const;
};

