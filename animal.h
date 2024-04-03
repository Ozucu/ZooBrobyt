#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Animal
{
	string species;
	string kind;
	string name;
	int age;
	string date_of_last_feeding;
	float weight;
	vector <string> health_booklet;
	string date_of_arrival_to_zoo;
	string in_which_habitat;
	int chip_number;

public:
	Animal(string = "unknown", string = "unknown", string = "unknown", int = 0, string = "unknown", float = 0, vector<string> = {}, string = "unknown", string = "unknown", int = 0);
	void load_animal_data(string FileName);
	bool will_animal_get_sick(int age, float weight, vector<string> health_booklet);
	virtual void display_animal_info();
	

};

class Animal_vector
{
	vector<unique_ptr<Animal>> animal_vector;
public:
	void add_animal(unique_ptr<Animal> animal);
};

class Reptile :public Animal
{
	string test;
public:
	Reptile(string = "unknown", string = "unknown", string = "unknown", int = 0, string = "unknown", float = 0, vector<string> = {}, string = "unknown", string = "unknown", int = 0, string = {});
	virtual void display_animal_info();

};

