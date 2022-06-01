#include "MenuFunctions.h"

Ship createShip() {
	double enginePower;
	std::cout << "Enter engine power: ";
	std::cin >> enginePower;
	double displacement;
	std::cout << "Enter displacement: ";
	std::cin >> displacement;
	std::string shipName;
	std::cout << "Enter ship name: ";
	std::cin >> shipName;
	int crewNumber;
	std::cout << "Enter number of crew members: ";
	std::cin >> crewNumber;
	std::string homePort;
	std::cout << "Enter home port: ";
	std::cin >> homePort;
	std::vector<CrewMember> members;
	for (int i = 0; i < crewNumber; i++) {
		std::string name, surname, fullname;
		std::cout << "Enter name of crew member " + std::to_string(i) + ": ";
		std::cin >> name;
		std::cout << "Enter surname of crew member: ";
		std::cin >> surname;
		fullname = name + " " + surname;
		int memberAge;
		std::cout << "Enter " << fullname << " age: ";
		std::cin >> memberAge;
		int workExp;
		std::cout << "Enter " << fullname << " work experience: ";
		std::cin >> workExp;
		CrewMemberRank rank;
		int rankNumber;
		std::cout << std::endl;
		std::cout << "Rank: " << std::endl;
		std::cout << "0) Master;" << "\n" << "1) Master Assistant;" << "\n" << "2) ChiefEngineer;" << "\n"  << "3) Engineer Assistant;" 
			<< "\n" << "4) Sailor;" << "\n" << "5) Cook; " << "\n" << "6) Doctor" << std::endl;
		std::cin >> rankNumber;
		if (rankNumber < 0 or rankNumber > 6) {
			std::cout << "No such number, please, try again: ";
			std::cin >> rankNumber;
		}
		rank = static_cast<CrewMemberRank>(rankNumber);
		members.push_back(CrewMember(fullname, rank, memberAge, workExp));
	}
	return Ship(enginePower, displacement, shipName, homePort, crewNumber, members);
}

void printShip(std::vector<Ship>* ship, std::vector<PassengerShip>* passengerShip, std::vector<CargoShip>* cargoShip) {
	int i = 0;
	if (ship == NULL || !ship->size()) std::cout << "Ordinary ships missing." << std::endl;
	else {
		std::cout << "Ordinary ships: " << std::endl;
		for (auto c : *ship) {
			std::cout << "Ship's number: " << i << std::endl;
			std::cout << c.infoShip() << std::endl;
		}
	}
}
