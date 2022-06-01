#pragma once
#include "Ship.h"
#include "PassengerShip.h"
#include "CargoShip.h"
#include "CrewMember.h"
#include <iostream>
#include <string>
#include <vector>

Ship createShip();

void printShip(std::vector<Ship>* ship, std::vector<PassengerShip>* passengerShip, std::vector<CargoShip>* cargoShip);
