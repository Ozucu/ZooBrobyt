#include "employee.h"
employee::employee(string Name, string Last_name, string Date_of_birth, string Date_of_employment, string Position, string Specialization, vector<string> Animal_under_care, int ID_Number_of_employee) {
	name = Name;
	last_name = Last_name;
	date_of_birth = Date_of_birth;
	date_of_employment = Date_of_employment;
	position = Position;
	specialization = Specialization;
	animal_under_care = Animal_under_care;
	ID_number_of_employee = ID_Number_of_employee;
}