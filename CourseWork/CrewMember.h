#pragma once
#include <string>

enum class CrewMemberRank {
	Master,
	MasterAssistant,
	ChiefEngineer,
	EngineerAssistant,
	Sailor,
	Cook,
	Doctor
};

class CrewMember {
	CrewMemberRank rank;
	std::string fullname;
	int crewMemberAge, workExperience;
public:
	CrewMember(std::string fn, CrewMemberRank r, int cMA, int wE);
	void changeRank(CrewMemberRank r);
	CrewMemberRank getRank() const;
	std::string getFullname() const;
	int getAge() const;
	int getWorkExp() const;
};

