#include "animal.h"
#include "habitat.h"
#include "employee.h"
#include "warehouse.h"
#include <fstream>

Employee_vector list_of_employees;
unique_ptr<Employee> director_ptr = make_unique<Director_of_the_zoo>("Director", "Director", "01.01.1010", "01.01.1010", "Director", 11);
void start();
void test_employee_vector();
void test_director();

int main() {
	
	start();
	//test_employee_vector();
	test_director();
	return 0;
}

void start() {
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
// do dorobienia wy³apywanie z³ego typu pracownika i zamiana zookeeper na Zookeeper
