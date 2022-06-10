#include "MenuFunctions.h"


int main() {
	try {
		std::vector<Ship> ordinaryShip;
		std::vector<PassengerShip> passengerShip;
		std::vector<CargoShip> cargoShip;
		int menuButton = 1;
		std::cout << "\tHello!\n" << "Welcome in my shipcreator!" << std::endl;
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
			if (menuButton <= 0 or menuButton >= 8) {
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
						ordinaryShip.push_back(createShip());
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
						printShip(&ordinaryShip, &passengerShip, &cargoShip);
						break;
					}
					break;
/////////////////////////////////////////////////////////////////////////////////////////////
				case 3: //Check Master;
					if (ordinaryShip.size() == 0 and passengerShip.size() == 0 and cargoShip.size() == 0) std::cout <<
						"No ships to check the Captain." << std::endl;
					else {
						int typeOfShip;
						std::cout << "Choose type of the ship to check the Captain." << std::endl;
						std::cout << "1) Ordinary ship." << "\n" << "2) Passenger ship." << "\n" << "3) Cargo ship." << std::endl;
						std::cin >> typeOfShip;
						switch (typeOfShip) {//Choose number of ship to check Master;
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
										std::cout << "Captain is present at ordinary shipnumber " << numShipToCheck << "." << std::endl;
										break;
									}
									else {
										std::cout << "Captain is missing at ordinary ship number " << numShipToCheck << "." << std::endl;
										break;
									}
									break;
								}
								else {
									std::cout << "The ordinary ship with number " << numShipToCheck << " wasn't created or deleted." << std::endl;
									break;
								}
							}
						case 2:	
							if (passengerShip.size() == 0) {
								std::cout << "The passenger ship wasn't created or deleted." << std::endl;
								break;
							}
							else {
								std::cout << "Please, enter the number of passenger ship to check the Captain." << std::endl;
								int numShipToCheck;
								std::cin >> numShipToCheck;
								if (numShipToCheck - 1 <= ordinaryShip.size()) {
									if (passengerShip[numShipToCheck - 1].isCaptainPresent()) {
										std::cout << "Captain is present at passenger shipnumber " << numShipToCheck << "." << std::endl;
										break;
									}
									else {
										std::cout << "Captain is missing at passenger ship number " << numShipToCheck << "." << std::endl;
										break;
									}
									break;
								}
								else {
									std::cout << "The passanger ship with number " << numShipToCheck << " wasn't created or deleted." 
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
								std::cout << "Please, enter the number of cargo ship to check the Captain." << std::endl;
								int numShipToCheck;
								std::cin >> numShipToCheck;
								if (numShipToCheck - 1 <= ordinaryShip.size()) {
									if (cargoShip[numShipToCheck - 1].isCaptainPresent()) {
										std::cout << "Captain is present at cargo shipnumber " << numShipToCheck << "." << std::endl;
										break;
									}
									else {
										std::cout << "Captain is missing at cargo ship number " << numShipToCheck << "." << std::endl;
									}
									break;
								}
								else {
									std::cout << "The cargo ship with number " << numShipToCheck << " wasn't created or deleted."
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
					if (numCheckBoats - 1 <= passengerShip.size()) {
						if (passengerShip[numCheckBoats - 1].isEnoughBoats()) {
							std::cout << "Boats enough." << std::endl;
							break;
						}
						else {
							std::cout << "Boats aren't enough at the passenger ship number " << numCheckBoats << "." << std::endl;
							std::cout << "Please, choose the next action: \n" << "1) Increase number of boats.\n" << "2) Save the current amount." << std::endl;
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
						std::cout << "Sorry, but you enter incorrect number." << std::endl;
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
					int typeOfShipDel;
					std::cin >> typeOfShipDel;
					if (typeOfShipDel == 1 and ordinaryShip.size() != 0) {//Modify ordinary ship
						std::cout << "Enter ship number: ";
						modShip(ordinaryShip);
						break;
					}
					if (ordinaryShip.size() == 0 and typeOfShipDel == 1) {
						std::cout << "No ordinary ships to modify." << std::endl;
						break;
					}
					if (typeOfShipDel == 2 and passengerShip.size() != 0) {//Modify passenger ship
						std::cout << "Enter passenger ship number: ";
						modPassengerShip(passengerShip);
						break;
					}
					if (passengerShip.size() == 0 and typeOfShipDel == 2) {
						std::cout << "No passenger ships to modify." << std::endl;
						break;
					}
					if (typeOfShipDel == 3 and cargoShip.size() != 0) {//Modify cargo ship
						std::cout << "Enter cargo ship number: ";
						modCargoShip(cargoShip);
						break;
					}
					if (cargoShip.size() == 0 and typeOfShipDel == 3) {
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