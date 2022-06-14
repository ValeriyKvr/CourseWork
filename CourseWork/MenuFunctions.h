#pragma once
#include "OrdinaryShip.h"
#include "PassengerShip.h"
#include "CargoShip.h"
#include <iostream>
#include <string>
#include <vector>

void createCrewMember(std::vector<CrewMember>& crewMembers, int crewNumber);

OrdinaryShip createShip();
PassengerShip createPassengerShip();
CargoShip createCargoShip();

void modShip(std::vector<OrdinaryShip>& ship);
void modPassengerShip(std::vector<PassengerShip>& pasShip);
void modCargoShip(std::vector<CargoShip>& cargoShip);

void printShips(std::vector<OrdinaryShip>* ship, std::vector<PassengerShip>* passengerShip, std::vector<CargoShip>* cargoShip);