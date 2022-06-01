#include "PassengerShip.h"
#include <stdexcept>

PassengerShip::PassengerShip(double eP, double d, std::string sN, std::string hP, int cN, std::vector<CrewMember> m, int nOP, int nOB, int bC)  : Ship(eP, d, sN, hP, cN, m) {
	if (nOP < 0) throw std::invalid_argument("Passengers must be > 0");
	if (nOB < 0) throw std::invalid_argument("Boats must be > 0");
	if (bC < 0) throw std::invalid_argument("Boats capacity must be > 0");
	numberOfPassengers = nOP, numberOfBoats = nOB, boatCapacity = bC;
}

bool PassengerShip::isEnoughBoats() const {
	if ((getCrewNumber() + numberOfPassengers) >= numberOfBoats * boatCapacity) return false;
	return true;
}

int PassengerShip::increaseBoats() {
	if (isEnoughBoats()) return int("Boats are enough");
	return numberOfBoats += (getCrewNumber() + numberOfPassengers) - (numberOfBoats * boatCapacity) / boatCapacity;

}

std::string PassengerShip::infoShip() const {
	return (Ship::infoShip() + "Number of passengers: " + std::to_string(numberOfPassengers) + '\n' + "Numbers 0f boats: " +
		std::to_string(numberOfBoats) + '\n' + "Boats capacity: " + std::to_string(boatCapacity) + '\n');
}