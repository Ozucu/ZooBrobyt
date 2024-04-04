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

void Animal::display_animal_info() {
	cout << endl << kind;
}
Animal_vector::Animal_vector(vector<unique_ptr<Animal>> Animal_vector) {
	animal_vector = move(Animal_vector);
}
void Animal_vector::add_animal(unique_ptr<Animal> animal) {
	animal_vector.push_back(move(animal));
	for (const auto& animal_ptr : animal_vector) {
		animal_ptr->display_animal_info(); // U¿yj ->, aby uzyskaæ dostêp do metody display_animal_info()
	}
}
Reptile::Reptile(string Species, string Kind, string Name, int Age, string Date_of_feeding, float Weight, vector<string> Health_booklet, string Date_of_arrival, string in_which, int Chip_number, string Test) : Animal(Species, Kind, Name, Age, Date_of_feeding, Weight, Health_booklet, Date_of_arrival, in_which, Chip_number) {
	test = Test;

}
void Reptile::display_animal_info() {
	cout << "dziala lol";
}