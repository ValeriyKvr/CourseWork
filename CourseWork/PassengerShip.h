#pragma once
#include "OrdinaryShip.h"
class PassengerShip : public OrdinaryShip {
	int numberOfPassengers, numberOfBoats, boatCapacity;
public:
	PassengerShip(double eP, double d, std::string sN, std::string hP, int cN, std::vector<CrewMember> m, int nOP, int nOB, int bC);
	~PassengerShip() = default;
	bool isEnoughBoats() const;
	int increaseBoats();
	std::string infoShip() const override;
	int getNumOfBoats() const;

	void setNumOfPas(const int& nOF);
	void setNumOfBoats(const int& nOB);
	void setBoatsCap(const int& bC);

};

