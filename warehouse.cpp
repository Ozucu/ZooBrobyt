#include "warehouse.h"
//-------------------------------------------------------------------FOOD------------------------------------------------------------------------------
Food::Food(vector<string> Type_of_product, vector<int> Amount, vector<string> Expiration_date) {
	type_of_product = Type_of_product;
	amount = Amount;
	expiration_date = Expiration_date;
}
//-------------------------------------------------------------------WAREHOUSE VECTOR------------------------------------------------------------------------------

Warehouse::Warehouse(vector<unique_ptr<Food>>  Warehouse_status) {
	warehouse_status = move(Warehouse_status);
	
}
void Warehouse::display_warehouse_info() {
    cout << "Warehouse Status:" << endl;
    cout << "-----------------" << endl;
 
}
//-------------------------------------------------------------------MEAT------------------------------------------------------------------------------
Meat::Meat(vector<string> Type_of_product, vector<int> Amount, vector<string> Expiration_date) : Food(Type_of_product, Amount, Expiration_date) {

}
//-------------------------------------------------------------------PLANT FOOD------------------------------------------------------------------------------
Plant_food::Plant_food(vector<string> Type_of_product, vector<int> Amount, vector<string> Expiration_date) : Food(Type_of_product, Amount, Expiration_date) {

}