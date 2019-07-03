#include "PriceListItem.h"
PriceListItem::PriceListItem(const string &itemName, const string &code, double price, bool taxable) {
 name = itemName;
 barcode = code;
 priceofitem = price;
 tax = taxable;
}


PriceListItem::PriceListItem() {
  name = " ";
  tax = false;
  barcode = " ";
  priceofitem = 0.00;
}

string PriceListItem::getItemName() {
  return name;
}

string PriceListItem::getCode() {
  return barcode;
}

double PriceListItem::getPrice() {

  return priceofitem;
}

bool PriceListItem::isTaxable() {
  return tax;
}
