#include "animal.h"
Animal::Animal(string Species, string Kind, string Name, int Age, string Date_of_feeding, float Weight, vector<string> Health_booklet, string Date_of_arrival, string in_which, int Chip_number, bool Is_animal_healthy) {
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
	is_animal_healthy = Is_animal_healthy;
}

void Animal::display_animal_info() {
	
}
Animal_vector::Animal_vector(vector<unique_ptr<Animal>> Animal_vector) {
	animal_vector = move(Animal_vector);
}
void Animal_vector::add_animal(unique_ptr<Animal> animal) {
	animal_vector.push_back(move(animal));
	for (const auto& animal_ptr : animal_vector) animal_ptr->display_animal_info();

}
//---------------------------------------------------------------REPTILE-----------------------------------------------------------------------------
Reptile::Reptile(string Species, string Kind, string Name, int Age, string Date_of_feeding, float Weight, vector<string> Health_booklet, string Date_of_arrival, string in_which, int Chip_number, string Test) : Animal(Species, Kind, Name, Age, Date_of_feeding, Weight, Health_booklet, Date_of_arrival, in_which, Chip_number) {
	test = Test;
}
void Reptile::display_animal_info() {
	
}
//---------------------------------------------------------------MAMMAL-------------------------------------------------------------------------------
Mammal::Mammal(string Species, string Kind, string Name, int Age, string Date_of_feeding, float Weight, vector<string> Health_booklet, string Date_of_arrival, string in_which, int Chip_number) : Animal(Species, Kind, Name, Age, Date_of_feeding, Weight, Health_booklet, Date_of_arrival, in_which, Chip_number) {

}

//---------------------------------------------------------------AMPHIBIAN----------------------------------------------------------------------------
Amphibian::Amphibian(string Species, string Kind, string Name, int Age, string Date_of_feeding, float Weight, vector<string> Health_booklet, string Date_of_arrival, string in_which, int Chip_number) : Animal(Species, Kind, Name, Age, Date_of_feeding, Weight, Health_booklet, Date_of_arrival, in_which, Chip_number) {

}

//---------------------------------------------------------------BIRD---------------------------------------------------------------------------------
Bird::Bird(string Species, string Kind, string Name, int Age, string Date_of_feeding, float Weight, vector<string> Health_booklet, string Date_of_arrival, string in_which, int Chip_number) : Animal(Species, Kind, Name, Age, Date_of_feeding, Weight, Health_booklet, Date_of_arrival, in_which, Chip_number) {

}

//---------------------------------------------------------------FISH---------------------------------------------------------------------------------
Fish::Fish(string Species, string Kind, string Name, int Age, string Date_of_feeding, float Weight, vector<string> Health_booklet, string Date_of_arrival, string in_which, int Chip_number, int Amount_of_fish) : Animal(Species, Kind, Name, Age, Date_of_feeding, Weight, Health_booklet, Date_of_arrival, in_which, Chip_number) {
	amount_of_fish = Amount_of_fish;
}

//---------------------------------------------------------------INVERTEBRATE-------------------------------------------------------------------------
Invertebrate::Invertebrate(string Species, string Kind, string Name, int Age, string Date_of_feeding, float Weight, vector<string> Health_booklet, string Date_of_arrival, string in_which, int Chip_number, int Amount_of_invertebrate, string Type, string Subtype) : Animal(Species, Kind, Name, Age, Date_of_feeding, Weight, Health_booklet, Date_of_arrival, in_which, Chip_number) {
	amount_of_invertebrate = Amount_of_invertebrate;
	type = Type;
	subtype = Subtype;
}


