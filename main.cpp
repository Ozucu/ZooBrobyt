#include "animal.h"
#include "habitat.h"
#include "employee.h"
#include "warehouse.h"
#include <fstream>

Employee_vector list_of_employees;
unique_ptr<Employee> director_ptr = make_unique<Director_of_the_zoo>("Director", "Director", "01.01.1010", "01.01.1010", "Director", 11);

int main() {
	
	start();
	Reptile reptile;
	Animal_vector animal_vector;
	unique_ptr<Animal> ptr(new Reptile(reptile));
	
	//animal_vector.add_animal(move(ptr));
	return 0;
}

void start() {
	list_of_employees.load_employee_data("employees.csv");
	list_of_employees.display_all_employees();

}
void test_employee_vector() {
	Employee* employee_to_remove = list_of_employees[1];
	list_of_employees.add_employee(move(director_ptr));
	list_of_employees.display_all_employees();
}
void test_director() {
	
	director_ptr->display_employee_info();
	director_ptr->display_employee_menu();
	director_ptr->display_tasks();
	
}
