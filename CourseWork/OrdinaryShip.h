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
	double getDisplacement() const;
	std::string getShipName() const;
	std::string getHomePort() const;
	int getCrewNumber() const;
	void setEnginePower(double eP);
	void setDisplacement(double d);
	void setShipName(std::string sN);
	void setHomePort(std::string hP);
};

