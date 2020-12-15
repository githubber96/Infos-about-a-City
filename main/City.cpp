#include "City.h"
#include "Table.h"
#include <fstream>
#include <iostream>
#include <algorithm> 
#include <cctype>

std::string choseCity()
{
	std::string input;

	std::vector<std::string> cities{ "Munich", "Berlin", "Hamburg", "Bremen", "Barcelona" };
	while (!(find(begin(cities), end(cities), input) != end(cities)))
	{
		std::cout << "Chose your city from the following: Munich, Berlin, Hamburg, Bremen, Barcelona." << std::endl;
		std::cin >> input;
		transform(begin(input), end(input), begin(input), tolower);
		if (!input.empty())
		{
			input[0] = toupper(input[0]);
		}
	}
	return input;
}

City::City(std::string name) :
	m_name(name)
{
	auto path = name + ".txt";
	loadInfo(path);
}

std::string City::getName()
{	
	return m_name;
}

std::string City::getFootballclub(bool print)
{
	if (print)
	{
		std::cout << "\n" << m_footballClub << "\n" << std::endl;
	}
	return m_footballClub;
}

void City::printTable()
{
	VariadicTable<std::string, int> vt({ "District", "Residents"});
	int sum = 0;
	for (int i = 0; i < m_districts.size(); i++)
	{
		sum += m_districts[i].population;
		std::cout.imbue(std::locale(""));		//converts number into local reading format
		vt.addRow(m_districts[i].name, m_districts[i].population);
	}
	vt.print(std::cout);
	std::cout << "\n" << m_name << " has " << sum << " residents" << std::endl;
}

void City::loadInfo(std::string path)
{
	//LOAD DISTRICTS
	std::ifstream file(path, std::ios::in);
	std::string temp;
	while (std::getline(file, temp, '\n'))
	{
		District d;
		d.name = temp.substr(0, temp.find('\t'));
		d.population = stoi(temp.substr(temp.find('\t') + 1));
		m_districts.push_back(d);
		//m_population
	}

	//LOAD FOOTBALL CLUB
	if (m_name == "Munich")
	{
		m_footballClub = "Munich has two major football clubs: TSV 1860 and FC Bayern Muenchen";
	}
	if (m_name == "Hamburg")
	{
		m_footballClub = "Hamburg has two major football clubs: Hamburger SV and 1.FC St. Pauli";
	}
	if (m_name == "Berlin")
	{
		m_footballClub = "Berlin has two major football clubs: Hertha BSC and Union Berlin";
	}
	if (m_name == "Bremen")
	{
		m_footballClub = "Bremen has one major football club: SV Werder Bremen";
	}
	if (m_name == "Barcelona")
	{
		m_footballClub = "Barcelona has two major football clubs: FC Barcelona and Espanyol Barcelona";
	}
}
