#pragma once
#include "OrdinaryShip.h"
#include "PassengerShip.h"
#include "CargoShip.h"
#include "CrewMember.h"
#include <iostream>
#include <string>
#include <vector>

void createCrewMember(std::vector<CrewMember>& crewMembers, int crewNumber);

Ship createShip();
PassengerShip createPassengerShip();
CargoShip createCargoShip();

void modShip(std::vector<Ship>& ship);
void modPassengerShip(std::vector<PassengerShip>& pasShip);
void modCargoShip(std::vector<CargoShip>& cargoShip);

void printShip(std::vector<Ship>* ship, std::vector<PassengerShip>* passengerShip, std::vector<CargoShip>* cargoShip);