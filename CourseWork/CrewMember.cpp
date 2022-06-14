#include "CrewMember.h"
#include <stdexcept>
#include <iostream>

CrewMember::CrewMember(std::string fn, CrewMemberRank r, int cMA, int wE) {
	fullname = fn, rank = r, crewMemberAge = cMA, workExperience = wE;
}

CrewMemberRank CrewMember::getRank() const { return rank; }
std::string CrewMember::getFullname() const { return fullname; }
int CrewMember::getAge() const { return crewMemberAge; }
int CrewMember::getWorkExp() const { return workExperience; }

void CrewMember::setRank(const CrewMemberRank& r) { rank = r; }
