#include "pch.h"

#ifndef INVENTORY_H
#define INVENTORY_H

struct Chemical
{
	string name;
	string casNumber;
	string chemicalFormula;
	int quantity;
	string expiryDate;
	int hazardLevel; // 1 -> ниско , 5 -> високо
};
void loadInventory(const string& fileName, vector<Chemical>& inventory);
void saveInventory(const string& fileName, vector<Chemical>& inventory);
//void displayInventory(const vector<Chemical>& inventory);

void displayInventory();
void displayShelfInside();
void displayChembenchZoomed();


#endif