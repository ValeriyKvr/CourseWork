#pragma once
#include "CrewMember.h"
#include <string>
#include <vector>

class OrdinaryShip {
	double enginePower, displacement;
	std::string shipName, homePort;
	int crewNumber;
	std::vector<CrewMember> crewMembers;
public:
	OrdinaryShip(double eP, double d, std::string sN, std::string hP, int cN, std::vector<CrewMember> cM);
	virtual std::string infoShip() const;
	bool isCaptainPresent() const;
	void changeMemberRank(int memberNum, CrewMemberRank newRank);
	std::string infoMember() const;

	double getEnginePower() const;
	double getDisplacement() const;
	std::string getShipName() const;
	std::string getHomePort() const;
	int getCrewNumber() const;
	std::vector<CrewMember> getCrewMembers() const;

	void setEnginePower(const double& eP);
	void setDisplacement(const double& d);
	void setShipName(const std::string& sN);
	void setHomePort(const std::string& hP);
};

