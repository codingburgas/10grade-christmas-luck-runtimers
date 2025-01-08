#include "pch.h"
#include "startingScreen.h"

int main() 
{

	vector<Chemical> inventory = LoadInventoryFromFile("inventory.txt");

	displayStartingScreen();

}