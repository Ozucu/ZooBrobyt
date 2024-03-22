#pragma once
#include <iostream>
#include <vector>
using namespace std;

class animal
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
	animal(string = "unknown", string = "unknown", string = "unknown", int = 0, string = "unknown", float = 0, vector<string> = {}, string = "unknown", string = "unknown", int = 0);
	void load_animal_data(string FileName);
	bool will_animal_get_sick(int age, float weight, vector<string> health_booklet);
	void dispaly_animal_info();
	

};

