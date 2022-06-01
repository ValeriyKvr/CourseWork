#include "Ship.h"
#include <iostream>
#include <stdexcept>

Ship::Ship(double eP, double d, std::string sN, std::string hP, int cN, std::vector<CrewMember> m) {
	if (eP < 0) throw std::invalid_argument("Incorrect engine power");
	if (d < 0) throw std::invalid_argument("Incorrect displacement");
	if (cN < 0) throw std::invalid_argument("Incorrect crew number");
	enginePower = eP, displacement = d, shipName = sN, homePort = hP, crewNumber = cN, members = m;
}

bool Ship::isMasterPresent() const {
	for (int i = 0; i < crewNumber; i++) {
		if (members[i].getRank() != CrewMemberRank::Master) return false;
		return true;
	}
}

std::string Ship::infoShip() const {
	std::string info =  ("Engine power is: " + std::to_string(enginePower) + '\n' + "Displacemnt is: " + std::to_string(displacement) + '\n'
		+ "Ship name is: " + shipName + '\n' + "Homeport is: " + homePort + '\n' + "Crew number is: " + std::to_string(crewNumber) + "\n");
	for (int i = 0; i < crewNumber; i++) {
		std::cout << std::endl;
		info += "\nCrew member #" + std::to_string(i) + "\n" + "Fullname: " + members[i].getFullname() + "\n" + "Age: " + std::to_string(members[i].getAge()) +
			"\n" + "Work experience: " + std::to_string(members[i].getWorkExp()) + "\n";
		const CrewMemberRank rank = members[i].getRank();
		switch (rank) {
			case CrewMemberRank::Master:
				info += "Rank: Master";
				std::cout << std::endl;
				break;
			case CrewMemberRank::MasterAssistant:
				info += "Rank: Master Assistant";
				std::cout << std::endl;
				break;
			case CrewMemberRank::ChiefEngineer:
				info += "Rank: Chief Engineer";
				std::cout << std::endl;
				break;
			case CrewMemberRank::EngineerAssistant:
				info += "Rank : Engineer Assistant";
				std::cout << std::endl;
				break;
			case CrewMemberRank::Sailor:
				info += "Rank: Sailor";
				std::cout << std::endl;
				break;
			case CrewMemberRank::Cook:
				info += "Rank: Cook";
				std::cout << std::endl;
				break;
			case CrewMemberRank::Doctor:
				info += "Rank: Doctor";
				std::cout << std::endl;
				break;
		}
	}
	return info;
}
int Ship::getCrewNumber() const { return crewNumber; }