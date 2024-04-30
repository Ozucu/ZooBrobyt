#include "habitat.h"

Habitat::Habitat(float Surface, string Species_living_in_habitat, int Number_of_living_animals, vector<string> Names_of_living_animals, vector<int> Numbers_of_chips_of_living_animals, string Type_of_habitat, vector<string> Notes_for_habitat) {
	surface = Surface;
	species_living_in_habitat = Species_living_in_habitat;
	number_of_living_animals = Number_of_living_animals;
	names_of_living_animals = Names_of_living_animals;
	numbers_of_chips_of_living_animals = Numbers_of_chips_of_living_animals;
	type_of_habitat = Type_of_habitat;
	notes_for_habitat = Notes_for_habitat;
}
void Habitat::display_habitat_info() {
    cout << "Surface: " << surface << "\nSpecies living in habitat: " << species_living_in_habitat << "\nNames of animals: ";
    for (auto name_of_animal : names_of_living_animals) cout << name_of_animal << " ";
    cout << "\nAnimals chips: ";
    for (auto number : numbers_of_chips_of_living_animals) cout << number << " ";
    cout << "\nType of habitat: " << type_of_habitat << "\nNotes for habitat: ";
    for (auto note : notes_for_habitat) cout << note << " ";
}

void Habitat_vector::add_animal_to_habitat_vector(unique_ptr<Animal> new_animal) {
    if (!list_of_habitats.empty()) {
        // Pobranie wskaŸnika do pierwszego habitatu na liœcie
        Habitat* habitat_ptr = list_of_habitats[stoi(new_animal->in_which_habitat)].get();

        // Dodanie zwierzêcia do odpowiednich zmiennych sk³adowych wewn¹trz habitatu
        habitat_ptr->number_of_living_animals++;
        habitat_ptr->names_of_living_animals.push_back(new_animal->name);
        habitat_ptr->numbers_of_chips_of_living_animals.push_back(new_animal->chip_number);

        cout << "Animal added to habitat." << endl;
    }
    else {
        cerr << "No habitats available." << endl;
    }
}
void Habitat_vector::load_habitat_data(string FileName) {
    ifstream file(FileName);
    if (!file.is_open()) {
        cerr << "Nie mo¿na otworzyæ pliku." << endl;
        return;
    }

    string line;
    getline(file, line); // headline
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        int number_of_animals;
        vector<string> data;
        vector<string> names;
        vector <string> notes;
        vector<int> chip_numbers;
        while (getline(ss, token, ';')) {
            data.push_back(token);
        }
        if (data.size() > 0) {
            number_of_animals = stoi(data[2]);
            for (int i = 4; i < 4 + number_of_animals; i++) {
                names.push_back(data[i]);
                chip_numbers.push_back(stoi(data[i + number_of_animals]));
            }
            for (int i = 4 + 2 * number_of_animals; i < data.size(); i++) {
                notes.push_back(data[i]);
            }
        }
        list_of_habitats.push_back(move(make_unique<Habitat>(stof(data[0]), data[1], number_of_animals, names, chip_numbers, data[3], notes)));
    }

    file.close();
}
void Habitat_vector::display_all_habitats_info() {
    for (auto& habitat : list_of_habitats) habitat->display_habitat_info();
}
