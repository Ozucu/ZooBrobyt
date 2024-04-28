#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include<sstream>
#include "habitat.h"
using namespace std;

class Animal
{
	string cluster;
	string kind;
	string name;
	int age;
	string date_of_last_feeding;
	float weight;
	string date_of_arrival_to_zoo;
	string in_which_habitat;
	int chip_number;
	string is_animal_healthy;
	vector <string> health_booklet;

	friend class Habitat;


public:
	Animal(string = "unknown", string = "unknown", string = "unknown", int = 0, string = "unknown", float = 0, string = "unknown", string = "unknown", int = 0, string = "YES", vector<string> = {});
	string will_animal_get_sick(int age, float weight, vector<string> health_booklet);
	virtual void display_animal_info();
	

};

class Animal_vector
{
	vector<unique_ptr<Animal>> list_of_animals;
public:
	Animal_vector(vector<unique_ptr<Animal>> = {});
	void load_animal_data(string FileName);
	void display_all_animals();
	void add_animal_to_animal_vector(Habitat_vector& list_of_habitats);
};

class Reptile :public Animal
{

public:
	Reptile(string = "unknown", string = "unknown", string = "unknown", int = 0, string = "unknown", float = 0, string = "unknown", string = "unknown", int = 0, string = "YES", vector<string> = {});
	virtual void display_animal_info();

};

class Mammal :public Animal
{
public:
	Mammal(string = "unknown", string = "unknown", string = "unknown", int = 0, string = "unknown", float = 0, string = "unknown", string = "unknown", int = 0, string = "YES", vector<string> = {});
	virtual void display_animal_info();

};

class Amphibian :public Animal
{
public:
	Amphibian(string = "unknown", string = "unknown", string = "unknown", int = 0, string = "unknown", float = 0, string = "unknown", string = "unknown", int = 0, string = "YES", vector<string> = {});
	virtual void display_animal_info();

};

class Bird :public Animal
{
public:
	Bird(string = "unknown", string = "unknown", string = "unknown", int = 0, string = "unknown", float = 0, string = "unknown", string = "unknown", int = 0, string = "YES", vector<string> = {});
	virtual void display_animal_info();
};

class Fish :public Animal
{
	int amount_of_fish;
public:
	Fish(string = "unknown", string = "unknown", string = "unknown", int = 0, string = "unknown", float = 0, string = "unknown", string = "unknown", int = 0, string = "YES", vector<string> = {}, int = 0);
	virtual void display_animal_info();
};

class Invertebrate :public Animal
{
	int amount_of_invertebrate; // bezkrêgowców
	string type; //miêczak / stawonóg
	string subtype; // owad / pajêczak / skorupiak
public:
	Invertebrate(string = "unknown", string = "unknown", string = "unknown", int = 0, string = "unknown", float = 0, string = "unknown", string = "unknown", int = 0, string = "YES", vector<string> = {}, int = 0, string = "unknown", string = "unknown");
	virtual void display_animal_info();

};
