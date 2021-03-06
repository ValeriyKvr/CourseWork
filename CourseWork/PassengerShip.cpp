#include "PassengerShip.h"

PassengerShip::PassengerShip(double& eP, double& d, std::string& sN, std::string& hP, int& cN, std::vector<CrewMember>& cM, int& nOP, int& nOB, int& bC)  : OrdinaryShip(eP, d, sN, hP, cN, cM) {
	numberOfPassengers = nOP, numberOfBoats = nOB, boatCapacity = bC;
}

bool PassengerShip::isEnoughBoats() const {
	if ((getCrewNumber() + numberOfPassengers) > numberOfBoats * boatCapacity) return false;
	return true;
}

int PassengerShip::increaseBoats() {
	if (isEnoughBoats()) return numberOfBoats;
	else {
		while ((getCrewNumber() + numberOfPassengers) > numberOfBoats * boatCapacity) {
			numberOfBoats++;
		}
	}
	return numberOfBoats;
}

std::string PassengerShip::infoShip() const {
	return (OrdinaryShip::infoShip() + "\nNumber of passengers: " + std::to_string(numberOfPassengers) + '\n' + "Numbers of boats: " +
		std::to_string(numberOfBoats) + '\n' + "Boats capacity: " + std::to_string(boatCapacity));
}

int PassengerShip::getNumOfBoats() const { return numberOfBoats; }

void PassengerShip::setNumOfPas(const int& nOF) { numberOfPassengers = nOF; }
void PassengerShip::setNumOfBoats(const int& nOB) { numberOfBoats = nOB; }
void PassengerShip::setBoatsCap(const int& bC) { boatCapacity = bC; }