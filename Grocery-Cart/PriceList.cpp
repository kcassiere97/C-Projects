#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "PriceList.h"
#include "PriceListItem.h"

using namespace std;

// Load information from a text file with the given filename.
void PriceList::createPriceListFromDatafile(string filename){
	ifstream myfile(filename);

	if (myfile.is_open()) {
		cout << "Successfully opened file " << filename << endl;
		string name;
		string code;
		double price;
		bool taxable;
		while (myfile >> name >> code >> price >> taxable) {
			// cout << code << " " << taxable << endl;
			addEntry(name, code, price, taxable);
		}
		myfile.close();
	}
	else
		throw invalid_argument("Could not open file " + filename);
}
//default constructor
PriceList::PriceList(){
  EntryList = new PriceListItem[1000000];
	size = 0;
}
// copy constructor
PriceList::PriceList(const PriceList& Copy){

	EntryList = new PriceListItem[1000000];
  size = Copy.size;
  for(int i = 0; i < size; i++)
  {
    EntryList[i] = Copy.EntryList[i];
  }
}

PriceList & PriceList::operator=(const PriceList &Copy)
{
	EntryList = new PriceListItem[1000000];
	size = Copy.size;
	*EntryList = *Copy.EntryList;
	return *this;

}

// return true only if the code is valid
bool PriceList::isValid(string code) const {
	for(int i = 0; i < size; i++){
	if((EntryList[i].getCode()).compare(code)==0){
		return true;
	}
 }
		return false;
 }
// return price, item name, taxable? as an ItemPrice object; throw exception if code is not found
PriceListItem PriceList::getItem(string code) const {
	for( int i =0; i<size; i++){
		if(EntryList[i].getCode().compare(code)==0){
			return EntryList[i];
		}
	}
	throw invalid_argument("No Item Found" +code);
}
// add to the price list information about a new item
void PriceList::addEntry(string itemName, string code, double price, bool taxable){
   PriceListItem NewList(itemName,code,price,taxable); //creating the object NewList
	 EntryList[size] = NewList;
	 size++;
}
