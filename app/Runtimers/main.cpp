#include "pch.h"
#include "inventory.h"
#include "startingScreen.h"

int main() {
	vector<Chemical>inventory;
	loadInventory("chemicals.txt", inventory);

	displayStartingScreen();

}