#include "employee.h"
//--------------------------------------------------------------EMPLOYEE-----------------------------------------------------------------------
Employee::Employee(string Name, string Last_name, string Date_of_birth, string Date_of_employment, string Position, int ID_Number_of_employee) {
	name = Name;
	last_name = Last_name;
	date_of_birth = Date_of_birth;
	date_of_employment = Date_of_employment;
	position = Position;
	ID_number_of_employee = ID_Number_of_employee;
}
void Employee::display_employee_info() {
    cout << "Name: " << name << "\nLast name: " << last_name << "\nDate of birth: " << date_of_birth << "\n Date od employment: " << date_of_employment << "\nPosition: " << position << "\nID number: " << ID_number_of_employee << "\n\n";
}
void Employee::display_warehouse_info() {

}
void Employee::get_stuff_from_warehouse() {

}
void Employee::display_habitat_info() {

}
void Employee::display_employee_menu() {}; // dodane przez to ¿e funkcje nie s¹ ju¿ czysto wirtualne
void Employee::display_tasks() {}; // dodane przez to ¿e funkcje nie s¹ ju¿ czysto wirtualne

//--------------------------------------------------------------EMPLOYEE VECTOR-----------------------------------------------------------------------
//Employee_vector::Employee_vector(vector<unique_ptr<Employee>> List_of_employees) { //kopiowanie obiektu (zawartoœci wektora)
//    list_of_employees = move(List_of_employees);
//}
Employee_vector::Employee_vector(vector<unique_ptr<Employee>>&& List_of_employees) //przenoszenie bez kopiowania (zawartoœci wektora)
    : list_of_employees(std::move(List_of_employees)) {
}
void Employee_vector::load_employee_data(string FileName) {

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
                    if (data[4] == "Director")
                        list_of_employees.push_back(move(make_unique<Director_of_the_zoo>(data[0], data[1], data[2], data[3], data[4], stoi(data[5]))));
                    else if (data[4] == "Manager")
                        list_of_employees.push_back(move(make_unique<Manager_of_the_zoo>(data[0], data[1], data[2], data[3], data[4], stoi(data[5]), data[6])));
                    else if (data[4] == "Zookeeper") {
                        vector<string> animals;
                        copy(data.begin() + 7, data.end(), back_inserter(animals));
                        list_of_employees.push_back(move(make_unique<Zookeeper>(data[0], data[1], data[2], data[3], data[4], stoi(data[5]), data[6], animals)));
                    }
                    else if (data[4] == "Vet")
                        list_of_employees.push_back(move(make_unique<Vet>(data[0], data[1], data[2], data[3], data[4], stoi(data[5]))));
                    else
                        cerr << "Nieznany typ pracownika." << endl;
                }
            }
        
    
    file.close();
    
}
void Employee_vector::display_all_employees() {
    for (auto& employee : list_of_employees) employee -> display_employee_info();
}
void Employee_vector::add_employee(unique_ptr<Employee> employee) {
    list_of_employees.push_back(move(employee));
}
void Employee_vector::remove_employee(size_t index) {
    if (index >= list_of_employees.size()) {
        std::cerr << "Index out of range." << std::endl;
        return;
    }
    list_of_employees.erase(list_of_employees.begin() + index);
}

//-------------------------------------------------------- DIRECTOR ---------------------------------------------------------------
Director_of_the_zoo::Director_of_the_zoo(string Name, string Last_name, string Date_of_birth, string Date_of_employment, string Position, int ID_Number_of_employee) : Employee(Name, Last_name, Date_of_birth, Date_of_employment, Position, ID_Number_of_employee) {

}
void Director_of_the_zoo::display_employee_menu(Employee_vector list_of_employees) {
    int choice = 1;
    while (choice != 0) {
        display_tasks();
        cout << "Your choice (0 to escape): ";
        cin >> choice;
        if (choice == 1) {
            string name;
            string last_name;
            string date_of_birth;
            string date_of_employment;
            string position;
            int ID_number_of_employee;
            string specialization;
            vector<string> animal_under_care;
            cout << "Name: "; cin >> name;
            cout << "Last Name: "; cin >> last_name;
            cout << "Date od birth: "; cin >> date_of_birth;
            cout << "Date od employment: "; cin >> date_of_employment;
            cout << "Position: "; cin >> position;
            cout << "ID number: "; cin >> ID_number_of_employee;
            if (position != "Director") {
                cout << "Specialization: "; cin >> specialization;
            }
            if (position == "Zookeeper") {
                string animal = {};
                cout << "Animals under care (to end press 0): ";
                while (animal != "0") {
                    cin >> animal;
                    animal_under_care.push_back(animal);
                }
            }
            unique_ptr<Employee> new_employee;
            if (position == "Director") new_employee = make_unique<Director_of_the_zoo>(name, last_name, date_of_birth, date_of_employment, position, ID_number_of_employee);
            else if (position == "Manager") new_employee = make_unique<Manager_of_the_zoo>(name, last_name, date_of_birth, date_of_employment, position, ID_number_of_employee, specialization);
            else if (position == "Zookeeper") new_employee = make_unique<Zookeeper>(name, last_name, date_of_birth, date_of_employment, position, ID_number_of_employee, specialization, animal_under_care);
            else if (position == "Vet") new_employee = make_unique<Vet>(name, last_name, date_of_birth, date_of_employment, position, ID_number_of_employee, specialization);
            else cerr << "Wrong type of employee";


            list_of_employees.add_employee(move(new_employee));
        }
        else if (choice == 2) {
            int number;
            cout << "ID number of employee which will be erased: ";
            cin >> number;
            list_of_employees.remove_employee(number);
        }
        else if (choice == 3) display_warehouse_info();
        else if (choice == 4) display_habitat_info();
        else if (choice == 5) list_of_employees.display_all_employees();
        else if (choice != 0) cerr << "Wrong number";
    }
    


}
void Director_of_the_zoo::display_tasks() {
    system("cls");
    cout << "As an director you can :\n1. Add an employee.\n2. Erase an employee.\n3. Display info about warehouse.\n4. Display info about habitats.\n5. Display info about all employees.\n";
}

//-------------------------------------------------------- MANAGER ----------------------------------------------------------------
Manager_of_the_zoo::Manager_of_the_zoo(string Name, string Last_name, string Date_of_birth, string Date_of_employment, string Position, int ID_Number_of_employee, string Specialization) : Employee(Name, Last_name, Date_of_birth, Date_of_employment, Position, ID_Number_of_employee) {
    specialization = Specialization;
}
void Manager_of_the_zoo::display_employee_info() {
    cout << "Name: " << name << "\nLast name: " << last_name << "\nDate of birth: " << date_of_birth << "\n Date od employment: " << date_of_employment << "\nPosition: " << position << "\nID number: " << ID_number_of_employee << "\nSpecialization: " << specialization << "\n\n";
}
void Manager_of_the_zoo::display_employee_menu() {

    int choice = 1;
    while (choice != 0) {
        display_tasks();
        cout << "Your choice (0 to escape): ";
        cin >> choice;
        if (choice == 1) move_animal();
        else if (choice == 2) display_warehouse_info();
        else if (choice == 3) replain_warehouse();
        else if (choice != 0) cerr << "Wrong number";
    }
   
}
void Manager_of_the_zoo::display_tasks() {
	system("cls");
	cout << "As an maganger you can :\n1. Move an animal on other habitat.\n2. Display stock status.\n3. Replain goods in warehouse\n";
}
void Manager_of_the_zoo::move_animal() {
//	display_habitat_info();
}
void Manager_of_the_zoo::replain_warehouse() {

}
void Manager_of_the_zoo::repair_habitat_issues() {

}

//-------------------------------------------------------- ZOOKEPER ----------------------------------------------------------------
Zookeeper::Zookeeper(string Name, string Last_name, string Date_of_birth, string Date_of_employment, string Position, int ID_Number_of_employee, string Specialization, vector<string> Animal_under_care) : Employee(Name, Last_name, Date_of_birth, Date_of_employment, Position, ID_Number_of_employee) {
    specialization = Specialization;
    animal_under_care = Animal_under_care;
}
void Zookeeper::display_employee_info(){
    cout << "Name: " << name << "\nLast name: " << last_name << "\nDate of birth: " << date_of_birth << "\n Date od employment: " << date_of_employment << "\nPosition: " << position << "\nID number: " << ID_number_of_employee << "\nSpecialization: " << specialization << "Animals under care: ";
    for (string animal : animal_under_care) cout << animal << " ";
    cout << "\n\n";
}
void Zookeeper::display_employee_menu() {
}
void Zookeeper::display_tasks() {

}
void Zookeeper::feed_animal() {

}
void Zookeeper::make_an_appointment_with_the_vet() {

}
void Zookeeper::take_animal_for_quarantine() {

}
void Zookeeper::report_issue_with_habitat() {

}

//---------------------------------------------------------- VET -------------------------------------------------------------------

Vet::Vet(string Name, string Last_name, string Date_of_birth, string Date_of_employment, string Position, int ID_Number_of_employee, string Specialization) : Employee(Name, Last_name, Date_of_birth, Date_of_employment, Position, ID_Number_of_employee) {
    specialization = Specialization;
}
void Vet::display_employee_info() {
    cout << "Name: " << name << "\nLast name: " << last_name << "\nDate of birth: " << date_of_birth << "\nDate od employment: " << date_of_employment << "\nPosition: " << position << "\nID number: " << ID_number_of_employee << "\nSpecialization: " << specialization<<"\n\n";
}
void Vet::display_tasks() {

}
void Vet::display_employee_menu() {

}
void Vet::take_care_of_sick_animal() {

}
void Vet::replain_medicine() {

}