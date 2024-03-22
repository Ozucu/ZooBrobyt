#pragma once
#include<iostream>
#include<vector>
using namespace std;

class employee
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
	employee(string = "unknown", string = "unknown", string = "unknown", string = "unknown", string = "unknown", string = "unknown", vector<string> = {}, int = 0);
	void load_employee_data(string FileName);
	void display_employee_info();
	void feed_animal();
	void take_care_of_sick_animal();
	void take_animal_for_quarantine();
};

