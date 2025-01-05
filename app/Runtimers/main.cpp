#include "pch.h"
#include "inventory.h"
#include "archive.h"
#include "startingScreen.h"

int main() {

	vector<Chemical> inventory = LoadInventoryFromFile("inventory.txt");

	displayStartingScreen();

}