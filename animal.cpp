#include "animal.h"
Animal::Animal(string Species, string Kind, string Name, int Age, string Date_of_feeding, float Weight, vector<string> Health_booklet, string Date_of_arrival, string in_which, int Chip_number) {
	species = Species;
	kind = Kind;
	name = Name;
	age = Age;
	date_of_last_feeding = Date_of_feeding;
	weight = Weight;
	health_booklet = Health_booklet;
	date_of_arrival_to_zoo = Date_of_arrival;
	in_which_habitat = in_which;
	chip_number = Chip_number;
}

void Animal::dispaly_animal_info() {
	cout << endl << kind;
}
