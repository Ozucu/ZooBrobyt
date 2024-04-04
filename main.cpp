#include "animal.h"
#include "habitat.h"
#include "employee.h"
#include "warehouse.h"
#include <fstream>

Employee_vector list_of_employees;
void start();

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
	//unique_ptr<Employee> manager_ptr = make_unique<Manager_of_the_zoo>();
	//list_of_employees.add_employee(move(manager_ptr));

}
