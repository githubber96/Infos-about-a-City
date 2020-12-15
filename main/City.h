#pragma once

#include <string>
#include <vector>

std::string choseCity();

struct District
{
	std::string name;
	int population = 0;
};

class City
{
public:
	City(std::string name);
	std::string getName();
	std::string getFootballclub(bool print = false);
	void printTable();
	void printTableOfEveryCity();

private:
	void loadInfo(std::string path);
	std::string m_name;
	std::string m_footballClub;
	std::vector<District> m_districts;
};
