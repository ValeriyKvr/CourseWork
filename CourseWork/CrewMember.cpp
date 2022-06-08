#include "CrewMember.h"
#include <stdexcept>

CrewMember::CrewMember(std::string fn, CrewMemberRank r, int cMA, int wE) {
	if (workExperience < 0) throw std::invalid_argument("Work experience cannot be < 0");
	fullname = fn, rank = r, crewMemberAge = cMA, workExperience = wE;
}
void CrewMember::changeRank(CrewMemberRank r) { rank = r; }
CrewMemberRank CrewMember::getRank() const { return rank; }