#include "animal.h"
Animal::Animal(string Cluster, string Kind, string Name, int Age, string Date_of_feeding, float Weight, string Date_of_arrival, string in_which, int Chip_number, string Is_animal_healthy, vector<string> Health_booklet) {
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
    cout << "\n\nCluster: " << cluster << "\nKind: " << kind << "\nName: " << name << "\nAge: " << age << "\nDate od last feeding: " << date_of_last_feeding << "\nWeight: " << weight << "kg\nHealth booklet: ";
    for (auto item : health_booklet) cout << item << " ";
    cout << "\nDate od arrival to zoo: " << date_of_arrival_to_zoo << "\nIn which habitat: " << in_which_habitat << "\nChip number: " << chip_number << "\nIs animal healthy: " << is_animal_healthy <<"\n";
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
                copy(data.begin() + 10, data.end(), back_inserter(booklet));
                list_of_animals.push_back(move(make_unique<Reptile>(data[0], data[1], data[2], stoi(data[3]), data[4], stoi(data[5]), data[6], data[7], stoi(data[8]), data[9], booklet)));

            }
            else if (data[0] == "Mammal") {
                vector<string> booklet;
                copy(data.begin() + 10, data.end(), back_inserter(booklet));
                list_of_animals.push_back(move(make_unique<Mammal>(data[0], data[1], data[2], stoi(data[3]), data[4], stoi(data[5]), data[6], data[7], stoi(data[8]), data[9], booklet)));

            }
            else if (data[0] == "Amphibian") {
                vector<string> booklet;
                copy(data.begin() + 10, data.end(), back_inserter(booklet));
                list_of_animals.push_back(move(make_unique<Amphibian>(data[0], data[1], data[2], stoi(data[3]), data[4], stoi(data[5]), data[6], data[7], stoi(data[8]), data[9], booklet)));

            }
            else if (data[0] == "Bird") {
                vector<string> booklet;
                copy(data.begin() + 9, data.end(), back_inserter(booklet));
                list_of_animals.push_back(move(make_unique<Bird>(data[0], data[1], data[2], stoi(data[3]), data[4], stoi(data[5]), data[6], data[7], stoi(data[8]), data[9], booklet)));

            }
            else if (data[0] == "Fish") {
                vector<string> booklet;
                copy(data.begin() + 11, data.end(), back_inserter(booklet));
                list_of_animals.push_back(move(make_unique<Fish>(data[0], data[1], data[2], stoi(data[3]), data[4], stoi(data[5]), data[6], data[7], stoi(data[8]), data[9], booklet, stoi(data[10]))));

            }
            else if (data[0] == "Invertebrate") {
                vector<string> booklet;
                copy(data.begin() + 13, data.end(), back_inserter(booklet));
                list_of_animals.push_back(move(make_unique<Invertebrate>(data[0], data[1], data[2], stoi(data[3]), data[4], stoi(data[5]), data[6], data[7], stoi(data[8]), data[9], booklet, stoi(data[10]), data[11], data[12])));

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
void Animal_vector::add_animal_to_animal_vector(Habitat_vector& list_of_habitats) {
    string cluster;
    string kind;
    string name;
    int age;
    string date_of_feeding;
    float weight;
    string date_of_arrival;
    string in_which;
    int chip_number;
    string is_animal_healthy;
    vector<string> health_booklet;
    string health_note = "1";
    cout << "\n\nCluster of animal: ";
    cin >> cluster;
    cout << "Kind: ";
    cin >> kind;
    cout << "Name: ";
    cin >> name;
    cout << "Age: ";
    cin >> age;
    cout << "Date od last feeding: ";
    cin >> date_of_feeding;
    cout << "Weight: ";
    cin >> weight;
    cout << "Date od arrival to zoo: ";
    cin >> date_of_arrival;
    cout << "In which habitat: ";
    cin >> in_which;
    cout << "Chip number: ";
    cin >> chip_number;
    cout << "Is animal healthy: ";
    cin >> is_animal_healthy;
    while (health_note != "0") {
        cout << "Health note (0 to end): ";
        cin >> health_note;
        health_booklet.push_back(health_note);
    }
    unique_ptr<Animal> animal;
    if (cluster == "Reptile") animal = make_unique<Reptile>(cluster, kind, name, age,date_of_feeding,weight,date_of_arrival,in_which,chip_number,is_animal_healthy,health_booklet);
    else if (cluster == "Mammal") animal = make_unique<Mammal>(cluster, kind, name, age, date_of_feeding, weight, date_of_arrival, in_which, chip_number, is_animal_healthy, health_booklet);
    else if (cluster == "Amphibian") animal = make_unique<Amphibian>(cluster, kind, name, age, date_of_feeding, weight, date_of_arrival, in_which, chip_number, is_animal_healthy, health_booklet);
    else if (cluster == "Bird") animal = make_unique<Bird>(cluster, kind, name, age, date_of_feeding, weight, date_of_arrival, in_which, chip_number, is_animal_healthy, health_booklet);
    else if (cluster == "Fish") {
        int amount_of_fish;
        cout << "Amount of fish: ";
        cin >> amount_of_fish;
        animal = make_unique<Fish>(cluster, kind, name, age, date_of_feeding, weight, date_of_arrival, in_which, chip_number, is_animal_healthy, health_booklet, amount_of_fish);
    }
    else if (cluster == "Invertebrate") {
        int amount_of_invertebrate;
        string type;
        string subtype;
        cout << "Amount of invertebrates: ";
        cin >> amount_of_invertebrate;
        cout << "Type: ";
        cin >> type;
        cout << "Subtype: ";
        cin >> subtype;
        animal = make_unique<Invertebrate>(cluster, kind, name, age, date_of_feeding, weight, date_of_arrival, in_which,chip_number, is_animal_healthy, health_booklet,amount_of_invertebrate, type, subtype);
    }
    else cerr << "Unknown type od animal.";
	list_of_animals.push_back(move(animal));
    list_of_habitats.add_animal_to_habitat_vector(name, chip_number, in_which);
    display_all_animals();

}
void Animal_vector::remove_animal_from_animal_vector(Habitat_vector& list_of_habitats) {
    int chip;
    cout << "Animal's chip ID: ";
    cin >> chip;

    for (auto animal = list_of_animals.begin(); animal != list_of_animals.end(); ++animal) {
        if ((*animal)->chip_number == chip) {
            // Remove animal from its habitat
            for (auto& habitat : list_of_habitats.list_of_habitats) {
                auto& names = habitat->names_of_living_animals;
                auto& chips = habitat->numbers_of_chips_of_living_animals;
                for (size_t i = 0; i < chips.size(); ++i) {
                    if (chips[i] == chip) {
                        names.erase(names.begin() + i);
                        chips.erase(chips.begin() + i);
                        habitat->number_of_living_animals--;
                        break;
                    }
                }
            }

            // Remove the animal from the list
            list_of_animals.erase(animal);
            cout << "Animal with chip " << chip << " removed from the vector." << endl;
            return;
        }
    }

    cerr << "No animal with chip " << chip << " found." << endl;

}
//---------------------------------------------------------------REPTILE-----------------------------------------------------------------------------
Reptile::Reptile(string Cluster, string Kind, string Name, int Age, string Date_of_feeding, float Weight, string Date_of_arrival, string in_which, int Chip_number, string Is_animal_healthy, vector<string> Health_booklet) : Animal(Cluster, Kind, Name, Age, Date_of_feeding, Weight, Date_of_arrival, in_which, Chip_number, Is_animal_healthy, Health_booklet) {

}
void Reptile::display_animal_info() {
    Animal::display_animal_info();

}
//---------------------------------------------------------------MAMMAL-------------------------------------------------------------------------------
Mammal::Mammal(string Cluster, string Kind, string Name, int Age, string Date_of_feeding, float Weight, string Date_of_arrival, string in_which, int Chip_number, string Is_animal_healthy, vector<string> Health_booklet) : Animal(Cluster, Kind, Name, Age, Date_of_feeding, Weight, Date_of_arrival, in_which, Chip_number, Is_animal_healthy, Health_booklet) {

}
void Mammal ::display_animal_info() {
    Animal::display_animal_info();
}

//---------------------------------------------------------------AMPHIBIAN----------------------------------------------------------------------------
Amphibian::Amphibian(string Cluster, string Kind, string Name, int Age, string Date_of_feeding, float Weight, string Date_of_arrival, string in_which, int Chip_number, string Is_animal_healthy, vector<string> Health_booklet) : Animal(Cluster, Kind, Name, Age, Date_of_feeding, Weight, Date_of_arrival, in_which, Chip_number, Is_animal_healthy, Health_booklet) {

}
void Amphibian::display_animal_info() {
    Animal::display_animal_info();
}
//---------------------------------------------------------------BIRD---------------------------------------------------------------------------------
Bird::Bird(string Cluster, string Kind, string Name, int Age, string Date_of_feeding, float Weight, string Date_of_arrival, string in_which, int Chip_number, string Is_animal_healthy, vector<string> Health_booklet) : Animal(Cluster, Kind, Name, Age, Date_of_feeding, Weight, Date_of_arrival, in_which, Chip_number, Is_animal_healthy, Health_booklet) {
   
}
void Bird::display_animal_info() {
    Animal::display_animal_info();
}

//---------------------------------------------------------------FISH---------------------------------------------------------------------------------
Fish::Fish(string Cluster, string Kind, string Name, int Age, string Date_of_feeding, float Weight, string Date_of_arrival, string in_which, int Chip_number, string Is_animal_healthy, vector<string> Health_booklet, int Amount_of_fish) : Animal(Cluster, Kind, Name, Age, Date_of_feeding, Weight, Date_of_arrival, in_which, Chip_number, Is_animal_healthy, Health_booklet) {
	amount_of_fish = Amount_of_fish;
}
void Fish::display_animal_info() {
    Animal::display_animal_info();
    cout << "Amount of fish: " << amount_of_fish << "\n";
}
//---------------------------------------------------------------INVERTEBRATE-------------------------------------------------------------------------
Invertebrate::Invertebrate(string Cluster, string Kind, string Name, int Age, string Date_of_feeding, float Weight, string Date_of_arrival, string in_which, int Chip_number, string Is_animal_healthy, vector<string> Health_booklet, int Amount_of_invertebrate, string Type, string Subtype) : Animal(Cluster, Kind, Name, Age, Date_of_feeding, Weight, Date_of_arrival, in_which, Chip_number, Is_animal_healthy, Health_booklet) {
	amount_of_invertebrate = Amount_of_invertebrate;
	type = Type;
	subtype = Subtype;
}
void Invertebrate::display_animal_info() {
    Animal::display_animal_info();
    cout << "Amount of inverrtebrates: " << amount_of_invertebrate << "\nType: " << type << "\nSubtype: " << subtype << "\n\n";
}


