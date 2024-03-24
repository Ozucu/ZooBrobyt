#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Employee
{
	string name;
	string last_name;
	string date_of_birth;
	string date_of_employment;
	string position;
	string specialization;
	vector<string> animal_under_care;
	int ID_number_of_employee;

public:
	Employee(string = "unknown", string = "unknown", string = "unknown", string = "unknown", string = "unknown", string = "unknown", vector<string> = {}, int = 0);
	void load_employee_data(string FileName);
	void display_employee_info();
	void get_stuff_from_warehouse();

};

class Director_of_the_zoo :public Employee
{
	friend class Animal;
	friend class Employee; // czy jak dziedziczy to mo¿na/potrzeba dawaæ jako frienda?
	friend class Warehouse;
	friend class Habitat;

};

class Manager_of_the_zoo :public Employee
{
	friend class Warehouse;
	friend class Habitat;
public:
	void replain_warehouse();
	void move_animal();
};

class Zookeeper :public Employee
{
	friend class Animal;
	friend class Warehouse;
	friend class Habitat;
public:
	void feed_animal();
	void make_an_appointment_with_the_vet();
	void take_animal_for_quarantine();
	void report_issue_with_habitat();
	void repair_habitat_issues();
};

class Vet :public Employee
{
	friend class Animal;
	friend class Habitat;
public:
	void take_care_of_sick_animal();
	void take_animal_for_quarantine();
	void replain_medicine();

};

