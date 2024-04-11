#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Food
{
	string type_of_product;
	int amount;
	string expiration_date;
	string date_of_receipt; //w sensie kiedy towar przyjecha³ ¿eby policzyæ jego przydatnoœæ do podania zwierzakom
public:
	Food(string = "unknown", int = 0, string = "unknown", string = "unknown");

};
class Warehouse
{
	vector<unique_ptr<Food>> warehouse_status;

public:
	Warehouse(vector<unique_ptr<Food>> = {});
	void load_warehouse_data();
	void display_warehouse_info();
};
class Meat :public Food
{

};
class Plant_food :public Food
{

};