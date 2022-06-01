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
		std::cout << "3) Exit." << std::endl;
		std::cin >> menuButton;
		std::cout << std::endl;
		switch (menuButton) {
			case 1: {
				int typeOfShip;
				std::cout << "What type of ship do you want to create?" << std::endl;
				std::cout << "0) Ordinary ship." << "\n" << "1) Passenger ship." << "\n" << "2) Cargo ship." << std::endl;
				std::cin >> typeOfShip;
				if (typeOfShip == 0) {
					ship.push_back(createShip());
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
				menuButton = 0;
				std::cout << "Exit" << std::endl;
				break;
			}
		menuButton = 1;
		}
	}
}