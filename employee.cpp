#include "employee.h"

Employee::Employee(string Name, string Last_name, string Date_of_birth, string Date_of_employment, string Position, int ID_Number_of_employee) {
	name = Name;
	last_name = Last_name;
	date_of_birth = Date_of_birth;
	date_of_employment = Date_of_employment;
	position = Position;
	ID_number_of_employee = ID_Number_of_employee;
}
Director_of_the_zoo::Director_of_the_zoo(string Name, string Last_name, string Date_of_birth, string Date_of_employment, string Position, int ID_Number_of_employee) : Employee(Name, Last_name, Date_of_birth, Date_of_employment, Position, ID_Number_of_employee) {

}
Manager_of_the_zoo::Manager_of_the_zoo(string Name, string Last_name, string Date_of_birth, string Date_of_employment, string Position, int ID_Number_of_employee, string Specialization) : Employee(Name, Last_name, Date_of_birth, Date_of_employment, Position, ID_Number_of_employee) {
    specialization = Specialization;
}
Zookeeper::Zookeeper(string Name, string Last_name, string Date_of_birth, string Date_of_employment, string Position, int ID_Number_of_employee, string Specialization, vector<string> Animal_under_care) : Employee(Name, Last_name, Date_of_birth, Date_of_employment, Position, ID_Number_of_employee) {
    specialization = Specialization;
    animal_under_care = Animal_under_care;
}
Vet::Vet(string Name, string Last_name, string Date_of_birth, string Date_of_employment, string Position, int ID_Number_of_employee, string Specialization) : Employee(Name, Last_name, Date_of_birth, Date_of_employment, Position, ID_Number_of_employee) {
    specialization = Specialization;
}

void Employee::display_employee_info() {
	cout <<"\nName: " << name << "\nLast name: " << last_name << "\nDate of birth: " << date_of_birth << "\n Date od employment: " << date_of_employment << "\nPosition: " << position << "\nID number: " << ID_number_of_employee;
}

void Employee_vector::load_employee_data(string FileName) {
    ifstream file(FileName); // Otwórz plik
    if (!file.is_open()) {
        cerr << "Nie mo¿na otworzyæ pliku." << endl;
        return;
    }

    string line;
    getline(file, line);
    while (getline(file, line)) { // Wczytaj linie z pliku
        stringstream ss(line);
        string token;
        vector<string> data;
        while (getline(ss, token, ';')) {
            data.push_back(token);
        }

        // SprawdŸ typ pracownika i utwórz odpowiedni obiekt
        if (data.size() > 0) {
            if (data[4] == "Director") {
 //               list_of_employees.push_back(Director_of_the_zoo(data[1], data[2], data[3], data[4], data[5], stoi(data[6])));
            }
            else if (data[4] == "Manager") {
                list_of_employees.push_back(Manager_of_the_zoo(data[0], data[1], data[2], data[3], data[4], stoi(data[5]), data[6]));
            }
            else if (data[4] == "Zookeeper") {
 //               list_of_employees.push_back(Zookeeper(data[1], data[2], data[3], data[4], data[5], data[6], vector<string>(), stoi(data[7])));
            }
            else if (data[4] == "Vet") {
 //               list_of_employees.push_back(Vet(data[1], data[2], data[3], data[4], data[5], data[6], stoi(data[7])));
            }
            else {
                cerr << "Nieznany typ pracownika." << endl;
            }
        }
    }

    file.close(); // Zamknij plik
}
void Employee_vector::display_all_employees() {
    for (auto& employee : list_of_employees) {
        employee.display_employee_info();
    }

}

//-------------------------------------------------------- DIRECTOR ---------------------------------------------------------------

//-------------------------------------------------------- MANAGER ----------------------------------------------------------------
/*
void Manager_of_the_zoo::display_tasks() {
	system("cls");
	cout << "As an maganger you can :\n1. Move an animal on other habitat.\n2. Display stock status.\n3. Replain goods in warehouse\n";
}

void Manager_of_the_zoo::display_employee_menu() {
	display_tasks();
	int number_of_task = 0;
	cout << "Choose number of task from listed above: ";
	if (number_of_task == 1) move_animal();
	else if (number_of_task == 2) display_warehouse_info();
	else if (number_of_task == 3) replain_warehouse();
	else cout << "Wrong number of task / no number picked";
}
*/
void Manager_of_the_zoo::move_animal() {
//	display_habitat_info();
}
void Manager_of_the_zoo::replain_warehouse() {

}
//-------------------------------------------------------- ZOOKEPER ----------------------------------------------------------------

//---------------------------------------------------------- VET -------------------------------------------------------------------