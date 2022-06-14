#include "OrdinaryShip.h"
#include "PassengerShip.h"
#include "CargoShip.h"

void createCrewMember(std::vector<CrewMember>& crewMembers, int crewNumber);
OrdinaryShip createOrdinaryShip();
PassengerShip createPassengerShip();
CargoShip createCargoShip();
void printShips(std::vector<OrdinaryShip>* ship, std::vector<PassengerShip>* pasShip, std::vector<CargoShip>* cargoShip);
void modShip(std::vector<OrdinaryShip>& ship);
void modPassengerShip(std::vector<PassengerShip>& pasShip);
void modCargoShip(std::vector<CargoShip>& cargoShip);

int main () {
	try {
		std::vector<OrdinaryShip> ordinaryShip;
		std::vector<PassengerShip> passengerShip;
		std::vector<CargoShip> cargoShip;
		int menuButton = 1;
		std::cout << "\tHello!\n" << "Welcome in my ship creator!" << std::endl;
		while (menuButton) {
			std::cout << "//////////////////////////////////////////////////" << std::endl;
			std::cout << "Please, choose the number:" << std::endl;
			std::cout << "1) Create ship." << std::endl;
			std::cout << "2) Show ships." << std::endl;
			std::cout << "3) Check for the Captain." << std::endl;
			std::cout << "4) Delete ship." << std::endl;
			std::cout << "5) Check the number of boats on a passenger ship." << std::endl;
			std::cout << "6) Modify ship." << std::endl;
			std::cout << "7) Exit." << std::endl;
			std::cout << "//////////////////////////////////////////////////" << std::endl;
			std::cin >> menuButton;
			if (menuButton < 1 or menuButton > 7) {
				std::cout << "Incorrect number. Try again." << std::endl;
				menuButton = 1;
			}
			else {
				std::cout << std::endl;
				switch (menuButton) {
				case 1: 
					int typeOfShip;
					std::cout << "What type of ship do you want to create?" << std::endl;
					std::cout << "1) Ordinary ship." << "\n" << "2) Passenger ship." << "\n" << "3) Cargo ship." << std::endl;
					std::cin >> typeOfShip;
					if (typeOfShip <= 0 or typeOfShip >= 4) {
						std::cout << "No such number to choose type of the ship. Go to the menu and choose correct number." << std::endl;
					}
					if (typeOfShip == 1) {
						ordinaryShip.push_back(createOrdinaryShip());
						break;
					}
					if (typeOfShip == 2) {
						passengerShip.push_back(createPassengerShip());
						break;
					}
					if (typeOfShip == 3) {
						cargoShip.push_back(createCargoShip());
						break;
					}
					break;
/////////////////////////////////////////////////////////////////////////////////////////
				case 2: 
					if (ordinaryShip.size() + passengerShip.size() + cargoShip.size() == 0) {
						std::cout << "Ships wasn't created or deleted." << std::endl;
						break;
					}
					else {
						printShips(&ordinaryShip, &passengerShip, &cargoShip);
						break;
					}
					break;
/////////////////////////////////////////////////////////////////////////////////////////////
				case 3: //Check Captain;
					if (ordinaryShip.size() == 0 and passengerShip.size() == 0 and cargoShip.size() == 0) std::cout <<
						"No ships to check the Captain." << std::endl;
					else {
						int typeOfShip;
						std::cout << "Choose type of the ship to check the Captain: " << std::endl;
						std::cout << "1) Ordinary ship." << "\n" << "2) Passenger ship." << "\n" << "3) Cargo ship." << std::endl;
						std::cin >> typeOfShip;
						if (typeOfShip < 1 or typeOfShip > 3) {
							std::cout << "No such number to choose type of the ship." << std::endl;
							break;
						}
						switch (typeOfShip) {//Choose number of ship to check Captain;
						case 1:
							if (ordinaryShip.size() == 0) {
								std::cout << "The ordinary ship wasn't created or deleted." << std::endl;
								break;
							}
							else {
								std::cout << "Please, enter the number of ordinary ship to check the Captain." << std::endl;
								int numShipToCheck;
								std::cin >> numShipToCheck;
								if (numShipToCheck - 1 <= ordinaryShip.size()) {
									if (ordinaryShip[numShipToCheck - 1].isCaptainPresent()) {
										std::cout << "\nCaptain is present at the ordinary ship number " << numShipToCheck << "." << std::endl;
										break;
									}
									else {
										std::cout << "\nCaptain is missing at the ordinary ship number " << numShipToCheck << "." << std::endl;
										break;
									}
									break;
								}
								else {
									std::cout << "The ordinary ship number " << numShipToCheck << " wasn't created or deleted." << std::endl;
									break;
								}
							}
						case 2:	
							if (passengerShip.size() == 0) {
								std::cout << "The passenger ship wasn't created or deleted." << std::endl;
								break;
							}
							else {
								std::cout << "Please, enter the number of passenger ship to check the Captain: ";
								int numShipToCheck;
								std::cin >> numShipToCheck;
								if (numShipToCheck - 1 <= ordinaryShip.size()) {
									if (passengerShip[numShipToCheck - 1].isCaptainPresent()) {
										std::cout << "\nCaptain is present at the passenger ship number " << numShipToCheck << "." << std::endl;
										break;
									}
									else {
										std::cout << "\nCaptain is missing at the passenger ship number " << numShipToCheck << "." << std::endl;
										break;
									}
									break;
								}
								else {
									std::cout << "The passanger ship number " << numShipToCheck << " wasn't created or deleted." 
										<< std::endl;
									break;
								}
							}
						case 3:
							if (cargoShip.size() == 0) {
								std::cout << "The cargo ship wasn't created or deleted." << std::endl;
								break;
							}
							else {
								std::cout << "Please, enter the number of the cargo ship to check the Captain." << std::endl;
								int numShipToCheck;
								std::cin >> numShipToCheck;
								if (numShipToCheck - 1 <= ordinaryShip.size()) {
									if (cargoShip[numShipToCheck - 1].isCaptainPresent()) {
										std::cout << "\nCaptain is present at the cargo ship number " << numShipToCheck << "." << std::endl;
										break;
									}
									else {
										std::cout << "\nCaptain is missing at the cargo ship number " << numShipToCheck << "." << std::endl;
									}
									break;
								}
								else {
									std::cout << "The cargo ship number " << numShipToCheck << " wasn't created or deleted."
										<< std::endl;
									break;
								}
							}
						}
					}
					break;
///////////////////////////////////////////////////////////////////////////////////
				case 4: 
					if (ordinaryShip.size() == 0 and passengerShip.size() == 0 and cargoShip.size() == 0) {
						std::cout << "No ships to delete." << std::endl;
						break;
					}
					std::cout << "What type of ship do you want to delete?" << std::endl;
					std::cout << "1) Ordinary ship." << "\n" << "2) Passenger ship." << "\n" << "3) Cargo ship." << std::endl;
					int typeOfShipToDel;
					std::cin >> typeOfShipToDel;
					if (typeOfShipToDel == 1 and ordinaryShip.size() != 0) {
						std::cout << "Please, enter number of the ordinary ship, which you want to delete: " << std::endl;
						int delShipNum;
						std::cin >> delShipNum;
						if (delShipNum > ordinaryShip.size()) {
							std::cout << "Incorrect number." << std::endl;
							break;
						}
						else {
							ordinaryShip.erase(ordinaryShip.begin() + delShipNum - 1);
							std::cout << "The ordinary ship number " << delShipNum << " was succesfully deleted." << std::endl;
							break;
						}
					}
					if (typeOfShipToDel == 2 and passengerShip.size() != 0) {
						std::cout << "Please, enter number of the passenger ship, which you want to delete: " << std::endl;
						int delShipNum;
						std::cin >> delShipNum;
						if (delShipNum > passengerShip.size()) {
							std::cout << "Incorrect number." << std::endl;
							break;
						}
						else {
							passengerShip.erase(passengerShip.begin() + delShipNum - 1);
							std::cout << "The passenger ship number " << delShipNum << " was succesfully deleted." << std::endl;
							break;
						}
					}
					if (typeOfShipToDel == 3 and cargoShip.size() != 0) {
						std::cout << "Please, enter number of the cargo ship, which you want to delete: " << std::endl;
						int delShipNum;
						std::cin >> delShipNum;
						if (delShipNum > cargoShip.size()) {
							std::cout << "Incorrect number." << std::endl;
							break;
						}
						else {
							cargoShip.erase(cargoShip.begin() + delShipNum - 1);
							std::cout << "The cargo ship number " << delShipNum << " was succesfully deleted." << std::endl;
							break;
						}
					}
					if (ordinaryShip.size() == 0 and typeOfShipToDel == 1) {
						std::cout << "All ordinary ships are deleted or not created." << std::endl;
						break;
					}
					if (passengerShip.size() == 0 and typeOfShipToDel == 2) {
						std::cout << "All passenger ships are deleted or not created." << std::endl;
						break;
					}
					if (cargoShip.size() == 0 and typeOfShipToDel == 3) {
						std::cout << "All cargo ships are deleted or not created." << std::endl;
						break;
					}
					break;
///////////////////////////////////////////////////////////////////////////////////////////////////
				case 5:
					if (passengerShip.size() == 0) {
						std::cout << "All passenger ships are deleted or not created." << std::endl;
						break;
					}
					std::cout << "Please, enter the number of passenger ship to check number of boats." << std::endl;
					int numCheckBoats;
					std::cin >> numCheckBoats;
					if (numCheckBoats <= passengerShip.size()) {
						if (passengerShip[numCheckBoats - 1].isEnoughBoats()) {
							std::cout << "Enough boats." << std::endl;
							break;
						}
						else {
							std::cout << "Boats aren't enough at the passenger ship number " << numCheckBoats << "." << std::endl;
							std::cout << "Please, choose the next action: \n" << "1) Increase number of boats.\n" << 
								"2) Save the current amount." << std::endl;
							int numInc;
							std::cin >> numInc;
							if (numInc == 1) {
								passengerShip[numCheckBoats - 1].increaseBoats();
								std::cout << "Number of boats was increased to " << passengerShip[numCheckBoats - 1].getNumOfBoats() << std::endl;
								break;
							}
							else if (numInc == 2) {
								std::cout << "No changes." << std::endl;
								break;
							}
							else std::cout << "Incorrect number." << std::endl;
						}
						break;
					}
					else {
						std::cout << "Sorry, but passenger ship number " << numCheckBoats << " wasn't created or deleted." << std::endl;
						break;
					}
					break;
//////////////////////////////////////////////////////////////////////////////
				case 6:
					if (ordinaryShip.size() == 0 and passengerShip.size() == 0 and cargoShip.size() == 0) {
						std::cout << "No ships to modify." << std::endl;
						break;
					}
					std::cout << "What type of ship do you want to modify?" << std::endl;
					std::cout << "1) Ordinary ship." << "\n" << "2) Passenger ship." << "\n" << "3) Cargo ship." << std::endl;
					int typeOfShipMod;
					std::cin >> typeOfShipMod;
					if (typeOfShipMod != 1 and typeOfShipMod != 2 and typeOfShipMod != 3) {
						std::cout << "You choose incorrect number." << std::endl;
						break;
					}
					if (typeOfShipMod == 1 and ordinaryShip.size() != 0) {//Modify ordinary ship
						std::cout << "Enter ship number: ";
						modShip(ordinaryShip);
						break;
					}
					if (ordinaryShip.size() == 0 and typeOfShipMod == 1) {
						std::cout << "No ordinary ships to modify." << std::endl;
						break;
					}
					if (typeOfShipMod == 2 and passengerShip.size() != 0) {//Modify passenger ship
						std::cout << "Enter passenger ship number: ";
						modPassengerShip(passengerShip);
						break;
					}
					if (passengerShip.size() == 0 and typeOfShipMod == 2) {
						std::cout << "No passenger ships to modify." << std::endl;
						break;
					}
					if (typeOfShipMod == 3 and cargoShip.size() != 0) {//Modify cargo ship
						std::cout << "Enter cargo ship number: ";
						modCargoShip(cargoShip);
						break;
					}
					if (cargoShip.size() == 0 and typeOfShipMod == 3) {
						std::cout << "No cargo ships to modify." << std::endl;
						break;
					}
					break;
/////////////////////////////////////////////////////////////////////////////
				case 7: 
					menuButton = 0;
					std::cout << "Thank you. Goodbye!" << std::endl;
					break;
				}
			}
		}
	}
	catch (std::invalid_argument ia) {
		std::cout << ia.what() << std::endl;
	}
}

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
			throw std::invalid_argument("Error. Incorrect age.");
		}
		int workExp;
		std::cout << "Enter " << fullname << " work experience: ";
		std::cin >> workExp;
		if (workExp < 0 or workExp > memberAge - 18) {
			throw std::invalid_argument("Error. Incorrect work experience.");
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

OrdinaryShip createOrdinaryShip() {
	double enginePower, displacement;
	std::cout << "Enter engine power in kW: ";
	std::cin >> enginePower;
	if (enginePower <= 0) {
		throw std::invalid_argument("\nError. Incorrect engine power.");
	}
	std::cout << "Enter displacement in tons: ";
	std::cin >> displacement;
	if (displacement <= 0) {
		throw std::invalid_argument("\nError. Incorrect displacement.");
	}
	std::string shipName, homePort;
	std::cout << "Enter ship name: ";
	std::cin.ignore(100, '\n');
	std::getline(std::cin, shipName);
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
	return OrdinaryShip(enginePower, displacement, shipName, homePort, crewNumber, crewMembers);
}
PassengerShip createPassengerShip() {
	double enginePower, displacement;
	std::cout << "Enter engine power in kW: ";
	std::cin >> enginePower;
	if (enginePower <= 0) {
		throw std::invalid_argument("\nError. Incorrect engine power.");
	}
	std::cout << "Enter displacement in tons: ";
	std::cin >> displacement;
	if (displacement <= 0) {
		throw std::invalid_argument("\nError. Incorrect displacement.");
	}
	std::string shipName, homePort;
	std::cout << "Enter ship name: ";
	std::cin.ignore(100, '\n');
	std::getline(std::cin, shipName);
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
	double enginePower, displacement, loadCapacity;
	std::cout << "Enter engine power in kW: ";
	std::cin >> enginePower;
	if (enginePower <= 0) {
		throw std::invalid_argument("\nError. Incorrect engine power.");
	}
	std::cout << "Enter displacement in tons: ";
	std::cin >> displacement;
	if (displacement <= 0) {
		throw std::invalid_argument("\nError. Incorrect displacement.");
	}
	std::string shipName, homePort;
	std::cout << "Enter ship name: ";
	std::cin.ignore(100, '\n');
	std::getline(std::cin, shipName);
	std::cout << "Enter home port: ";
	std::getline(std::cin, homePort);
	int crewNumber;
	std::cout << "Enter number of crew members: ";
	std::cin >> crewNumber;
	if (crewNumber < 0 or crewNumber > 10) {
		throw std::invalid_argument("\nError. Incorrect number of crew members.");
	}
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

void printShips(std::vector<OrdinaryShip>* ship, std::vector<PassengerShip>* pasShip, std::vector<CargoShip>* cargoShip) {
	if (ship == 0 || !(*ship).size()) std::cout << "Ordinary ships are missing." << std::endl;
	else {
		int i = 0;
		std::cout << "\tOrdinary ships: " << std::endl;
		for (auto c : *ship) {
			std::cout << "Ordinary ship number: " << ++i << std::endl;
			std::cout << "|||||||||||||||||||||||" << std::endl;
			std::cout << c.infoShip() << c.infoMember() << std::endl;
		}
	}
	std::cout << "_________________________________________________________________" << std::endl;
	if (pasShip == 0 || !(*pasShip).size()) std::cout << "Passenger ships are missing." << std::endl;
	else {
		int i = 0;
		std::cout << "\tPassenger ships: " << std::endl;
		for (auto c : *pasShip) {
			std::cout << "Passenger ship number: " << ++i << std::endl;
			std::cout << "||||||||||||||||||||||||" << std::endl;
			std::cout << c.infoShip() << c.infoMember() << std::endl;
		}
	}
	std::cout << "_________________________________________________________________" << std::endl;
	if (cargoShip == 0 || !(*cargoShip).size()) std::cout << "Cargo ships are missing." << std::endl;
	else {
		int i = 0;
		std::cout << "\tCargo ships: " << std::endl;
		for (auto c : *cargoShip) {
			std::cout << "Cargo ship number: " << ++i << std::endl;
			std::cout << "||||||||||||||||||||" << std::endl;
			std::cout << c.infoShip() << c.infoMember() << std::endl;
		}
	}
}

void modShip(std::vector<OrdinaryShip>& ship) {
	int numShip;
	std::cin >> numShip;
	if (numShip > ship.size()) std::cout << "No ship with number " << numShip << "." << std::endl;
	else {
		std::cout << "Choose next action: " << std::endl;
		std::cout << "1) Change ship's characteristics." << std::endl;
		std::cout << "2) Change rank." << std::endl;
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
				if (enginePower <= 0) {
					std::cout << "Incorrect engine power." << std::endl;
					break;
				}
				std::cout << "Engine power of ordinary ship number " << numShip << " was changed to " << enginePower
					<< std::endl;
				ship[numShip - 1].setEnginePower(enginePower);
				break;
			}
			if (numToChange == 2) {
				std::cout << "Please, enter new displacement in tons: ";
				double displacement;
				std::cin >> displacement;
				if (displacement <= 0) {
					std::cout << "Incorrect displacement." << std::endl;
					break;
				}
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
			if (ship[numShip - 1].getCrewMembers().size() == 0) {
				std::cout << "No members on the ship." << std::endl;
				break;
			}
			std::cout << "Enter number of crew member: " << std::endl;
			int num;
			std::cin >> num;
			if (num - 1 > ship[numShip - 1].getCrewMembers().size()) {
				std::cout << "No crew member with number: " << num << std::endl;
				break;
			}
			std::cout << "Rank to change: " << "\n" << "1) Captain;" << "\n" << "2) Captain Assistant;" << "\n" << "3) Chief Engineer;" <<
				"\n" << "4) Engineer Assistant;" << "\n" << "5) Sailor;" << "\n" << "6) Cook; " << "\n" << "7) Doctor." << std::endl;
			int rankNumber;
			std::cin >> rankNumber;
			if (rankNumber < 1 or rankNumber > 7) {
				std::cout << "No such number, please, try again: ";
				std::cin >> rankNumber;
			}
			CrewMemberRank rank = CrewMemberRank(rankNumber - 1);
			if (rank == ship[numShip - 1].getCrewMembers()[num - 1].getRank()) {
				std::cout << "This is the same rank." << std::endl;
				break;
			}
			ship[numShip - 1].changeMemberRank(num, rank);
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
		std::cout << "2) Change rank." << std::endl;
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
				if (enginePower <= 0) {
					std::cout << "Incorrect engine power." << std::endl;
					break;
				}
				std::cout << "Engine power of passenger ship number " << numShip << " was changed to " << enginePower
					<< std::endl;
				pasShip[numShip - 1].setEnginePower(enginePower);
				break;
			}
			if (numToChange == 2) {
				std::cout << "Please, enter new displacement in tons: ";
				double displacement;
				std::cin >> displacement;
				if (displacement <= 0) {
					std::cout << "Incorrect displacement." << std::endl;
					break;
				}
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
				if (numOfPas < 0) {
					std::cout << "Incorrect number of passengers." << std::endl;
					break;
				}
				std::cout << "Number of passengers was changed to " << numOfPas << std::endl;
				pasShip[numShip - 1].setNumOfPas(numOfPas);
				break;
			}
			if (numToChange == 6) {
				std::cout << "Please, enter new number of boats: ";
				int numOfBoats;
				std::cin >> numOfBoats;
				if (numOfBoats < 0) {
					std::cout << "Incorrect number of boats." << std::endl;
					break;
				}
				std::cout << "Number of boats was changed to " << numOfBoats << std::endl;
				pasShip[numShip - 1].setNumOfBoats(numOfBoats);
				break;
			}
			if (numToChange == 7) {
				std::cout << "Please, enter new boats capacity: ";
				int boatsCap;
				std::cin >> boatsCap;
				if (boatsCap <= 0) {
					std::cout << "Incorrect boats capacity." << std::endl;
					break;
				}
				std::cout << "Boats capacity was changed to " << boatsCap << std::endl;
				pasShip[numShip - 1].setBoatsCap(boatsCap);
				break;
			}
			if (numToChange < 1 or numToChange > 7) {
				std::cout << "Incorrect number." << std::endl;
				break;
			}
		case 2:
			if (pasShip[numShip - 1].getCrewMembers().size() == 0) {
				std::cout << "No members on the ship." << std::endl;
				break;
			}
			std::cout << "Enter number of crew member: " << std::endl;
			int num;
			std::cin >> num;
			if (num - 1 > pasShip[numShip - 1].getCrewMembers().size()) {
				std::cout << "No crew member with number: " << num << std::endl;
				break;
			}
			std::cout << "Rank to change: " << "\n" << "1) Captain;" << "\n" << "2) Captain Assistant;" << "\n" << "3) Chief Engineer;" <<
				"\n" << "4) Engineer Assistant;" << "\n" << "5) Sailor;" << "\n" << "6) Cook; " << "\n" << "7) Doctor." << std::endl;
			int rankNumber;
			std::cin >> rankNumber;
			if (rankNumber < 1 or rankNumber > 7) {
				std::cout << "No such number, please, try again: ";
				std::cin >> rankNumber;
			}
			CrewMemberRank rank = CrewMemberRank(rankNumber - 1);
			if (rank == pasShip[numShip - 1].getCrewMembers()[num - 1].getRank()) {
				std::cout << "This is the same rank." << std::endl;
				break;
			}
			pasShip[numShip - 1].changeMemberRank(num, rank);
			break;
		}
	}
}
void modCargoShip(std::vector<CargoShip>& cargoShip) {
	int numShip;
	std::cin >> numShip;
	if (numShip > cargoShip.size()) {
		std::cout << "No cargo ship with number " << numShip << "." << std::endl;
	}
	else {
		std::cout << "Choose next action: " << std::endl;
		std::cout << "1) Change ship's characteristics." << std::endl;
		std::cout << "2) Change rank." << std::endl;
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
				if (enginePower <= 0) {
					std::cout << "Incorrect engine power." << std::endl;
					break;
				}
				std::cout << "Engine power of passenger ship number " << numShip << " was changed to " << enginePower
					<< std::endl;
				cargoShip[numShip - 1].setEnginePower(enginePower);
				break;
			}
			if (numToChange == 2) {
				std::cout << "Please, enter new displacement in tons: ";
				double displacement;
				std::cin >> displacement;
				if (displacement <= 0) {
					std::cout << "Incorrect displacement." << std::endl;
					break;
				}
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
				if (loadCap <= 0) {
					std::cout << "Incorrect load capacity." << std::endl;
					break;
				}
				std::cout << "Ship load capacity was changed to " << loadCap << std::endl;
				cargoShip[numShip - 1].setLoadCap(loadCap);
				break;
			}
			if (numToChange <= 0 or numToChange >= 6) {
				std::cout << "Incorrect number." << std::endl;
				break;
			}
		case 2:
			if (cargoShip[numShip - 1].getCrewMembers().size() == 0) {
				std::cout << "No members on the ship." << std::endl;
				break;
			}
			std::cout << "Enter number of crew member: " << std::endl;
			int num;
			std::cin >> num;
			if (num - 1 > cargoShip[numShip - 1].getCrewMembers().size()) {
				std::cout << "No crew member with number: " << num << std::endl;
				break;
			}
			std::cout << "Rank to change: " << "\n" << "1) Captain;" << "\n" << "2) Captain Assistant;" << "\n" << "3) Chief Engineer;" <<
				"\n" << "4) Engineer Assistant;" << "\n" << "5) Sailor;" << "\n" << "6) Cook; " << "\n" << "7) Doctor." << std::endl;
			int rankNumber;
			std::cin >> rankNumber;
			if (rankNumber < 1 or rankNumber > 7) {
				std::cout << "No such number, please, try again: ";
				std::cin >> rankNumber;
			}
			CrewMemberRank rank = CrewMemberRank(rankNumber - 1);
			if (rank == cargoShip[numShip - 1].getCrewMembers()[num - 1].getRank()) {
				std::cout << "This is the same rank." << std::endl;
				break;
			}
			cargoShip[numShip - 1].changeMemberRank(num, rank);
			break;
		}
	}
}