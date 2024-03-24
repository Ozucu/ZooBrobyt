#include "warehouse.h"
Warehouse::Warehouse(vector<float> Stock_status, vector<string> Type_of_product, vector<string> Expiration_date, vector<string> Date_of_receipt) {
	stock_status = Stock_status;
	type_of_product = Type_of_product;
	expiration_date = Expiration_date;
	date_of_receipt = Date_of_receipt;
}
