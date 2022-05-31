#include "Ship.h"
#include <stdexcept>

Ship::Ship(double eP, double d, std::string sN, std::string hP, int cN) {
	if (eP < 0) throw std::invalid_argument("Incorrect engine power");
	if (d < 0) throw std::invalid_argument("Incorrect displacement");
	if (cN < 0) throw std::invalid_argument("Incorrect crew number");
	enginePower = eP, displacement = d, shipName = sN, homePort = hP, crewNumber = cN;
}

int Ship::GetCrewNumber() const { return crewNumber; }

std::string Ship::info() const {
	return ("Engine power is: " + std::to_string(enginePower) + '\n' + "Displacemnt is: " + std::to_string(displacement) + '\n'
		+ "Ship name is: " + shipName + '\n' + "Homeport is: " + homePort + '\n' + "Crew number is: " + std::to_string(crewNumber));
}