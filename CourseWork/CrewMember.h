#pragma once
#include <vector>
#include <string>

enum class CrewMemberRank {
	Captain,
	CaptainAssistant,
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

	CrewMemberRank getRank() const;
	std::string getFullname() const;
	int getAge() const;
	int getWorkExp() const;

	void setRank(const CrewMemberRank& r);
};

