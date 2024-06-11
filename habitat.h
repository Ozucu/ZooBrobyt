#pragma once
#include <iostream>
#include<fstream>
#include<sstream>
#include <vector>
#include "animal.h"
using namespace std;

class Animal;

class Habitat
{
protected:
	float surface;
	string species_living_in_habitat;
	int number_of_living_animals;
	vector<string> names_of_living_animals;
	vector<int> numbers_of_chips_of_living_animals;
	string type_of_habitat;
	vector<string> notes_for_habitat;

	friend class Habitat_vector;
	friend class Animal_vector;

public:
	Habitat(float = 0, string = "unknown", int = 0, vector<string> = {}, vector<int> = {}, string = "unknown", vector<string> = {});
	void display_habitat_info();

	//void remove_animal();
	//void move_animal();

};
class Habitat_vector
{
	vector<unique_ptr<Habitat>> list_of_habitats;
	friend class Animal_vector;
	friend class Director_of_the_zoo;

public:
	void load_habitat_data(string FileName);
	void display_all_habitats_info();
	void add_animal_to_habitat_vector(string name, int chip, string in_which);
};

