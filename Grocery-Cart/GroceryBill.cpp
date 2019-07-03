#include "GroceryBill.h"
#include <iostream>
#include <fstream>

using namespace std;

GroceryBill::GroceryBill(const PriceList *priceList, double taxRate) {

	item_codes = new string[1000];
	Quantity = new double[1000];
  tax_rate = taxRate;
	cart = priceList;
	size = 0;

}

void GroceryBill::scanItem(string scanCode, double quantity) {

	if(cart->isValid(scanCode)==false){
		throw invalid_argument(" Invalid code.");
	}
	Quantity[size] = quantity;
	item_codes[size] = scanCode;
	size++;
}


// Scan multiple codes and quantities from the given text file
// Each line contains two numbers separated by space: the first is the code (an integer), the second the quantity (a float/double)
// Example line from text file:
// 15000000 1.5
void GroceryBill::scanItemsFromFile(string filename) {

  ifstream myfile(filename);

	if (myfile.is_open()) {
		cout << "Successfully opened file " << filename << endl;
		string name;
		string code;
		double price;
		bool taxable;
		while (myfile >> name >> code >> price >> taxable) {
			    cout << code << " " << taxable << endl;
		}
		myfile.close();
	}
	else
		throw invalid_argument("Could not open file " + filename);

}
// return the total cost of all items scanned
double GroceryBill::getTotal(){
	PriceListItem temp;
	double total;
	  for(int i = 0; i<size; i++){
	    temp = cart->getItem(item_codes[i]);
	    if(temp.isTaxable()==true){
	      total += (temp.getPrice() * Quantity[i]) + (temp.getPrice()*Quantity[i]*tax_rate)/100;
	    }else
	    {
	      total += (Quantity[i] * temp.getPrice());
	    }
	  }
		return total;
}

// Print the bill to cout. Each line contains the name of an item, total price, and the letter "T" if tax was addded.
// The last line shows the total.
// An example:
//Plastic_Wrap	1.60547 T
//Sugar_white	5.475
//Waffles_frozen	5.16
//Oil_Canola_100%_pure	2.69
//Potatoes_red	13.446
//TOTAL 	28.3765
void GroceryBill::printBill() {
	PriceListItem temp;
	double total;
	  for(int i = 0; i<size; i++)
	  {
	    temp = cart->getItem(item_codes[i]);
	    if(temp.isTaxable()==true)
			{
	      total += (temp.getPrice() * Quantity[i]) + (temp.getPrice()*Quantity[i]*tax_rate)/100;
	      cout << temp.getItemName() << "\t" << temp.getPrice() << "\t" << "T" << endl;
	    }
	    else
	    {
	      total += (Quantity[i] * temp.getPrice());
	      cout << temp.getItemName() << "\t" << temp.getPrice() << endl;
	    }
	  }
	  cout << " The total price for the bill will be $" << total << endl;
}
