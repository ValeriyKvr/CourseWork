#include <iostream>
#include "MenuFunctions.h"

int main() {
	std::vector<Ship> ship;
	std::vector<PassengerShip> passengerShip;
	std::vector<CargoShip> cargoShip;
	int menuButton = 1;
	while (menuButton) {
		std::cout << "Choose number: " << std::endl;
		std::cout << "0) Create ship. " << std::endl;
		std::cout << "1) Exit." << std::endl;
		std::cin >> menuButton;
		std::cout << std::endl;
		switch (menuButton) {
			case 0: {
				int typeOfShip;
				std::cout << "What type of ship do you want to create?" << std::endl;
				std::cout << "0) Ordinary ship." << "\n" << "1) Passenger ship." << "\n" << "2) Cargo ship." << std::endl;
				std::cin >> typeOfShip;
				if (typeOfShip == 0) ship.push_back(createShip());
			}
				
		}
	}
	try {

	}
	catch (std::invalid_argument ia) {
		std::cout << ia.what() << std::endl;
	}
}