#include "OrdinaryShip.h"
#include <iostream>
#include <stdexcept>

OrdinaryShip::OrdinaryShip(double eP, double d, std::string sN, std::string hP, int cN, std::vector<CrewMember> cM) {
	enginePower = eP, displacement = d, shipName = sN, homePort = hP, crewNumber = cN, crewMembers = cM;
}

bool OrdinaryShip::isCaptainPresent() const {
	for (int i = 0; i < crewNumber; i++) {
		if (crewMembers[i].getRank() == CrewMemberRank::Captain) return true;
	}
	return false;
}

std::string OrdinaryShip::infoMember() const {
	std::string info;
	info = "\nNumber of crew members: " + std::to_string(crewNumber) + "\n";
	std::cout << std::endl;
	for (int i = 0; i < crewNumber; i++) {
		info += "\nCrew member #" + std::to_string(i + 1) + "\n" + "Fullname: " + crewMembers[i].getFullname() + "\n" + "Age: "
			+ std::to_string(crewMembers[i].getAge()) + " years." + "\n" + "Work experience: " + 
			std::to_string(crewMembers[i].getWorkExp()) + " years." + "\n";
		const CrewMemberRank rank = crewMembers[i].getRank();
		switch (rank) {
		case CrewMemberRank::Captain:
			info += "Rank: Captain\n";
			break;
		case CrewMemberRank::CaptainAssistant:
			info += "Rank: Captain Assistant\n";
			break;
		case CrewMemberRank::ChiefEngineer:
			info += "Rank: Chief Engineer\n";
			break;
		case CrewMemberRank::EngineerAssistant:
			info += "Rank: Engineer Assistant\n";
			break;
		case CrewMemberRank::Sailor:
			info += "Rank: Sailor\n";
			break;
		case CrewMemberRank::Cook:
			info += "Rank: Cook\n";
			break;
		case CrewMemberRank::Doctor:
			info += "Rank: Doctor\n";
			break;
		}
	}
	return info;
}

std::string OrdinaryShip::infoShip() const {
	std::string info = ("Engine power: " + std::to_string(enginePower) + " kW" + "\n" + "Displacemnt: " +
		std::to_string(displacement) + " tons" + "\n" + "Ship name: " + shipName + "\n" + "Homeport: " +
		homePort);
	return info;
}

double OrdinaryShip::getEnginePower() const { return enginePower; }
double OrdinaryShip::getDisplacement() const { return displacement; }
std::string OrdinaryShip::getShipName() const { return shipName; }
std::string OrdinaryShip::getHomePort() const { return homePort; }
int OrdinaryShip::getCrewNumber() const { return crewNumber; }
std::vector<CrewMember> OrdinaryShip::getCrewMembers() const { return crewMembers; }

void OrdinaryShip::setEnginePower(const double& eP) { enginePower = eP; }
void OrdinaryShip::setDisplacement(const double& d) { displacement = d; }
void OrdinaryShip::setShipName(const std::string& sN) { shipName = sN; }
void OrdinaryShip::setHomePort(const std::string& hP) { homePort = hP; }

void OrdinaryShip::changeMemberRank(int memberNum, CrewMemberRank newRank) {
	if (memberNum - 1 > crewMembers.size()) {
		std::cout << "Incorrect number." << std::endl;
	}
	crewMembers[memberNum - 1].setRank(newRank);
	std::cout << "Rank was changed." << std::endl;
}