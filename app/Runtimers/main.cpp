#include "pch.h"
#include "startingScreen.h"

int main() 
{

	vector<Chemical> inventory = LoadInventoryFromFile("inventory.txt"); // Load inventory from file

	displayStartingScreen(); // Display the starting screen

}