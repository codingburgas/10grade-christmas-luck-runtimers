#include "pch.h"

#pragma once

// Structure to represent a chemical
struct Chemical
{
	string name;
	string chemicalFormula;
	int quantity;
};

// Function declarations
bool checkIfFileExists(const string& fileName);

vector<Chemical> LoadInventoryFromFile(const string& fileName);
vector<Chemical> searchInventory(const string& query, const vector<Chemical>& inventory);

void saveInventoryFile(const string& fileName, vector<Chemical>& inventory);
void randomSortInventory(vector<Chemical>& inventory);
void sortInventory(vector<Chemical>& inventory);

void displayArchive();
void displayTablet();