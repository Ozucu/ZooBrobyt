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
	friend class warehouse;
	friend class habitat;
	friend class animal;

public:
	employee(string = "unknown", string = "unknown", string = "unknown", string = "unknown", string = "unknown", string = "unknown", vector<string> = {}, int = 0);
	void load_employee_data(string FileName);
	void display_employee_info();
//--------------------------------------------------------------- ANIMAL STUFF ----------------------------------------------------
	void feed_animal();
	void take_care_of_sick_animal();
	void take_animal_for_quarantine();
//--------------------------------------------------------------- HABITAT STUFF ----------------------------------------------------
	void report_issue_with_habitat();
	void repair_habitat_issues();
//--------------------------------------------------------------- WAREHOUSE STUFF ----------------------------------------------------
	void replain_warehouse();
};

