#include "MenuFunctions.h"

Ship makeShip() {
	double enginePower;
	std::cout << "Enter engine power: ";
	std::cin >> enginePower;
	double displacement;
	std::cout << "Enter displacement: ";
	std::cin >> displacement;
	std::string shipName;
	std::cout << "Enter ship name: ";
	std::getline(std::cin, shipName);
	std::string homePort;
	std::cout << "Enter home port: ";
	std::getline(std::cin, homePort);
	int crewNumber;
	std::cout << "Enter number of crew members: ";
	std::cin >> crewNumber;
	const auto members = new CrewMember[crewNumber];
	for (int i = 0; i < crewNumber; i++) {
		std::string fullname;
		std::cout << "Enter fullname of crew member: ";
		std::getline(std::cin, fullname);
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
		std::cout << "0) Master;" << "\n" << "1) ChiefEngineer;" << "\n" << "2) Sailor;" << "\n" << "3) Cook;" << std::endl;
		std::cin >> rankNumber;
		if (rankNumber < 0 or rankNumber > 3) {
			std::cout << "No such number, please, try again: ";
			std::cin >> rankNumber;
		}
		rank = static_cast<CrewMemberRank>(rankNumber);

		members[i] = CrewMember(fullname, rank, memberAge, workExp);
	}
	return Ship(enginePower, displacement, shipName, homePort, crewNumber, *members);

}