#pragma once
#include <iostream>
#include<fstream>
#include<sstream>
#include <vector>
using namespace std;
class Habitat
{
	float surface;
	string species_living_in_habitat;
	int number_of_living_animals;
	vector<string> names_of_living_animals;
	vector<int> numbers_of_chips_of_living_animals;
	string type_of_habitat;
	vector<string> notes_for_habitat;

public:
	Habitat(float = 0, string = "unknown", int = 0, vector<string> = {}, vector<int> = {}, string = "unknown", vector<string> = {});
	void display_habitat_info();
	void add_animal();
	void remove_animal();
	void move_animal();

};
class Habitat_vector
{
	vector<unique_ptr<Habitat>> list_of_habitats;
	friend class Habitat;
public:
	void load_habitat_data(string FileName);
	void display_all_habitats_info();

};

