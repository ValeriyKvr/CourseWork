#pragma once
#include <string>

enum class CrewMemberRank {
	Master,
	ChiefEngineer,
	Sailor,
	Cook
};

class CrewMember {
	CrewMemberRank rank;
	std::string fullname;
	int crewMemberAge, workExperience;
public:
	CrewMember(std::string fN, CrewMemberRank r, int cMA, int wE);
	void changeRank(CrewMemberRank r);

	CrewMemberRank getRank() const;
	std::string getFullname() const;
	int getAge() const;
	int getWorkExp() const;
};
