#include "habitat.h"

habitat::habitat(float Surface, string Species_living_in_habitat, int Number_of_living_animals, vector<string> Names_of_living_animals, vector<int> Numbers_of_chips_of_living_animals, string Type_of_habitat, vector<string> Notes_for_habitat) {
	surface = Surface;
	species_living_in_habitat = Species_living_in_habitat;
	number_of_living_animals = Number_of_living_animals;
	names_of_living_animals = Names_of_living_animals;
	numbers_of_chips_of_living_animals = Numbers_of_chips_of_living_animals;
	type_of_habitat = Type_of_habitat;
	notes_for_habitat = Notes_for_habitat;
}
