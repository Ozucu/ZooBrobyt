#include "warehouse.h"
//-------------------------------------------------------------------FOOD------------------------------------------------------------------------------
Food::Food(string Type_of_product, int Amount, string Expiration_date, string Date_of_receipt) {
	type_of_product = Type_of_product;
	amount = Amount;
	expiration_date = Expiration_date;
	date_of_receipt = Date_of_receipt;
}
//-------------------------------------------------------------------WAREHOUSE VECTOR------------------------------------------------------------------------------

Warehouse::Warehouse(vector<unique_ptr<Food>>  Warehouse_status) {
	warehouse_status = move(Warehouse_status);
	
}
void Warehouse::display_warehouse_info() {
    cout << "Warehouse Status:" << endl;
    cout << "-----------------" << endl;
    for (const auto& food : warehouse_status) {
        cout << "Type of Product: ";

        // Sprawdzenie, czy obiekt jest instancj¹ klasy Meat
        if (auto meat = dynamic_cast<Meat*>(food.get())) {
            cout << meat->type_of_product << endl;
            // Wyœwietl dodatkowe informacje dla miêsa
            cout << "Amount: " << meat->amount << endl;
            cout << "Expiration Date: " << meat->expiration_date << endl;
            cout << "Date of Receipt: " << meat->date_of_receipt << endl;
        }
        else if (auto plant_food = dynamic_cast<Plant_food*>(food.get())) {
            // Analogicznie dla innych klas pochodnych
            cout << plant_food->type_of_product << endl;
            // Wyœwietl dodatkowe informacje dla po¿ywienia roœlinnego
            cout << "Amount: " << plant_food->amount << endl;
            cout << "Expiration Date: " << plant_food->expiration_date << endl;
            cout << "Date of Receipt: " << plant_food->date_of_receipt << endl;
        }
        else {
            // Obs³u¿ obiekt klasy Food lub inny nieznany typ
            cout << food->type_of_product << endl;
            // Wyœwietl podstawowe informacje
            cout << "Amount: " << food->amount << endl;
            cout << "Expiration Date: " << food->expiration_date << endl;
            cout << "Date of Receipt: " << food->date_of_receipt << endl;
        }

        cout << endl;
    }
}
//-------------------------------------------------------------------MEAT------------------------------------------------------------------------------
Meat::Meat(string Type_of_product, int Amount, string Expiration_date, string Date_of_receipt) : Food(Type_of_product, Amount, Expiration_date, Date_of_receipt) {

}
//-------------------------------------------------------------------PLANT FOOD------------------------------------------------------------------------------
Plant_food::Plant_food(string Type_of_product, int Amount, string Expiration_date, string Date_of_receipt) : Food(Type_of_product, Amount, Expiration_date, Date_of_receipt) {

}