#include "animal.h"
Animal::Animal(string Cluster, string Kind, string Name, int Age, string Date_of_feeding, float Weight, vector<string> Health_booklet, string Date_of_arrival, string in_which, int Chip_number, bool Is_animal_healthy) {
	cluster = Cluster;
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
    cout << "Cluster: " << cluster << "\nKind: " << kind << "\nName: " << name << "\nAge: " << age << "\nDate od last feeding: " << date_of_last_feeding << "\nWeight: " << weight << " ";
    for (auto item : health_booklet) cout << item << " ";
    cout << "\nDate od arrival to zoo: " << date_of_arrival_to_zoo << "\nIn which habitat: " << in_which_habitat << "\nChip number: " << chip_number << "\nIs animal healthy: " << is_animal_healthy << "\n";
}
//---------------------------------------------------------------ANIMAL VECTOR-----------------------------------------------------------------------------
Animal_vector::Animal_vector(vector<unique_ptr<Animal>> List_of_animals) {
	list_of_animals = move(List_of_animals);
}
void Animal_vector::load_animal_data(string FileName) {
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
        vector<string> data;
        while (getline(ss, token, ';')) {
            data.push_back(token);
        }
        if (data.size() > 0) {
            if (data[0] == "Reptile") {
                vector<string> booklet;
                copy(data.begin() + 9, data.end(), back_inserter(booklet));
                list_of_animals.push_back(move(make_unique<Reptile>(data[0], data[1], data[2], stoi(data[3]), data[4], stoi(data[5]), booklet, data[6], data[7], stoi(data[8]))));

            }
            else if (data[0] == "Mammal") {
                vector<string> booklet;
                copy(data.begin() + 9, data.end(), back_inserter(booklet));
                list_of_animals.push_back(move(make_unique<Mammal>(data[0], data[1], data[2], stoi(data[3]), data[4], stoi(data[5]), booklet, data[6], data[7], stoi(data[8]))));

            }
            else if (data[0] == "Amphibian") {
                vector<string> booklet;
                copy(data.begin() + 9, data.end(), back_inserter(booklet));
                list_of_animals.push_back(move(make_unique<Amphibian>(data[0], data[1], data[2], stoi(data[3]), data[4], stoi(data[5]), booklet, data[6], data[7], stoi(data[8]))));

            }
            else if (data[0] == "Bird") {
                vector<string> booklet;
                copy(data.begin() + 9, data.end(), back_inserter(booklet));
                list_of_animals.push_back(move(make_unique<Bird>(data[0], data[1], data[2], stoi(data[3]), data[4], stoi(data[5]), booklet, data[6], data[7], stoi(data[8]))));

            }
            else if (data[0] == "Fish") {
                vector<string> booklet;
                copy(data.begin() + 8, data.end(), back_inserter(booklet));
                list_of_animals.push_back(move(make_unique<Fish>(data[0], data[1], data[2], stoi(data[3]), data[4], stoi(data[5]), booklet, data[6], data[7], stoi(data[8]), data[9])));

            }
            else if (data[0] == "Invertebrate") {
                vector<string> booklet;
                copy(data.begin() + 12, data.end(), back_inserter(booklet));
                list_of_animals.push_back(move(make_unique<Invertebrate>(data[0], data[1], data[2], stoi(data[3]), data[4], stoi(data[5]), booklet, data[6], data[7], stoi(data[8]), data[9], data[10], data[11])));

            }
           
            else
                cerr << "Nieznany typ zwierzecia." << endl;
        }
    }


    file.close();
}
void Animal_vector::display_all_animals() {
    for (auto& animal : list_of_animals) animal->display_animal_info();
}
void Animal_vector::add_animal(unique_ptr<Animal> animal) {
	list_of_animals.push_back(move(animal));
	for (const auto& animal_ptr : list_of_animals) animal_ptr->display_animal_info();

}
//---------------------------------------------------------------REPTILE-----------------------------------------------------------------------------
Reptile::Reptile(string Cluster, string Kind, string Name, int Age, string Date_of_feeding, float Weight, vector<string> Health_booklet, string Date_of_arrival, string in_which, int Chip_number) : Animal(Cluster, Kind, Name, Age, Date_of_feeding, Weight, Health_booklet, Date_of_arrival, in_which, Chip_number) {

}
void Reptile::display_animal_info() {
    Animal::display_animal_info();

}
//---------------------------------------------------------------MAMMAL-------------------------------------------------------------------------------
Mammal::Mammal(string Cluster, string Kind, string Name, int Age, string Date_of_feeding, float Weight, vector<string> Health_booklet, string Date_of_arrival, string in_which, int Chip_number) : Animal(Cluster, Kind, Name, Age, Date_of_feeding, Weight, Health_booklet, Date_of_arrival, in_which, Chip_number) {

}
void Mammal ::display_animal_info() {

}

//---------------------------------------------------------------AMPHIBIAN----------------------------------------------------------------------------
Amphibian::Amphibian(string Cluster, string Kind, string Name, int Age, string Date_of_feeding, float Weight, vector<string> Health_booklet, string Date_of_arrival, string in_which, int Chip_number) : Animal(Cluster, Kind, Name, Age, Date_of_feeding, Weight, Health_booklet, Date_of_arrival, in_which, Chip_number) {

}
void Amphibian::display_animal_info() {

}
//---------------------------------------------------------------BIRD---------------------------------------------------------------------------------
Bird::Bird(string Cluster, string Kind, string Name, int Age, string Date_of_feeding, float Weight, vector<string> Health_booklet, string Date_of_arrival, string in_which, int Chip_number) : Animal(Cluster, Kind, Name, Age, Date_of_feeding, Weight, Health_booklet, Date_of_arrival, in_which, Chip_number) {

}
void Bird::display_animal_info() {

}

//---------------------------------------------------------------FISH---------------------------------------------------------------------------------
Fish::Fish(string Cluster, string Kind, string Name, int Age, string Date_of_feeding, float Weight, vector<string> Health_booklet, string Date_of_arrival, string in_which, int Chip_number, int Amount_of_fish) : Animal(Cluster, Kind, Name, Age, Date_of_feeding, Weight, Health_booklet, Date_of_arrival, in_which, Chip_number) {
	amount_of_fish = Amount_of_fish;
}
void Fish::display_animal_info() {
    Animal::display_animal_info();
    cout << "Amount of fish: " << amount_of_fish << "\n";
}
//---------------------------------------------------------------INVERTEBRATE-------------------------------------------------------------------------
Invertebrate::Invertebrate(string Cluster, string Kind, string Name, int Age, string Date_of_feeding, float Weight, vector<string> Health_booklet, string Date_of_arrival, string in_which, int Chip_number, int Amount_of_invertebrate, string Type, string Subtype) : Animal(Cluster, Kind, Name, Age, Date_of_feeding, Weight, Health_booklet, Date_of_arrival, in_which, Chip_number) {
	amount_of_invertebrate = Amount_of_invertebrate;
	type = Type;
	subtype = Subtype;
}
void Invertebrate::display_animal_info() {

}


