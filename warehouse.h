#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Food
{
	friend class Warehouse;
protected:
	string type_of_product;
	int amount;
	string expiration_date;

public:
	Food(string = "unknown", int = 0, string = "unknown", string = "unknown");
	virtual ~Food() = default;

};
class Warehouse
{
	friend class Employee;
	vector<unique_ptr<Food>> warehouse_status;

public:
	Warehouse(vector<unique_ptr<Food>> = {});
	void load_warehouse_data();
	void display_warehouse_info();
};
class Meat :public Food
{
public:
	Meat(string = "unknown", int = 0, string = "unknown", string = "unknown");

};
class Plant_food :public Food
{
public:
	Plant_food(string = "unknown", int = 0, string = "unknown", string = "unknown");

};