#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Food
{
	friend class Warehouse;
protected:
	vector<string> type_of_product;
	vector<int> amount;
	vector<string> expiration_date;

public:
	Food(vector<string> = {}, vector<int> = {}, vector<string> = {});
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
	Meat(vector<string> = {}, vector<int> = {}, vector<string> = {});

};
class Plant_food :public Food
{
public:
	Plant_food(vector<string> = {}, vector<int> = {}, vector<string> = {});

};