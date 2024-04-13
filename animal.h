#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include<sstream>
using namespace std;

class Animal
{
	string cluster;
	string kind;
	string name;
	int age;
	string date_of_last_feeding;
	float weight;
	vector <string> health_booklet;
	string date_of_arrival_to_zoo;
	string in_which_habitat;
	int chip_number;
	bool is_animal_healthy;

public:
	Animal(string = "unknown", string = "unknown", string = "unknown", int = 0, string = "unknown", float = 0, vector<string> = {}, string = "unknown", string = "unknown", int = 0, bool = true);
	bool will_animal_get_sick(int age, float weight, vector<string> health_booklet);
	virtual void display_animal_info();
	

};

class Animal_vector
{
	vector<unique_ptr<Animal>> list_of_animals;
public:
	Animal_vector(vector<unique_ptr<Animal>> = {});
	void load_animal_data(string FileName);
	void display_all_animals();
	void add_animal(unique_ptr<Animal> animal);
};

class Reptile :public Animal
{

public:
	Reptile(string = "unknown", string = "unknown", string = "unknown", int = 0, string = "unknown", float = 0, vector<string> = {}, string = "unknown", string = "unknown", int = 0);
	virtual void display_animal_info();

};

class Mammal :public Animal
{
public:
	Mammal(string = "unknown", string = "unknown", string = "unknown", int = 0, string = "unknown", float = 0, vector<string> = {}, string = "unknown", string = "unknown", int = 0);
	virtual void display_animal_info();

};

class Amphibian :public Animal
{
public:
	Amphibian(string = "unknown", string = "unknown", string = "unknown", int = 0, string = "unknown", float = 0, vector<string> = {}, string = "unknown", string = "unknown", int = 0);
	virtual void display_animal_info();

};

class Bird :public Animal
{
public:
	Bird(string = "unknown", string = "unknown", string = "unknown", int = 0, string = "unknown", float = 0, vector<string> = {}, string = "unknown", string = "unknown", int = 0);
	virtual void display_animal_info();
};

class Fish :public Animal
{
	int amount_of_fish;
public:
	Fish(string = "unknown", string = "unknown", string = "unknown", int = 0, string = "unknown", float = 0, vector<string> = {}, string = "unknown", string = "unknown", int = 0, int = 0);
	virtual void display_animal_info();
};

class Invertebrate :public Animal
{
	int amount_of_invertebrate; // bezkrêgowców
	string type; //miêczak / stawonóg
	string subtype; // owad / pajêczak / skorupiak
public:
	Invertebrate(string = "unknown", string = "unknown", string = "unknown", int = 0, string = "unknown", float = 0, vector<string> = {}, string = "unknown", string = "unknown", int = 0, int = 0, string = "unknown", string = "unknown");
	virtual void display_animal_info();

};
