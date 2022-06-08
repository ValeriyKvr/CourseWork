#pragma once
#include "OrdinaryShip.h"
#include "PassengerShip.h"
#include "CargoShip.h"
#include "CrewMember.h"
#include <iostream>
#include <string>
#include <vector>

Ship createShip();
PassengerShip createPassengerShip();
CargoShip createCargoShip();

void printShip(std::vector<Ship>* ship, std::vector<PassengerShip>* passengerShip, std::vector<CargoShip>* cargoShip);