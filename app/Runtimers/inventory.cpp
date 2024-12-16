#include "inventory.h"


void loadInventory(const string& fileName, vector<Chemical>& inventory) {
	ifstream file(fileName);
	if (!file) {
		cerr << "Unable to open file for reading" << endl;
	}

	Chemical chem;

	while (file >> chem.name >> chem.casNumber >> chem.chemicalFormula >> chem.expiryDate >> chem.hazardLevel >> chem.quantity) {
		inventory.push_back(chem);
	}
	file.close();
}

void saveInventory(const string& fileName, vector<Chemical>& inventory) {
	ofstream file(fileName);
	if (!file) {
		cerr << "Unable to open file for writing" << endl;
	}

	for (const auto& chem : inventory) {
		file << chem.name << " " << chem.casNumber << " " << chem.chemicalFormula << " " << chem.expiryDate << " " << chem.hazardLevel << " " << chem.quantity << endl;
	}
	file.close();
}
void displayInventory(vector<Chemical>& inventory) {
	for (const auto& chem : inventory) {
		cout << "Name: " << chem.name
			<< "casNumber: " << chem.casNumber
			<< "expiryDate: " << chem.expiryDate
			<< "hazardLevel: " << chem.hazardLevel
			<< "quantity: " << chem.quantity
			<< endl;
	}
}