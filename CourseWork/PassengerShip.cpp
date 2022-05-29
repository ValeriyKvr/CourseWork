#include "PassengerShip.h"
#include <stdexcept>

PassengerShip::PassengerShip(double eP, double d, std::string sN, std::string hP, int cN, int nOP, int nOB, int bC) : Ship(eP, d, sN, hP, cN) {
	if (nOP < 0) throw std::invalid_argument("Passengers must be > 0");
	if (nOB < 0) throw std::invalid_argument("Boats must be > 0");
	if (bC < 0) throw std::invalid_argument("Boats capacity must be > 0");
	numberOfPassengers = nOP, numberOfBoats = nOB, boatCapacity = bC;
}

bool PassengerShip::isEnoughBoats() const {
	if ((GetCrewNumber() + numberOfPassengers) > numberOfBoats * boatCapacity) return false;
	return true;
}

int PassengerShip::IncreaseBoats() {
	if (isEnoughBoats()) {
		return int("Boats are enough");
	}
	return numberOfBoats += (GetCrewNumber() + numberOfPassengers) - (numberOfBoats * boatCapacity) / boatCapacity;

}

std::string PassengerShip::Info() const {
	return (Ship::Info() + "Number of passengers: " + std::to_string(numberOfPassengers) + '\n' + "Numbers 0f boats: " +
		std::to_string(numberOfBoats) + '\n' + "Boats capacity: " + std::to_string(boatCapacity) + '\n');
}