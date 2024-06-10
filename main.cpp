#include "animal.h"
#include "habitat.h"
#include "employee.h"
#include "warehouse.h"
#include <fstream>

Employee_vector list_of_employees;
unique_ptr<Employee> director_ptr = make_unique<Director_of_the_zoo>("Director", "Director", "01.01.1010", "01.01.1010", "Director", 11);
void start_employees();
void test_employee_vector();
void test_director();

Animal_vector list_of_animals;
void test_animal_vector();
void start_animals();

Habitat_vector list_of_habitats;
void start_habitats();

void test();
void menu();
int main() {
	//start_animals();
	//start_employees();
	//test_employee_vector();
	//test_director();
	//start_habitats();
	//test();
	menu();
	return 0;
}
void test() {
	list_of_animals.load_animal_data("animals.txt");
	list_of_animals.display_all_animals();
	list_of_habitats.load_habitat_data("habitats.txt");
	list_of_habitats.display_all_habitats_info();
	//list_of_animals.add_animal_to_animal_vector(list_of_habitats);
	//list_of_animals.display_all_animals();
	//list_of_habitats.display_all_habitats_info();
	//list_of_animals.remove_animal(list_of_habitats);
	//list_of_animals.display_all_animals();
	//list_of_habitats.display_all_habitats_info();
}
void start_employees() {
	cout << "START\n";
	list_of_employees.load_employee_data("employees.csv");
	cout << "WCZYTANI PRACOWNICY:\n";
	list_of_employees.display_all_employees();

}
void test_employee_vector() {
	cout << "TEST WEKTORA PRACOWNIKOW\n\n";
	list_of_employees.add_employee(move(director_ptr));
	cout << "DODANIE PRACOWNIKA DO WEKTORA:\n";
	list_of_employees.display_all_employees();
	list_of_employees.remove_employee(0);
	cout << "USUNIECIE PRACOWNIKA Z WEKTORA:\n";
	list_of_employees.display_all_employees();
}
void test_director() {
	cout << "TEST DYREKTORA\n\nWYSWIETLENIE INFORMACJI O DYREKTORZE:\n";
	director_ptr->display_employee_info();
	cout << "WYSWIETLENIE MENU OPCJI DYREKTORA:\n";
	//director_ptr->display_employee_menu();
	static_cast<Director_of_the_zoo*>(director_ptr.get())->display_employee_menu(move(list_of_employees));
	
}
void start_animals() {
	list_of_animals.load_animal_data("animals.txt");
	list_of_animals.display_all_animals();
}
void test_animal_vector() {

}
void start_habitats() {
	list_of_habitats.load_habitat_data("habitats.txt");
	list_of_habitats.display_all_habitats_info();
}
void menu() {
	list_of_animals.load_animal_data("animals.txt");
	list_of_employees.load_employee_data("employees.txt");
	list_of_habitats.load_habitat_data("habitats.txt");
	Employee* employee_ptr = nullptr;
	cout << "Prosze wybrac pracownika: \n1. Dyrektor zoo.\n2. Zarzadca zoo.\n3. Opiekun zwierzat.\n4. Weterynarz.\n0. Wyjscie.\nPracownik nr: ";
	int choice;
	cin >> choice;
	switch (choice) {
		case 0:
			return;
		case 1:
			employee_ptr = list_of_employees.get_employee(0);
			employee_ptr->display_employee_info();
			employee_ptr->display_employee_menu();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
	}
}
//do dorobienia wy³apywanie z³ego typu pracownika i zamiana zookeeper na Zookeeper
//na odwórt daæ freind class
//zmiana displayu dla pracowników na Employee::