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
    cout << "\n\nName: " << name << "\nLast name: " << last_name << "\nDate of birth: " << date_of_birth << "\n Date od employment: " << date_of_employment << "\nPosition: " << position << "\nID number: " << ID_number_of_employee;
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
    for (auto& employee : list_of_employees) {
        employee -> display_employee_info();
    }

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
void Director_of_the_zoo::display_employee_menu() {

}
void Director_of_the_zoo::display_tasks() {

}

//-------------------------------------------------------- MANAGER ----------------------------------------------------------------
Manager_of_the_zoo::Manager_of_the_zoo(string Name, string Last_name, string Date_of_birth, string Date_of_employment, string Position, int ID_Number_of_employee, string Specialization) : Employee(Name, Last_name, Date_of_birth, Date_of_employment, Position, ID_Number_of_employee) {
    specialization = Specialization;
}
void Manager_of_the_zoo::display_employee_info() {
    cout << "\n\nName: " << name << "\nLast name: " << last_name << "\nDate of birth: " << date_of_birth << "\n Date od employment: " << date_of_employment << "\nPosition: " << position << "\nID number: " << ID_number_of_employee << "\nSpecialization: " << specialization;
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
    cout << "\nName: " << name << "\nLast name: " << last_name << "\nDate of birth: " << date_of_birth << "\n Date od employment: " << date_of_employment << "\nPosition: " << position << "\nID number: " << ID_number_of_employee << "\nSpecialization: " << specialization << "Animals under care: ";
    for (string animal : animal_under_care) cout << animal << " ";
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
    cout << "\n\nName: " << name << "\nLast name: " << last_name << "\nDate of birth: " << date_of_birth << "\n Date od employment: " << date_of_employment << "\nPosition: " << position << "\nID number: " << ID_number_of_employee << "\nSpecialization: " << specialization;
}
void Vet::display_tasks() {

}
void Vet::display_employee_menu() {

}
void Vet::take_care_of_sick_animal() {

}
void Vet::replain_medicine() {

}