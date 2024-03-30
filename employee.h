#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;

class Employee
{
	string name;
	string last_name;
	string date_of_birth;
	string date_of_employment;
	string position;
	int ID_number_of_employee;

public:
	Employee(string = "unknown", string = "unknown", string = "unknown", string = "unknown", string = "unknown", int = 0);
	void display_employee_info();
	void display_warehouse_info();
	void get_stuff_from_warehouse();
//	void display_habitat_info();
//	virtual void display_tasks() = 0;
//	virtual void display_employee_menu() = 0;

};

class Employee_vector {
	vector<Employee> list_of_employees;
public:
	void load_employee_data(string FileName);
	void display_all_employees();
	void add_employee(const Employee &employee);
	void remove_employee();

};

class Director_of_the_zoo :public Employee
{
	friend class Animal;
	friend class Warehouse;
	friend class Habitat;
public:
	Director_of_the_zoo(string name, string last_name, string date_of_birth, string date_of_employment, string position, int ID_number_of_employee);

};

class Manager_of_the_zoo :public Employee
{
	string specialization;
	friend class Warehouse;
	friend class Habitat;
public:
	Manager_of_the_zoo(string = "unknown", string = "unknown", string = "unknown", string = "unknown", string = "unknown", int = 0, string = "unknown");
//	virtual void display_tasks();
//	virtual void display_employee_menu();
	void replain_warehouse();
	void move_animal();
	void repair_habitat_issues();
};

class Zookeeper :public Employee
{
	string specialization;
	vector<string> animal_under_care;

	friend class Animal;
	friend class Warehouse;
	friend class Habitat;
public:
	Zookeeper(string name, string last_name, string date_of_birth, string date_of_employment, string position, int ID_number_of_employee, string specialization = "unknown", vector<string> animal_under_care = {});
	void feed_animal();
	void make_an_appointment_with_the_vet();
	void take_animal_for_quarantine();
	void report_issue_with_habitat();

};

class Vet :public Employee
{
	string specialization;
	friend class Animal;
	friend class Habitat;
public:
	Vet(string name, string last_name, string date_of_birth, string date_of_employment, string position, int ID_number_of_employee, string specialization = "unknown");
	void take_care_of_sick_animal();
	void replain_medicine();

};

