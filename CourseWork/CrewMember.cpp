#include "CrewMember.h"
#include <stdexcept>

CrewMember::CrewMember(std::string fn, CrewMemberRank r, int cMA, int wE) {
	if (workExperience < 0) throw std::invalid_argument("Work experience cannot be < 0");
	fullname = fn, rank = r, crewMemberAge = cMA, workExperience = wE;
}

CrewMemberRank CrewMember::getRank() const { return rank; }
std::string CrewMember::getFullname() const { return fullname; }
int CrewMember::getAge() const { return crewMemberAge; }
int CrewMember::getWorkExp() const { return workExperience; }