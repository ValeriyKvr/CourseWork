#include "PassengerShip.h"
#include <stdexcept>

PassengerShip::PassengerShip(double eP, double d, std::string sN, std::string hP, int cN, std::vector<CrewMember> m, int nOP, int nOB, int bC)  : Ship(eP, d, sN, hP, cN, m) {
	numberOfPassengers = nOP, numberOfBoats = nOB, boatCapacity = bC;
}

bool PassengerShip::isEnoughBoats() const {
	if ((getCrewNumber() + numberOfPassengers) >= numberOfBoats * boatCapacity) return false;
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
	return (Ship::infoShip() + "\nNumber of passengers: " + std::to_string(numberOfPassengers) + '\n' + "Numbers of boats: " +
		std::to_string(numberOfBoats) + '\n' + "Boats capacity: " + std::to_string(boatCapacity));
}

int PassengerShip::getNumOfBoats() const { return numberOfBoats; }

void PassengerShip::setNumOfPas(int nOF) { numberOfPassengers = nOF; }
void PassengerShip::setNumOfBoats(int nOB) { numberOfBoats = nOB; }
void PassengerShip::setBoatsCap(int bC) { boatCapacity = bC; }