#include "CargoShip.h"
#include <stdexcept>

CargoShip::CargoShip(double eP, double d, std::string sN, std::string hP, int cN, std::vector<CrewMember> m, double lC) : Ship(eP, d, sN, hP, cN, m) {
	if (loadCapacity <= 0) throw std::invalid_argument("Load capacity must be > 0");
	loadCapacity = lC;
}
std::string CargoShip::infoShip() const {
	return(Ship::infoShip() + " Load capacity: " + std::to_string(loadCapacity));
}
