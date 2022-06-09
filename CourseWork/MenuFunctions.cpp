#include "MenuFunctions.h"

Ship createShip() {
	double enginePower;
	std::cout << "Enter engine power in kW: ";
	std::cin >> enginePower;
	if (enginePower <= 0) {
		throw std::invalid_argument("Error. Incorrect engine power.");
	}
	double displacement;
	std::cout << "Enter displacement in tons: ";
	std::cin >> displacement;
	if (displacement <= 0) {
		throw std::invalid_argument("Error. Incorrect displacement.");
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
	if (crewNumber < 0 or crewNumber > 100) {
		throw std::invalid_argument("Error. Incorrect number of crew members.");
	}
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
		if (memberAge <= 0 or memberAge > 90) {
			throw std::invalid_argument("Error. Incorrect input.");
		}
		int workExp;
		std::cout << "Enter " << fullname << " work experience: " << std::endl;;
		std::cin >> workExp;
		if (workExp < 0 or workExp > memberAge - 18) {
			throw std::invalid_argument("Error. Incorrect input.");
		}
		CrewMemberRank rank;
		int rankNumber;
		std::cout << "Rank: " << "\n" << "1) Master;" << "\n" << "2) Master Assistant;" << "\n" << "3) Chief Engineer;" << "\n" << "4) Engineer Assistant;"
			<< "\n" << "5) Sailor;" << "\n" << "6) Cook; " << "\n" << "7) Doctor" << std::endl;
		std::cin >> rankNumber;
		if (rankNumber < 1 or rankNumber > 7) {
			std::cout << "No such number, please, try again: ";
			std::cin >> rankNumber;
		}
		rank = CrewMemberRank(rankNumber - 1);
		members.push_back(CrewMember(fullname, rank, memberAge, workExp));
	}
	std::cout << "Ordinary ship was created. Thank you." << std::endl;
	return Ship(enginePower, displacement, shipName, homePort, crewNumber, members);
}

PassengerShip createPassengerShip() {
	double enginePower;
	std::cout << "Enter engine power in kW: ";
	std::cin >> enginePower;
	if (enginePower <= 0) {
		throw std::invalid_argument("Error. Incorrect engine power.");
	}
	double displacement;
	std::cout << "Enter displacement in tons: ";
	std::cin >> displacement;
	if (displacement <= 0) {
		throw std::invalid_argument("Error. Incorrect displacement.");
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
	if (crewNumber < 0 or crewNumber > 100) {
		throw std::invalid_argument("Error. Incorrect number of crew members.");
	}
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
		std::cout << "Rank: " << "\n" << "1) Master;" << "\n" << "2) Master Assistant;" << "\n" << "3) Chief Engineer;" << "\n" 
			<< "4) Engineer Assistant;" << "\n" << "5) Sailor;" << "\n" << "6) Cook; " << "\n" << "7) Doctor" << std::endl;
		std::cin >> rankNumber;
		if (rankNumber < 1 or rankNumber > 7) {
			std::cout << "No such number, please, try again: ";
			std::cin >> rankNumber;
		}
		rank = CrewMemberRank(rankNumber - 1);
		members.push_back(CrewMember(fullname, rank, memberAge, workExp));
	}
	int numberOfPassengers, numberOfBoats, boatCapacity;
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
	std::cout << "Enter engine power in kW: ";
	std::cin >> enginePower;
	if (enginePower <= 0) {
		throw std::invalid_argument("Error. Incorrect engine power.");
	}
	double displacement;
	std::cout << "Enter displacement in tons: ";
	std::cin >> displacement;
	if (displacement <= 0) {
		throw std::invalid_argument("Error. Incorrect displacement.");
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
	if (crewNumber < 0 or crewNumber > 100) {
		throw std::invalid_argument("Error. Incorrect number of crew members.");
	}
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
		std::cout << "Rank: " << "\n" << "1) Master;" << "\n" << "2) Master Assistant;" << "\n" << "3) Chief Engineer;" << "\n"
			<< "4) Engineer Assistant;" << "\n" << "5) Sailor;" << "\n" << "6) Cook; " << "\n" << "7) Doctor" << std::endl;
		std::cin >> rankNumber;
		if (rankNumber < 1 or rankNumber > 7) {
			std::cout << "No such number, please, try again: ";
			std::cin >> rankNumber;
		}
		rank = CrewMemberRank(rankNumber - 1);
		members.push_back(CrewMember(fullname, rank, memberAge, workExp));
	}
	double loadCapacity;
	std::cout << "Enter load capacity: ";
	std::cin >> loadCapacity;
	std::cout << "Cargo ship was created. Thank you." << std::endl;
	return CargoShip(enginePower, displacement, shipName, homePort, crewNumber, members, loadCapacity);
}

void printShip(std::vector<Ship>* ship, std::vector<PassengerShip>* pasShip, std::vector<CargoShip>* cargoShip) {
	if (ship == 0 || !(*ship).size()) std::cout << "Ordinary ships are missing." << std::endl;
	else {
		int i = 0;
		std::cout << "\tOrdinary ships: " << std::endl;
		for (auto &c : *ship) {
			std::cout << "Ordinary ship number: " << ++i << std::endl;
			std::cout << c.infoShip() << std::endl;
		}
	}
	std::cout << "_________________________________________________________________" << std::endl;
	if (pasShip == 0 || !(*pasShip).size()) std::cout << "Passenger ships are missing." << std::endl;
	else {
		int i = 0;
		std::cout << "\tPassenger ships: " << std::endl;
		for (auto &c : *pasShip) {
			std::cout << "Passenger ship number: " << ++i << std::endl;
			std::cout << c.infoShip() << std::endl;
		}
	}
	std::cout << "_________________________________________________________________" << std::endl;
	if (cargoShip == 0 || !(*cargoShip).size()) std::cout << "Cargo ships are missing." << std::endl;
	else {
		int i = 0;
		std::cout << "\tCargo ships: " << std::endl;
		for (auto &c : *cargoShip) {
			std::cout << "Cargo ship number: " << ++i;
			std::cout << c.infoShip() << std::endl;
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
			std::cout << "1) Engine Power;\n2) Dispalcement;\n3) Ship Name;\n4) Ship homeport;" << std::endl;
			int numToChange;
			std::cin >> numToChange;
			if (numToChange == 1) {
				std::cout << "Please, enter new engine power in kW: ";
				double enginePower;
				std::cin >> enginePower;
				std::cout << "Engine power of ordinary ship number " << numShip << " was changed to " << enginePower
					<< std::endl;
				ship[numShip - 1].setEnginePower(enginePower);
			}
			if (numToChange == 2) {
				std::cout << "Please, enter new displacement in tons: ";
				double displacement;
				std::cin >> displacement;
				std::cout << "Displacement of ordinary ship number " << numShip << " was changed to " << displacement
					<< std::endl;
				ship[numShip - 1].setDisplacement(displacement);
			}
			if (numToChange == 3) {
				std::cout << "Please, enter new ship name: ";
				std::string shipName;
				std::cin >> shipName;
				std::cout << "Ship name was changed to " << shipName << std::endl;
				ship[numShip - 1].setShipName(shipName);
			}
			if (numToChange == 4) {
				std::cout << "Please, enter new home port: ";
				std::string homePort;
				std::cin >> homePort;
				std::cout << "Ship home port was changed to " << homePort << std::endl;
				ship[numShip - 1].setHomePort(homePort);
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
			std::cout << "1) Engine Power;\n2) Dispalcement;\n3) Ship Name;\n4) Ship Homeport;\n5) Number of passengers;\n"
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
			}
			if (numToChange == 2) {
				std::cout << "Please, enter new displacement in tons: ";
				double displacement;
				std::cin >> displacement;
				std::cout << "Displacement of passenger ship number " << numShip << " was changed to " << displacement
					<< std::endl;
				pasShip[numShip - 1].setDisplacement(displacement);
			}
			if (numToChange == 3) {
				std::cout << "Please, enter new ship name: ";
				std::string shipName;
				std::cin >> shipName;
				std::cout << "Ship name was changed to " << shipName << std::endl;
				pasShip[numShip - 1].setShipName(shipName);
			}
			if (numToChange == 4) {
				std::cout << "Please, enter new home port: ";
				std::string homePort;
				std::cin >> homePort;
				std::cout << "Ship home port was changed to " << homePort << std::endl;
				pasShip[numShip - 1].setHomePort(homePort);
			}
			if (numToChange == 5) {
				std::cout << "Please, enter new number of passengers: ";
				int numOfPas;
				std::cin >> numOfPas;
				std::cout << "Number of passengers was changed to " << numOfPas << std::endl;
				pasShip[numShip - 1].setNumOfPas(numOfPas);
			}
			if (numToChange == 6) {
				std::cout << "Please, enter new number of boats: ";
				int numOfBoats;
				std::cin >> numOfBoats;
				std::cout << "Number of boats was changed to " << numOfBoats << std::endl;
				pasShip[numShip - 1].setNumOfBoats(numOfBoats);
			}
			if (numToChange == 7) {
				std::cout << "Please, enter new boats capacity: ";
				int boatsCap;
				std::cin >> boatsCap;
				std::cout << "Boats capacity was changed to " << boatsCap << std::endl;
				pasShip[numShip - 1].setBoatsCap(boatsCap);
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
			std::cout << "1) Engine Power;\n2) Dispalcement;\n3) Ship Name;\n4) Ship Homeport;\n5) Load Capacity." << std::endl;
			int numToChange;
			std::cin >> numToChange;
			if (numToChange == 1) {
				std::cout << "Please, enter new engine power in kW: ";
				double enginePower;
				std::cin >> enginePower;
				std::cout << "Engine power of passenger ship number " << numShip << " was changed to " << enginePower
					<< std::endl;
				cargoShip[numShip - 1].setEnginePower(enginePower);
			}
			if (numToChange == 2) {
				std::cout << "Please, enter new displacement in tons: ";
				double displacement;
				std::cin >> displacement;
				std::cout << "Displacement of passenger ship number " << numShip << " was changed to " << displacement
					<< std::endl;
				cargoShip[numShip - 1].setDisplacement(displacement);
			}
			if (numToChange == 3) {
				std::cout << "Please, enter new ship name: ";
				std::string shipName;
				std::cin >> shipName;
				std::cout << "Ship name was changed to " << shipName << std::endl;
				cargoShip[numShip - 1].setShipName(shipName);
			}
			if (numToChange == 4) {
				std::cout << "Please, enter new home port: ";
				std::string homePort;
				std::cin >> homePort;
				std::cout << "Ship home port was changed to " << homePort << std::endl;
				cargoShip[numShip - 1].setHomePort(homePort);
			}
			if (numToChange == 5) {
				std::cout << "Please, enter new load capacity: ";
				double loadCap;
				std::cin >> loadCap;
				std::cout << "Ship load capacity was changed to " << loadCap << std::endl;
				cargoShip[numShip - 1].setLoadCap(loadCap);
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
