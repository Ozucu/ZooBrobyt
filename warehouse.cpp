#include "warehouse.h"
Food::Food(string Type_of_product, int Amount, string Expiration_date, string Date_of_receipt) {
	type_of_product = Type_of_product;
	amount = Amount;
	expiration_date = Expiration_date;
	date_of_receipt = Date_of_receipt;
}
Warehouse::Warehouse(vector<unique_ptr<Food>>  Warehouse_status) {
	warehouse_status = move(Warehouse_status);
	
}
