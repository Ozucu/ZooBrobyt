#include "animal.h"
#include "habitat.h"
#include "employee.h"
#include "warehouse.h"
#include <fstream>

Employee_vector list_of_employees;
void start();

int main() {
	
	start();
	
	return 0;
}

void start() {
	list_of_employees.load_employee_data("employees.csv");
	list_of_employees.display_all_employees();
	Manager_of_the_zoo manager;
	Employee *wsk;
	wsk = &manager;
	list_of_employees.add_employee(wsk);
	list_of_employees.display_all_employees();


}
