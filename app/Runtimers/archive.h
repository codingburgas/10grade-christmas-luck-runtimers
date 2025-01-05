#pragma once

#include "pch.h"

struct Chemical
{
	string name;
	string chemicalFormula;
	int quantity;
};

bool checkIfFileExists(const string& fileName);

vector<Chemical> LoadInventoryFromFile(const string& fileName);
vector<Chemical> searchInventory(const string& query, const vector<Chemical>& inventory);

void saveInventoryFile(const string& fileName, vector<Chemical>& inventory);
void randomSortInventory(vector<Chemical>& inventory);
void sortInventory(vector<Chemical>& inventory);
void handleRemoveElement(const string elementName);
void handleElementClick(const string elementName, const int quantity);


void displayArchive();
void displayTablet();