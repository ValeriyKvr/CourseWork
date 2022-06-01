#include <iostream>
#include "MenuFunctions.h"

int main() {
	std::vector<Ship> ship;
	std::vector<PassengerShip> passengerShip;
	std::vector<CargoShip> cargoShip;
	int menuButton = 1;
	while (menuButton) {
		std::cout << "Choose number: " << std::endl;
		std::cout << "1) Create ship. " << std::endl;
		std::cout << "2) Show ships." << std::endl;
		std::cout << "3) Check Master." << std::endl;
		std::cout << "4) Exit." << std::endl;
		std::cin >> menuButton;
		std::cout << std::endl;
		switch (menuButton) {
			case 1: {
				int typeOfShip;
				std::cout << "What type of ship do you want to create?" << std::endl;
				std::cout << "1) Ordinary ship." << "\n" << "2) Passenger ship." << "\n" << "3) Cargo ship." << std::endl;
				std::cin >> typeOfShip;
				if (typeOfShip == 1) ship.push_back(createShip());
				if (typeOfShip == 2) passengerShip.push_back(createPassengerShip());
				if (typeOfShip == 3) cargoShip.push_back(createCargoShip());
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
			/*case 3: {
				if (ship.isMasterPresent()) {
					std::cout << "Master is present." << std::endl;
					break;
				}
				else {
					std::cout << "Master is missing." << std::endl;
					break;
				}
			}*/
			case 4: {
				menuButton = 0;
				std::cout << "Exit" << std::endl;
				break;
			}
		menuButton = 1;
		}
	}
}