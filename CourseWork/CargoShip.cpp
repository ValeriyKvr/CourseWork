#include "CargoShip.h"
#include <stdexcept>

CargoShip::CargoShip(double eP, double d, std::string sN, std::string hP, int cN, std::vector<CrewMember> m, double lC) : OrdinaryShip(eP, d, sN, hP, cN, m) {
	loadCapacity = lC;
}
std::string CargoShip::infoShip() const {
	return(OrdinaryShip::infoShip() + "\nLoad capacity: " + std::to_string(loadCapacity) + " tons." + "\n");
}
void CargoShip::setLoadCap(const double& lC) { loadCapacity = lC; }
