#include "MenuFunctions.h"

void createCrewMember(std::vector<CrewMember>& crewMembers, int crewNumber) {
	for (int i = 0; i < crewNumber; i++) {
		std::string name, surname, fullname;
		std::cout << "Enter name of crew member #" + std::to_string(i + 1) + ": ";
		std::cin >> name;
		std::cout << "Enter surname of crew member #" + std::to_string(i + 1) + ": ";
		std::cin >> surname;
		fullname = name + " " + surname;
		int memberAge;
		std::cout << "Enter " << fullname << " age: ";
		std::cin >> memberAge;
		if (memberAge <= 0 or memberAge > 90) {
			throw std::invalid_argument("Error. Incorrect input.");
		}
		int workExp;
		std::cout << "Enter " << fullname << " work experience: ";
		std::cin >> workExp;
		if (workExp < 0 or workExp > memberAge - 18) {
			throw std::invalid_argument("Error. Incorrect input.");
		}
		CrewMemberRank rank;
		int rankNumber;
		std::cout << "Rank: " << "\n" << "1) Captain;" << "\n" << "2) Captain Assistant;" << "\n" << "3) Chief Engineer;" <<
			"\n" << "4) Engineer Assistant;" << "\n" << "5) Sailor;" << "\n" << "6) Cook; " << "\n" << "7) Doctor." << std::endl;
		std::cin >> rankNumber;
		if (rankNumber < 1 or rankNumber > 7) {
			std::cout << "No such number, please, try again: ";
			std::cin >> rankNumber;
		}
		rank = CrewMemberRank(rankNumber - 1);
		crewMembers.push_back(CrewMember(fullname, rank, memberAge, workExp));
	}
}

Ship createShip() {
	double enginePower;
	std::cout << "Enter engine power in kW: ";
	std::cin >> enginePower;
	if (enginePower <= 0) {
		throw std::invalid_argument("\nError. Incorrect engine power.");
	}
	double displacement;
	std::cout << "Enter displacement in tons: ";
	std::cin >> displacement;
	if (displacement <= 0) {
		throw std::invalid_argument("\nError. Incorrect displacement.");
	}
	std::string shipName;
	std::cout << "Enter ship name: ";
	std::cin.ignore(100, '\n');
	std::getline(std::cin, shipName);
	std::string homePort;
	std::cout << "Enter home port: ";
	std::getline(std::cin, homePort);
	int crewNumber;
	std::cout << "Enter number of crew members: ";
	std::cin >> crewNumber;
	if (crewNumber < 0 or crewNumber > 10) {
		throw std::invalid_argument("\nError. Incorrect number of crew members.");
	}
	std::vector<CrewMember> crewMembers;
	createCrewMember(crewMembers, crewNumber);
	std::cout << "Ordinary ship was created. Thank you." << std::endl;
	return Ship(enginePower, displacement, shipName, homePort, crewNumber, crewMembers);
}

PassengerShip createPassengerShip() {
	double enginePower;
	std::cout << "Enter engine power in kW: ";
	std::cin >> enginePower;
	if (enginePower <= 0) {
		throw std::invalid_argument("\nError. Incorrect engine power.");
	}
	double displacement;
	std::cout << "Enter displacement in tons: ";
	std::cin >> displacement;
	if (displacement <= 0) {
		throw std::invalid_argument("\nError. Incorrect displacement.");
	}
	std::string shipName;
	std::cout << "Enter ship name: ";
	std::cin.ignore(100, '\n');
	std::getline(std::cin, shipName);
	std::string homePort;
	std::cout << "Enter home port: ";
	std::getline(std::cin, homePort);
	int numberOfPassengers, numberOfBoats, boatCapacity;
	std::cout << "Enter number of passengers: ";
	std::cin >> numberOfPassengers;
	if (numberOfPassengers < 0) {
		throw std::invalid_argument("\nError. Incorrect number of passengers.");
	}
	std::cout << "Enter number of boats: ";
	std::cin >> numberOfBoats;
	if (numberOfBoats < 0) {
		throw std::invalid_argument("\nError. Incorrect number of boats.");
	}
	std::cout << "Enter boats capacity: ";
	std::cin >> boatCapacity;
	if (boatCapacity <= 0) {
		throw std::invalid_argument("\nError. Incorrect boats capacity.");
	}
	int crewNumber;
	std::cout << "Enter number of crew members: ";
	std::cin >> crewNumber;
	if (crewNumber < 0 or crewNumber > 10) {
		throw std::invalid_argument("\nError. Incorrect number of crew members.");
	}
	std::vector<CrewMember> crewMembers;
	createCrewMember(crewMembers, crewNumber);
	std::cout << "Passenger ship was created. Thank you." << std::endl;
	return PassengerShip(enginePower, displacement, shipName, homePort, crewNumber, crewMembers, numberOfPassengers, numberOfBoats, boatCapacity);
}

CargoShip createCargoShip() {
	double enginePower;
	std::cout << "Enter engine power in kW: ";
	std::cin >> enginePower;
	if (enginePower <= 0) {
		throw std::invalid_argument("\nError. Incorrect engine power.");
	}
	double displacement;
	std::cout << "Enter displacement in tons: ";
	std::cin >> displacement;
	if (displacement <= 0) {
		throw std::invalid_argument("\nError. Incorrect displacement.");
	}
	std::string shipName;
	std::cout << "Enter ship name: ";
	std::cin.ignore(100, '\n');
	std::getline(std::cin, shipName);
	std::string homePort;
	std::cout << "Enter home port: ";
	std::getline(std::cin, homePort);
	int crewNumber;
	std::cout << "Enter number of crew members: ";
	std::cin >> crewNumber;
	if (crewNumber < 0 or crewNumber > 10) {
		throw std::invalid_argument("\nError. Incorrect number of crew members.");
	}
	double loadCapacity;
	std::cout << "Enter load capacity: ";
	std::cin >> loadCapacity;
	if (loadCapacity < 0) {
		throw std::invalid_argument("\nError. Incorrect load capacity.");
	}
	std::vector<CrewMember> crewMembers;
	createCrewMember(crewMembers, crewNumber);
	std::cout << "Cargo ship was created. Thank you." << std::endl;
	return CargoShip(enginePower, displacement, shipName, homePort, crewNumber, crewMembers, loadCapacity);
}

void printShip(std::vector<Ship>* ship, std::vector<PassengerShip>* pasShip, std::vector<CargoShip>* cargoShip) {
	if (ship == 0 || !(*ship).size()) std::cout << "Ordinary ships are missing." << std::endl;
	else {
		int i = 0;
		std::cout << "\tOrdinary ships: " << std::endl;
		for (auto &c : *ship) {
			std::cout << "Ordinary ship number: " << ++i << std::endl;
			std::cout << "|||||||||||||||||||||||" << std::endl;
			std::cout << c.infoShip() << c.infoMember() << std::endl;
			std::cout << std::endl;
		}
	}
	std::cout << "_________________________________________________________________" << std::endl;
	if (pasShip == 0 || !(*pasShip).size()) std::cout << "Passenger ships are missing." << std::endl;
	else {
		int i = 0;
		std::cout << "\tPassenger ships: " << std::endl;
		for (auto &c : *pasShip) {
			std::cout << "Passenger ship number: " << ++i << std::endl;
			std::cout << "||||||||||||||||||||||||" << std::endl;
			std::cout << c.infoShip() << c.infoMember() << std::endl;
			std::cout << std::endl;
		}
	}
	std::cout << "_________________________________________________________________" << std::endl;
	if (cargoShip == 0 || !(*cargoShip).size()) std::cout << "Cargo ships are missing." << std::endl;
	else {
		int i = 0;
		std::cout << "\tCargo ships: " << std::endl;
		for (auto &c : *cargoShip) {
			std::cout << "Cargo ship number: " << ++i << std::endl;
			std::cout << "||||||||||||||||||||" << std::endl;
			std::cout << c.infoShip() << c.infoMember() << std::endl;
			std::cout << std::endl;
		}
	}
}

void modShip(std::vector<Ship>& ship) {
	int numShip;
	std::cin >> numShip;
	if (numShip > ship.size()) std::cout << "No ship with number " << numShip << "." << std::endl;
	else {
		std::cout << "Choose next action: " << std::endl;
		std::cout << "1) Change ship's characteristics." << std::endl;
		std::cout << "2) Reset to the menu." << std::endl;
		int shipChar;
		std::cin >> shipChar;
		switch (shipChar) {
		case 1:
			std::cout << "Choose characteristic, which you want to change:" << std::endl;
			std::cout << "1) Engine Power;\n2) Displacement;\n3) Ship Name;\n4) Ship Home Port." << std::endl;
			int numToChange;
			std::cin >> numToChange;
			if (numToChange == 1) {
				std::cout << "Please, enter new engine power in kW: ";
				double enginePower;
				std::cin >> enginePower;
				std::cout << "Engine power of ordinary ship number " << numShip << " was changed to " << enginePower
					<< std::endl;
				ship[numShip - 1].setEnginePower(enginePower);
				break;
			}
			if (numToChange == 2) {
				std::cout << "Please, enter new displacement in tons: ";
				double displacement;
				std::cin >> displacement;
				std::cout << "Displacement of ordinary ship number " << numShip << " was changed to " << displacement
					<< std::endl;
				ship[numShip - 1].setDisplacement(displacement);
				break;
			}
			if (numToChange == 3) {
				std::cout << "Please, enter new ship name: ";
				std::string shipName;
				std::cin >> shipName;
				std::cout << "Ship name was changed to " << shipName << std::endl;
				ship[numShip - 1].setShipName(shipName);
				break;
			}
			if (numToChange == 4) {
				std::cout << "Please, enter new home port: ";
				std::string homePort;
				std::cin >> homePort;
				std::cout << "Ship home port was changed to " << homePort << std::endl;
				ship[numShip - 1].setHomePort(homePort);
				break;
			}
			if (numToChange <= 0 or numToChange >= 5) {
				std::cout << "Incorrect number." << std::endl;
				break;
			} 
		case 2: 
			break;
		}
	}
}

void modPassengerShip(std::vector<PassengerShip>& pasShip) {
	int numShip;
	std::cin >> numShip;
	if (numShip > pasShip.size()) std::cout << "No passenger ship with number " << numShip << "." << std::endl;
	else {
		std::cout << "Choose next action: " << std::endl;
		std::cout << "1) Change ship's characteristics." << std::endl;
		std::cout << "2) Reset to the menu." << std::endl;
		int shipChar;
		std::cin >> shipChar;
		switch (shipChar) {
		case 1:
			std::cout << "Choose characteristic, which you want to change:" << std::endl;
			std::cout << "1) Engine Power;\n2) Displacement;\n3) Ship Name;\n4) Ship Home Port;\n5) Number of passengers;\n"
				"6) Number of boats;\n7) Boats capacity." << std::endl;
			int numToChange;
			std::cin >> numToChange;
			if (numToChange == 1) {
				std::cout << "Please, enter new engine power in kW: ";
				double enginePower;
				std::cin >> enginePower;
				std::cout << "Engine power of passenger ship number " << numShip << " was changed to " << enginePower
					<< std::endl;
				pasShip[numShip - 1].setEnginePower(enginePower);
				break;
			}
			if (numToChange == 2) {
				std::cout << "Please, enter new displacement in tons: ";
				double displacement;
				std::cin >> displacement;
				std::cout << "Displacement of passenger ship number " << numShip << " was changed to " << displacement
					<< std::endl;
				pasShip[numShip - 1].setDisplacement(displacement);
				break;
			}
			if (numToChange == 3) {
				std::cout << "Please, enter new ship name: ";
				std::string shipName;
				std::cin >> shipName;
				std::cout << "Ship name was changed to " << shipName << std::endl;
				pasShip[numShip - 1].setShipName(shipName);
				break;
			}
			if (numToChange == 4) {
				std::cout << "Please, enter new home port: ";
				std::string homePort;
				std::cin >> homePort;
				std::cout << "Ship home port was changed to " << homePort << std::endl;
				pasShip[numShip - 1].setHomePort(homePort);
				break;
			}
			if (numToChange == 5) {
				std::cout << "Please, enter new number of passengers: ";
				int numOfPas;
				std::cin >> numOfPas;
				std::cout << "Number of passengers was changed to " << numOfPas << std::endl;
				pasShip[numShip - 1].setNumOfPas(numOfPas);
				break;
			}
			if (numToChange == 6) {
				std::cout << "Please, enter new number of boats: ";
				int numOfBoats;
				std::cin >> numOfBoats;
				std::cout << "Number of boats was changed to " << numOfBoats << std::endl;
				pasShip[numShip - 1].setNumOfBoats(numOfBoats);
				break;
			}
			if (numToChange == 7) {
				std::cout << "Please, enter new boats capacity: ";
				int boatsCap;
				std::cin >> boatsCap;
				std::cout << "Boats capacity was changed to " << boatsCap << std::endl;
				pasShip[numShip - 1].setBoatsCap(boatsCap);
				break;
			}
			if (numToChange <= 0 or numToChange >= 5) {
				std::cout << "Incorrect number." << std::endl;
				break;
			}
		case 2:
			break;
		}
	}
}

void modCargoShip(std::vector<CargoShip>& cargoShip) {
	int numShip;
	std::cin >> numShip;
	if (numShip > cargoShip.size()) std::cout << "No cargo ship with number " << numShip << "." << std::endl;
	else {
		std::cout << "Choose next action: " << std::endl;
		std::cout << "1) Change ship's characteristics." << std::endl;
		std::cout << "2) Reset to the menu." << std::endl;
		int shipChar;
		std::cin >> shipChar;
		switch (shipChar) {
		case 1:
			std::cout << "Choose characteristic, which you want to change:" << std::endl;
			std::cout << "1) Engine Power;\n2) Displacement;\n3) Ship Name;\n4) Ship Home Port;\n5) Load Capacity." << std::endl;
			int numToChange;
			std::cin >> numToChange;
			if (numToChange == 1) {
				std::cout << "Please, enter new engine power in kW: ";
				double enginePower;
				std::cin >> enginePower;
				std::cout << "Engine power of passenger ship number " << numShip << " was changed to " << enginePower
					<< std::endl;
				cargoShip[numShip - 1].setEnginePower(enginePower);
				break;
			}
			if (numToChange == 2) {
				std::cout << "Please, enter new displacement in tons: ";
				double displacement;
				std::cin >> displacement;
				std::cout << "Displacement of passenger ship number " << numShip << " was changed to " << displacement
					<< std::endl;
				cargoShip[numShip - 1].setDisplacement(displacement);
				break;
			}
			if (numToChange == 3) {
				std::cout << "Please, enter new ship name: ";
				std::string shipName;
				std::cin >> shipName;
				std::cout << "Ship name was changed to " << shipName << std::endl;
				cargoShip[numShip - 1].setShipName(shipName);
				break;
			}
			if (numToChange == 4) {
				std::cout << "Please, enter new home port: ";
				std::string homePort;
				std::cin >> homePort;
				std::cout << "Ship home port was changed to " << homePort << std::endl;
				cargoShip[numShip - 1].setHomePort(homePort);
				break;
			}
			if (numToChange == 5) {
				std::cout << "Please, enter new load capacity: ";
				double loadCap;
				std::cin >> loadCap;
				std::cout << "Ship load capacity was changed to " << loadCap << std::endl;
				cargoShip[numShip - 1].setLoadCap(loadCap);
				break;
			}
			if (numToChange <= 0 or numToChange >= 6) {
				std::cout << "Incorrect number." << std::endl;
				break;
			}
		case 2:
			break;
		}
	}
}
