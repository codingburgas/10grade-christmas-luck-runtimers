#include "inventory.h"
#include "sorting.h"
#include "searching.h"
#include <iostream>

using namespace std;

int main() {
	vector<Chemical>inventory;
	loadInventory("chemicals.txt", inventory);

}