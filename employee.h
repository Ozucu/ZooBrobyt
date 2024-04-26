#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;

class Employee
{
protected:
	string name;
	string last_name;
	string date_of_birth;
	string date_of_employment;
	string position;
	int ID_number_of_employee;

public:
	Employee(string = "unknown", string = "unknown", string = "unknown", string = "unknown", string = "unknown", int = 0);
	//wirtualny destruktor dla klasy bazowej
	//void display_warehouse_info();
	void get_stuff_from_warehouse();
	//void display_habitat_info();
	virtual void display_employee_info();
	virtual void display_tasks(); // problem gdy zmienie z wirtualnej na czysto wirtualn¹ poprzez dodanie = 0
	virtual void display_employee_menu(); // problem gdy zmienie z wirtualnej na czysto wirtualn¹ poprzez dodanie = 0

};

class Employee_vector {

	vector<unique_ptr<Employee>> list_of_employees;

public:
	//Employee_vector(vector<unique_ptr<Employee>> = {}); //kopiowanie obiektu
	Employee_vector(vector<unique_ptr<Employee>> && = {});//przenoszenie bez kopiowania
	void load_employee_data(string FileName);
	void display_all_employees();
	void add_employee(unique_ptr<Employee> employee);
	void remove_employee(size_t index);

};

class Director_of_the_zoo :public Employee
{
	friend class Animal;
	friend class Warehouse;
	friend class Habitat;
	friend class Employee_vector;
public:
	Director_of_the_zoo(string = "unknown", string = "unknown", string = "unknown", string = "unknown", string = "unknown", int = 0);
	virtual void display_tasks();
	virtual void display_employee_menu(Employee_vector list_of_employees);

};

class Manager_of_the_zoo :public Employee
{
	string specialization;
	friend class Warehouse;
	friend class Habitat;

public:
	Manager_of_the_zoo(string = "unknown", string = "unknown", string = "unknown", string = "unknown", string = "unknown", int = 0, string = "unknown");
	virtual void display_tasks();
	virtual void display_employee_menu();
	virtual void display_employee_info();
	void replain_warehouse();
	void move_animal();
};

class Zookeeper :public Employee
{
	string specialization;
	vector<string> animal_under_care;

	friend class Animal;
	friend class Warehouse;
	friend class Habitat;

public:
	Zookeeper(string = "unknown", string = "unknown", string = "unknown", string = "unknown", string = "unknown", int = 0, string = "unknown", vector<string> = {});
	virtual void display_tasks();
	virtual void display_employee_menu();
	virtual void display_employee_info();
	void feed_animal();
	void make_an_appointment_with_the_vet();
	void take_animal_for_quarantine();



};

class Vet :public Employee
{
	vector<string> appointments;
	string specialization;
	friend class Animal;
	friend class Habitat;
public:
	Vet(string = "unknown", string = "unknown", string = "unknown", string = "unknown", string = "unknown", int = 0, string = "unknown", vector<string> = {});
	virtual void display_employee_info();
	virtual void display_tasks();
	virtual void display_employee_menu();
	void take_care_of_sick_animal();
	void take_animal_for_quarantine();
	void replain_medicine();

};

