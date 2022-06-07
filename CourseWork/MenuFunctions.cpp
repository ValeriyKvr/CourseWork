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
		std::cout << "Enter name of crew member #" + std::to_string(i + 1) + ": ";
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
		std::cout << "1) Master;" << "\n" << "2) Master Assistant;" << "\n" << "3) ChiefEngineer;" << "\n"  << "4) Engineer Assistant;" 
			<< "\n" << "5) Sailor;" << "\n" << "6) Cook; " << "\n" << "7) Doctor" << std::endl;
		std::cin >> rankNumber;
		if (rankNumber < 1 or rankNumber > 7) {
			std::cout << "No such number, please, try again: ";
			std::cin >> rankNumber;
		}
		rank = CrewMemberRank(rankNumber + 1);
		members.push_back(CrewMember(fullname, rank, memberAge, workExp));
	}

	std::cout << "Ordinary ship was created. Thank you." << std::endl;
	return Ship(enginePower, displacement, shipName, homePort, crewNumber, members);
}

PassengerShip createPassengerShip() {
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
		std::cout << "Enter name of crew member #" + std::to_string(i + 1) + ": ";
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
		std::cout << "1) Master;" << "\n" << "2) Master Assistant;" << "\n" << "3) ChiefEngineer;" << "\n" << "4) Engineer Assistant;"
			<< "\n" << "5) Sailor;" << "\n" << "6) Cook; " << "\n" << "7) Doctor" << std::endl;
		std::cin >> rankNumber;
		if (rankNumber < 1 or rankNumber > 7) {
			std::cout << "No such number, please, try again: ";
			std::cin >> rankNumber;
		}
		rank = CrewMemberRank(rankNumber + 1);
		members.push_back(CrewMember(fullname, rank, memberAge, workExp));
	}
	int numberOfPassengers, numberOfBoats, boatCapacity;
	std::cout << std::endl;
	std::cout << "Enter number of passengers: ";
	std::cin >> numberOfPassengers;
	std::cout << "Enter number of boats: ";
	std::cin >> numberOfBoats;
	std::cout << "Enter boats capacity: ";
	std::cin >> boatCapacity;
	std::cout << "Passenger ship was created. Thank you." << std::endl;
	return PassengerShip(enginePower, displacement, shipName, homePort, crewNumber, members, numberOfPassengers, numberOfBoats, boatCapacity);
}

CargoShip createCargoShip() {
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
		std::cout << "Enter name of crew member #" + std::to_string(i + 1) + ": ";
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
		std::cout << "1) Master;" << "\n" << "2) Master Assistant;" << "\n" << "3) Chief Engineer;" << "\n" << "4) Engineer Assistant;"
			<< "\n" << "5) Sailor;" << "\n" << "6) Cook; " << "\n" << "7) Doctor" << std::endl;
		std::cin >> rankNumber;
		if (rankNumber < 1 or rankNumber > 7) {
			std::cout << "No such number, please, try again: ";
			std::cin >> rankNumber;
		}
		rank = CrewMemberRank(rankNumber + 1);
		members.push_back(CrewMember(fullname, rank, memberAge, workExp));
	}
	double loadCapacity;
	std::cout << "Enter load capacity: ";
	std::cin >> loadCapacity;
	std::cout << "Cargo ship was created. Thank you." << std::endl;
	return CargoShip(enginePower, displacement, shipName, homePort, crewNumber, members, loadCapacity);
}

void printShip(std::vector<Ship>* ship, std::vector<PassengerShip>* pasShip, std::vector<CargoShip>* cargoShip) {
	int i = 0;
	if (ship == 0 || !(*ship).size()) std::cout << "Ordinary ships are missing." << std::endl;
	else {
		std::cout << "Ordinary ships: " << std::endl;
		for (auto &c : *ship) {
			std::cout << "Ship's number: " << ++i << std::endl;
			std::cout << c.infoShip() << std::endl;
		}
	}
	std::cout << "_________________________________________________________________" << std::endl;
	if (pasShip == 0 || !(*pasShip).size()) std::cout << "Passenger ships are missing." << std::endl;
	else {
		std::cout << "Passenger ships: " << std::endl;
		for (auto &c : *pasShip) {
			std::cout << "Passenger ship's number: " << ++i << std::endl;
			std::cout << c.infoShip() << std::endl;
		}
	}
	std::cout << "_________________________________________________________________" << std::endl;
	if (cargoShip == 0 || !(*cargoShip).size()) std::cout << "Cargo ships are missing." << std::endl;
	else {
		std::cout << "Cargo ships: " << std::endl;
		for (auto &c : *cargoShip) {
			std::cout << "Cargo ship's number: " << ++i << std::endl;
			std::cout << c.infoShip() << std::endl;
		}
	}
}
/*void deleteShip(std::vector<Ship>* ship) {
	ship->pop_back();
	std::cout << "Ordinary ship was succesfully deleted. Tnak you." << std::endl;
}
void deletePasShip(std::vector<PassengerShip>* pasShip) {
	pasShip->pop_back();
	std::cout << "Passenger ship was succesfully deleted. Tnak you." << std::endl;
}
void deleteCargoShip(std::vector<CargoShip>* cargoShip) {
	cargoShip->pop_back();
	std::cout << "Cargo ship was succesfully deleted. Tnak you." << std::endl;
}*/