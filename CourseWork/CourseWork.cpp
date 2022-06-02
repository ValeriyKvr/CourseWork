#include <iostream>
#include "MenuFunctions.h"

int main() {
	std::vector<Ship> ship;
	std::vector<PassengerShip> passengerShip;
	std::vector<CargoShip> cargoShip;
	int menuButton = 1;
	while (menuButton) {
		std::cout << "/////////////////////////////" << std::endl;
		std::cout << "Choose number: " << std::endl;
		std::cout << "\t1) Create ship. " << std::endl;
		std::cout << "\t2) Show ships." << std::endl;
		std::cout << "\t3) Check Master." << std::endl;
		std::cout << "\t4) Exit." << std::endl;
		std::cin >> menuButton;
		std::cout << std::endl;
		switch (menuButton) {
			case 1: {
				int typeOfShip;
				std::cout << "What type of ship do you want to create?" << std::endl;
				std::cout << "1) Ordinary ship." << "\n" << "2) Passenger ship." << "\n" << "3) Cargo ship." << std::endl;
				std::cin >> typeOfShip;
				if (typeOfShip == 1) {
					ship.push_back(createShip());
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
				else {
					std::cout << "No such ships." << std::endl;
					break;
				}
				break;
			}
			case 2: {
				if (ship.size() + passengerShip.size() + cargoShip.size() == 0) {
					std::cout << "No ships" << std::endl;
					break;
				}
				else {
					printShip(&ship, &passengerShip, &cargoShip);
					break;
				}
				break;
			}
			case 3: {
				if (ship.size() + passengerShip.size() + cargoShip.size() == 0) std::cout << "No ships to check the Master." << std::endl;
				else {
					for (int i = 0; i < ship.size(); i++) {
						if (!ship[i].isMasterPresent()) {
							std::cout << "Master is present at ordinary ship." << std::endl;
						}
						else {
							std::cout << "Master is missing at ordinary ship." << std::endl;
							break;
						}
					}
					for (int i = 0; i < passengerShip.size(); i++) {
						if (!passengerShip[i].isMasterPresent()) {
							std::cout << "Master is present at passenger ship." << std::endl;
						}
						else {
							std::cout << "Master is missing at passenger ship." << std::endl;
							break;
						}
					}
					for (int i = 0; i < cargoShip.size(); i++) {
						if (!cargoShip[i].isMasterPresent()) {
							std::cout << "Master is present at cargo ship." << std::endl;
							break;
						}
						else {
							std::cout << "Master is missing at cargo ship." << std::endl;
							break;
						}
					}
				}
				break;
			}
			case 4: {
				menuButton = 0;
				std::cout << "Thank you. Goodbye!" << std::endl;
				break;
			}
		menuButton = 1;
		}
	}
}