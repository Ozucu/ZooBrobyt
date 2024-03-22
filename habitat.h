#pragma once
#include <iostream>
#include <vector>
using namespace std;
class habitat
{
	float surface;
	string species_living_in_habitat;
	int number_of_living_animals;
	vector<string> names_of_living_animals;
	vector<int> numbers_of_chips_of_living_animals;
	string type_of_habitat;
	vector<string> notes_for_habitat;

public:
	habitat(float = 0, string = "unknown", int = 0, vector<string> = {}, vector<int> = {}, string = "unknown", vector<string> = {});
	void load_habitat_data(string FileName);
	void display_habitat_info();

};

