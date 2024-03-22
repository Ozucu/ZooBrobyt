#pragma once
#include <vector>
#include <iostream>
using namespace std;
class warehouse
{
	vector<float> stock_status;
	vector<string> type_of_product;
	vector<string> expiration_date;
	vector<string> date_of_receipt; //w sensie kiedy towar przyjecha³ ¿eby policzyæ jego przydatnoœæ do podania zwierzakom

public:
	warehouse(vector<float> = {}, vector<string> = {}, vector<string> = {}, vector<string> = {});
	void load_warehouse_data();
	void display_warehouse_info();
};

