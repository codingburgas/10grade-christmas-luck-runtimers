#include "inventory.h"

const int screenWidth = 1920;
const int screenHeight = 1080;

Texture2D inventoryElementsTextures[12];

// Position for the inventory elements
Vector2 inventoryElementPositions[12] =
{
	{ 450, -400 }, { 615, -400 }, {850, -405},
	{420, -240}, {540, -230}, {730, -237}, {830, -261},
	{450, -40}, {640, -29}, {830, -49},
	{520, 160}, {785, 148 }
};

Rectangle inventoryElementRectangles[12];

inventoryElement inventoryElements[12];

Texture2D warningTexture;
Texture2D outOfStockTexture;

int selectedElement = -1;

// Trims leading and trailing whitespace characters from a string
string trim(const string& str)
{
	size_t start = str.find_first_not_of(" \t\n\r");
	size_t end = str.find_last_not_of(" \t\n\r");

	return (start == string::npos) ? "" : str.substr(start, end - start + 1);
}

// Checks if a card is clicked
void checkCardClick()
{
	for (int i = 0; i < 12; i++)
	{
		// Check if the mouse position is within the source rectangle of an inventory element
		if (CheckCollisionPointRec({ GetMousePosition().x, GetMousePosition().y }, inventoryElements[i].sourceRect))
		{
			selectedElement = i;
		}
	}
}

// Finds an element in the inventory 
int findElementByName(vector<Chemical>& inventory, const string& formula)
{
	for (int i = 0; i < inventory.size(); i++)
	{
		// Compare the trimmed chemical formula with the given formula
		if (trim(inventory[i].chemicalFormula) == formula)
		{

			return i; 
		}
	}
	return -1; 
}

void displayInventoryBg()
{
	Font font = LoadFont("../font/font.ttf"); // Load font

	// Position for the buttons
	Vector2 exitButtonPosition = { GetScreenWidth() / 2 + 650, GetScreenHeight() / 2 + 425 };
	Vector2 shelfButtonPosition = { GetScreenWidth() / 2 + 600, GetScreenHeight() / 2 - 50 };
	Vector2 chembenchButtonPosition = { GetScreenWidth() / 2 - 550, GetScreenHeight() / 2 };

	// Define the button's rectangles
	const Rectangle exitButton = { exitButtonPosition.x + 90, exitButtonPosition.y + 20, 115, 70 };
	const Rectangle shelfButton = { shelfButtonPosition.x , shelfButtonPosition.y , 400, 500 };
	const Rectangle chembenchButton = { chembenchButtonPosition.x , chembenchButtonPosition.y , 600, 300 };

	Texture2D background = LoadTexture("../assets/inventory/labBackground.png"); // Load background texture

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		Vector2 mousePosition = GetMousePosition();

		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawTexture(background, 0, 0, RAYWHITE);

		// Check if the mouse is over the chembench button
		bool isMouseOverChembenchButton = CheckCollisionPointRec(mousePosition, chembenchButton);

		if (CheckCollisionPointRec(mousePosition, chembenchButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			displayChembenchZoomed();
		}

		// Check if the mouse is over the shelf button
		bool isMouseOverShelfButton = CheckCollisionPointRec(mousePosition, shelfButton);

		if (CheckCollisionPointRec(mousePosition, shelfButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			displayShelfInside();
		}

		// Check if the mouse is over the exit button
		bool isMouseOverExitButton = CheckCollisionPointRec(mousePosition, exitButton);

		DrawTextEx(font, "Exit", Vector2{ exitButtonPosition.x + 100, exitButtonPosition.y + 55 }, 50, 10, isMouseOverExitButton ? BLACK : WHITE);

		if (CheckCollisionPointRec(mousePosition, exitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			break;
		}

		EndDrawing();
	}

	UnloadTexture(background);
	UnloadFont(font);

}

void displayChembenchZoomed()
{
	Font font = LoadFont("../font/font.ttf"); // Load font

	Vector2 exitButtonPosition = { GetScreenWidth() / 2 + 650, GetScreenHeight() / 2 + 425 }; // Position for the button

	const Rectangle exitButton = { exitButtonPosition.x + 90, exitButtonPosition.y + 20, 115, 50 }; // Define the button's rectangle

	Texture2D background = LoadTexture("../assets/inventory/chembenchZoomed/chembenchZoomed.png"); // Load background texture

	//Load textures
	inventoryElementsTextures[0] = LoadTexture("../assets/inventory/chembenchZoomed/cards/H2Card.png");
	inventoryElementsTextures[1] = LoadTexture("../assets/inventory/chembenchZoomed/cards/H2OCard.png");
	inventoryElementsTextures[2] = LoadTexture("../assets/inventory/chembenchZoomed/cards/O2Card.png");
	inventoryElementsTextures[3] = LoadTexture("../assets/inventory/chembenchZoomed/cards/Cl2Card.png");
	inventoryElementsTextures[4] = LoadTexture("../assets/inventory/chembenchZoomed/cards/N2Card.png");
	inventoryElementsTextures[5] = LoadTexture("../assets/inventory/chembenchZoomed/cards/CaCard.png");
	inventoryElementsTextures[6] = LoadTexture("../assets/inventory/chembenchZoomed/cards/NaCard.png");
	inventoryElementsTextures[7] = LoadTexture("../assets/inventory/chembenchZoomed/cards/HClCard.png");
	inventoryElementsTextures[8] = LoadTexture("../assets/inventory/chembenchZoomed/cards/NaOHCard.png");
	inventoryElementsTextures[9] = LoadTexture("../assets/inventory/chembenchZoomed/cards/NaClCard.png");
	inventoryElementsTextures[10] = LoadTexture("../assets/inventory/chembenchZoomed/cards/HNO3Card.png");
	inventoryElementsTextures[11] = LoadTexture("../assets/inventory/chembenchZoomed/cards/CaOH2Card.png");

	// Define the textures' rectangles
	inventoryElementRectangles[0] = { 1378, 35, 110, 100 };
	inventoryElementRectangles[1] = { 1526, 35, 200, 100 };
	inventoryElementRectangles[2] = { 1773, 35, 110, 100 };
	inventoryElementRectangles[3] = { 1378, 250, 110, 100 };
	inventoryElementRectangles[4] = { 1526, 250, 110, 100 };
	inventoryElementRectangles[5] = { 1686, 250, 110, 100 };
	inventoryElementRectangles[6] = { 1800, 240, 110, 100 };
	inventoryElementRectangles[7] = { 1378, 465, 190, 100 };
	inventoryElementRectangles[8] = { 1510, 465, 200, 110 };
	inventoryElementRectangles[9] = { 1755, 465, 180, 100 };
	inventoryElementRectangles[10] = { 1378, 640, 240, 100 };
	inventoryElementRectangles[11] = { 1700, 660, 240, 100 };

	//Load warnings textures
	warningTexture = LoadTexture("../assets/inventory/chembenchZoomed/warning.png");
	outOfStockTexture = LoadTexture("../assets/inventory/chembenchZoomed/outOfStock.png");

	inventoryElements[0] = { "H2", inventoryElementsTextures[0], inventoryElementRectangles[0], inventoryElementPositions[0] };
	inventoryElements[1] = { "H2O", inventoryElementsTextures[1], inventoryElementRectangles[1], inventoryElementPositions[1] };
	inventoryElements[2] = { "O2", inventoryElementsTextures[2], inventoryElementRectangles[2], inventoryElementPositions[2] };
	inventoryElements[3] = { "Cl2", inventoryElementsTextures[3], inventoryElementRectangles[3], inventoryElementPositions[3] };
	inventoryElements[4] = { "N2", inventoryElementsTextures[4], inventoryElementRectangles[4], inventoryElementPositions[4] };
	inventoryElements[5] = { "Ca", inventoryElementsTextures[5], inventoryElementRectangles[5], inventoryElementPositions[5] };
	inventoryElements[6] = { "Na", inventoryElementsTextures[6], inventoryElementRectangles[6], inventoryElementPositions[6] };
	inventoryElements[7] = { "HCl", inventoryElementsTextures[7], inventoryElementRectangles[7], inventoryElementPositions[7] };
	inventoryElements[8] = { "NaOH", inventoryElementsTextures[8], inventoryElementRectangles[8], inventoryElementPositions[8] };
	inventoryElements[9] = { "NaCl", inventoryElementsTextures[9], inventoryElementRectangles[9], inventoryElementPositions[9] };
	inventoryElements[10] = { "HNO3", inventoryElementsTextures[10], inventoryElementRectangles[10], inventoryElementPositions[10] };
	inventoryElements[11] = { "Ca(OH)2", inventoryElementsTextures[11], inventoryElementRectangles[11], inventoryElementPositions[11] };

	//Load test tube phases textures
	Texture2D testTubeTextureEmpty = LoadTexture("../assets/inventory/chembenchZoomed/testTubes/testTubeEmpty.png");
	Texture2D testTubeTextureHalfFull = LoadTexture("../assets/inventory/chembenchZoomed/testTubes/testTubeHalfFull.png");

	Rectangle testTube = { 550, 840, 200, 170 }; // Define the test tube's rectangle

	vector<Chemical> inventory = LoadInventoryFromFile("../data/inventory.txt");

	int tubeElements[2] = { -1, -1 };

	bool tubePhase = false;

	bool showWarningTexture = false;
	bool showOutOfStockTexture = false;

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		Vector2 mousePosition = GetMousePosition();
		inventory = LoadInventoryFromFile("../data/inventory.txt");

		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawTexture(background, 0, 0, RAYWHITE);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			checkCardClick();
			if (CheckCollisionPointRec(GetMousePosition(), testTube))
			{
				int elementIndex = findElementByName(inventory, inventoryElements[selectedElement].formula);

				if (inventory[elementIndex].quantity == 0 )
				{
					if (tubePhase)
					{
						tubeElements[0] = selectedElement;
					}
				}
				else
				{
					tubeElements[1] = selectedElement;

					if (tubeElements[0] == 0) // H2
					{
						if (tubeElements[1] == 2) // O2
						{
							// Handle H2 + O2 reaction
							int h2Index = findElementByName(inventory, "H2");
							int o2Index = findElementByName(inventory, "O2");

							if (h2Index != -1 && o2Index != -1)
							{
								inventory[h2Index].quantity -= 2; // Remove H2 from inventory
								inventory[o2Index].quantity--;    // Remove O2 from inventory

								// Add the resulting H2O
								int h2oIndex = findElementByName(inventory, "H2O");
								if (h2oIndex != -1)
								{
									inventory[h2oIndex].quantity++; 
								}
							}
						}
						else if (tubeElements[1] == 3) // Cl2
						{
							// Handle H2 + Cl2 reaction 
							int h2Index = findElementByName(inventory, "H2 ");
							int cl2Index = findElementByName(inventory, "Cl2");

							if (h2Index != -1 && cl2Index != -1)
							{
								inventory[h2Index].quantity--; // Remove H2 from inventory
								inventory[cl2Index].quantity--; // Remove Cl2 from inventory

								// Add HCl to inventory
								int hclIndex = findElementByName(inventory, "HCl");
								if (hclIndex != -1)
								{
									inventory[hclIndex].quantity += 2; 
								}
							}
						}
					}
					else if (tubeElements[0] == 1) // H2O
					{
						if (tubeElements[1] == 5) // Ca
						{
							// Handle H2O + Ca reaction
							int h2oIndex = findElementByName(inventory, "H2O");
							int caIndex = findElementByName(inventory, "Ca");

							if (h2oIndex != -1 && caIndex != -1)
							{
								inventory[h2oIndex].quantity -= 2; // Remove H2O from inventory
								inventory[caIndex].quantity--; // Remove Ca from inventory

								// Add Ca(OH)2 and H2 to inventory
								int caohIndex = findElementByName(inventory, "Ca(OH)2");
								if (caohIndex != -1)
								{
									inventory[caohIndex].quantity++; // Add Ca(OH)2 to inventory
								}

								int hIndex = findElementByName(inventory, "H2");
								if (hIndex != -1) {
									inventory[hIndex].quantity++; // Add H2 to inventory
								}
							}
						}
						else if (tubeElements[1] == 6) // Na
						{
							// Handle H2O + Na reaction to form NaOH
							int h2oIndex = findElementByName(inventory, "H2O ");
							int naIndex = findElementByName(inventory, "Na");

							if (h2oIndex != -1 && naIndex != -1)
							{
								inventory[h2oIndex].quantity--; // Remove H2O from inventory
								inventory[naIndex].quantity--; // Remove Na from inventory

								// Add NaOH to inventory
								int naohIndex = findElementByName(inventory, "NaOH");
								if (naohIndex != -1)
								{
									inventory[naohIndex].quantity += 2;
								}
							}
						}
					}
					else if (tubeElements[0] == 2) // O2
					{
						if (tubeElements[1] == 7) // HCl
						{
							// Handle O2 + HCl reaction
							int oIndex = findElementByName(inventory, "O2");
							int hclIndex = findElementByName(inventory, "HCl");

							if (oIndex != -1 && hclIndex != -1)
							{
								inventory[oIndex].quantity--; // Remove O2 from inventory
								inventory[hclIndex].quantity -= 4; // Remove HCl from inventory

								// Add H2O and Cl2 to inventory
								int h2oIndex = findElementByName(inventory, "H2O");
								if (h2oIndex != -1)
								{
									inventory[h2oIndex].quantity += 2; // Add H2O to inventory
								}

								int clIndex = findElementByName(inventory, "Cl2");
								if (clIndex != -1) {
									inventory[clIndex].quantity += 2; // Add Cl2 to inventory
								}
							}

						}
					}
					else if (tubeElements[0] == 3) //Cl2
					{
						if (tubeElements[1] == 6) // Na
						{
							// Handle Cl2 + Na reaction
							int clIndex = findElementByName(inventory, "CL2");
							int naIndex = findElementByName(inventory, "Na");

							if (clIndex != -1 && naIndex != -1)
							{
								inventory[clIndex].quantity--; // Remove Cl2 from inventory
								inventory[naIndex].quantity -= 2; // Remove Na2 from inventory

								// Add NaCl to inventory
								int naclIndex = findElementByName(inventory, "NaCl");
								if (naclIndex != -1)
								{
									inventory[naclIndex].quantity += 2; 

								}
							}
						}
					}
					else if (tubeElements[0] == 5) //Ca
					{
						if (tubeElements[1] == 1) // H2O
						{
							// Handle Ca + H2O reaction
							int caIndex = findElementByName(inventory, "Ca");
							int h2oIndex = findElementByName(inventory, "H2O");

							if (caIndex != -1 && h2oIndex != -1)
							{ 
								inventory[caIndex].quantity--; // Remove Ca from inventory
								inventory[h2oIndex].quantity--; // Remove H2O from inventory

								// Add Ca(OH)2 and H2 to inventory
								int caohIndex = findElementByName(inventory, "Ca(OH)2");
								if (caohIndex != -1)
								{
									inventory[caohIndex].quantity++; // Add Ca(OH)2 to inventory
								}

								int hlIndex = findElementByName(inventory, "H2");
								if (hlIndex != -1)
								{
									inventory[hlIndex].quantity++; // Add H2 to inventory
								}
							}
						}
					}
					else if (tubeElements[0] == 6) //Na
					{
						if (tubeElements[1] == 1) // H2O
						{
							// Handle H2O + Na reaction to form NaOH
							int h2oIndex = findElementByName(inventory, "H2O");
							int naIndex = findElementByName(inventory, "Na");

							if (h2oIndex != -1 && naIndex != -1)
							{
								inventory[h2oIndex].quantity--; // Remove H2O from inventory
								inventory[naIndex].quantity--; // Remove Na from inventory

								// Add NaOH to inventory
								int naohIndex = findElementByName(inventory, "NaOH");
								if (naohIndex != -1)
								{
									inventory[naohIndex].quantity += 2;
								}
							}
						}
						else if (tubeElements[1] == 3) // Cl2
						{
							// Handle Cl2 + Na reaction
							int clIndex = findElementByName(inventory, "CL2");
							int naIndex = findElementByName(inventory, "Na");

							if (clIndex != -1 && naIndex != -1)
							{
								inventory[clIndex].quantity--; // Remove Cl2 from inventory
								inventory[naIndex].quantity -= 2; // Remove Na from inventory

								// Add NaCl to inventory
								int naclIndex = findElementByName(inventory, "NaCl");
								if (naclIndex != -1)
								{
									inventory[naclIndex].quantity += 2;
								}
							}
						}
						else if (tubeElements[1] == 7) // HCl
						{
							// Handle HCl + Na reaction
							int hclIndex = findElementByName(inventory, "HCl");
							int naIndex = findElementByName(inventory, "Na");

							if (hclIndex != -1 && naIndex != -1)
							{
								inventory[hclIndex].quantity--; // Remove HCl from inventory
								inventory[naIndex].quantity--; // Remove Na from inventory

								// Add NaCl and H2 to inventory
								int naclIndex = findElementByName(inventory, "NaCl");
								if (naclIndex != -1)
								{
									inventory[naclIndex].quantity++; // Add NaCl to inventory
								}

								int hIndex = findElementByName(inventory, "H2");
								if (hIndex != -1)
								{
									inventory[hIndex].quantity++; // Add H2 to inventory
								}
							}
						}
					}

					saveInventoryFile("../data/inventory.txt", inventory);

					tubePhase = !tubePhase;
				}

			}
			if (selectedElement != -1)
			{
				int elementIndex = findElementByName(inventory, inventoryElements[selectedElement].formula);

				if (inventory[elementIndex].quantity == 1)
				{
					showWarningTexture = !showWarningTexture; 
					showOutOfStockTexture = false; 
				}
				else if (inventory[elementIndex].quantity == 0)
				{
					showOutOfStockTexture = !showOutOfStockTexture; 
					showWarningTexture = false; 
				}
				else
				{
					showWarningTexture = false;
					showOutOfStockTexture = false;
				}
			}

		}

		//Display warnings if needed
		if (showWarningTexture)
		{
			DrawTexture(warningTexture, 950, 50, WHITE);  // Display warning texture
		}
		if (showOutOfStockTexture)
		{
			DrawTexture(outOfStockTexture, 950, 50, WHITE);  // Display out-of-stock texture
		}

		// Draw inventory elements
		Color elementColor = RAYWHITE;
		for (int i = 0; i < 12; i++)
		{
			elementColor = RAYWHITE;

			if (selectedElement == i)
			{
				elementColor = BLUE;
			}

			DrawTexture(inventoryElements[i].texture, inventoryElements[i].position.x, inventoryElements[i].position.y, elementColor);
		}

		// Handle exit button click
		bool isMouseOverExitButton = CheckCollisionPointRec(mousePosition, exitButton);
		DrawTextEx(font, "Exit", Vector2{ exitButtonPosition.x + 100, exitButtonPosition.y + 25 }, 50, 10, isMouseOverExitButton ? BLACK : WHITE);
		if (CheckCollisionPointRec(mousePosition, exitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			break;
		}

		// Display test tube based on tubePhase
		if (tubePhase)
		{
			DrawTexture(testTubeTextureHalfFull, -290, 377, WHITE);  
		}
		else
		{
			DrawTexture(testTubeTextureEmpty, -290 , 370, WHITE);  
		}

		EndDrawing();

	}

	UnloadTexture(background); // Unload the background texture 
	UnloadFont(font); // Unload the font

	// Unload textures
	for (int i = 0; i < 12; i++)
	{
		UnloadTexture(inventoryElementsTextures[i]);
	}
}

void displayShelfInside()
{
	Font font = LoadFont("../font/font.ttf"); // Load font

	// Position for the buttons
	Vector2 exitButtonPosition = { GetScreenWidth() / 2 + 650, GetScreenHeight() / 2 + 425 }; 

	Vector2 buttonPositions[] =
	{
		{ GetScreenWidth() / 2 - 420, GetScreenHeight() / 2 - 380 }, // H2O
		{ GetScreenWidth() / 2 - 220, GetScreenHeight() / 2 - 380 }, // HCl
		{ GetScreenWidth() / 2 , GetScreenHeight() / 2 - 380 }, // HNO3
		{ GetScreenWidth() / 2 + 240, GetScreenHeight() / 2 - 400 }, // NaOH
		{ GetScreenWidth() / 2 - 390, GetScreenHeight() / 2 - 160 }, // CaOH2
		{ GetScreenWidth() / 2 - 170, GetScreenHeight() / 2 - 160 }, // NaCl
		{ GetScreenWidth() / 2 + 60, GetScreenHeight() / 2 - 160 },  // O2
		{ GetScreenWidth() / 2 + 325, GetScreenHeight() / 2 - 160 },  // H2
		{ GetScreenWidth() / 2 - 380, GetScreenHeight() / 2 + 120 }, // N2
		{ GetScreenWidth() / 2 - 170, GetScreenHeight() / 2 + 120 }, // Cl2
		{ GetScreenWidth() / 2 + 70, GetScreenHeight() / 2 + 150 }, // Na
		{ GetScreenWidth() / 2 + 300, GetScreenHeight() / 2 + 120 }  // Ca
	};

	// Define the button's rectangles
	const Rectangle exitButton = { exitButtonPosition.x + 90, exitButtonPosition.y + 20, 115, 50 };

	const Rectangle buttons[] =
	{
		{ buttonPositions[0].x, buttonPositions[0].y, 200, 150 },
		{ buttonPositions[1].x, buttonPositions[1].y, 200, 150 },
		{ buttonPositions[2].x, buttonPositions[2].y, 200, 150 },
		{ buttonPositions[3].x, buttonPositions[3].y, 200, 150 },
		{ buttonPositions[4].x, buttonPositions[4].y, 130, 150 },
		{ buttonPositions[5].x, buttonPositions[5].y, 130, 150 },
		{ buttonPositions[6].x, buttonPositions[6].y, 130, 150 },
		{ buttonPositions[7].x, buttonPositions[7].y, 130, 150 },
		{ buttonPositions[8].x, buttonPositions[8].y, 150, 150 },
		{ buttonPositions[9].x, buttonPositions[9].y, 170, 150 },
		{ buttonPositions[10].x, buttonPositions[10].y, 130, 130 },
		{ buttonPositions[11].x, buttonPositions[11].y, 130, 150 }
	};

	Texture2D background = LoadTexture("../assets/inventory/shelfInside.png"); // Load background texture

	//Load reagents
	Texture2D reagents[] = {
		LoadTexture("../assets/inventory/info/H2OInfo.png"),
		LoadTexture("../assets/inventory/info/HClInfo.png"),
		LoadTexture("../assets/inventory/info/HNO3Info.png"),
		LoadTexture("../assets/inventory/info/NaOHInfo.png"),
		LoadTexture("../assets/inventory/info/CaOH2Info.png"),
		LoadTexture("../assets/inventory/info/NaClInfo.png"),
		LoadTexture("../assets/inventory/info/O2Info.png"),
		LoadTexture("../assets/inventory/info/H2Info.png"),
		LoadTexture("../assets/inventory/info/N2Info.png"),
		LoadTexture("../assets/inventory/info/Cl2Info.png"),
		LoadTexture("../assets/inventory/info/NaInfo.png"),
		LoadTexture("../assets/inventory/info/CaInfo.png")
	};

	//Position the reagents
	Vector2 reagentPositions[] = {
		{ 55, 110 }, { 265, 100 }, { 495, 100 }, { 730, 100 },
		{ 70, 260 }, { 250, 260 }, { 485, 260 }, { 740, 260 },
		{ 35, 580 }, { 225, 580 }, { 510, 580 }, { 750, 580 }
	};

	int visibleReagentIndex = -1;

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		Vector2 mousePosition = GetMousePosition();

		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawTexture(background, 0, 0, RAYWHITE);

		// Handle reagent button interactions
		for (int i = 0; i < 12; i++)
		{
			bool isMouseOver = CheckCollisionPointRec(mousePosition, buttons[i]);

			if (isMouseOver && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				visibleReagentIndex = i;
			}
		}

		// Handle space key for closing the reagent info
		if (IsKeyDown(KEY_SPACE))
		{
			visibleReagentIndex = -1;
		}

		// Display reagent information if selected
		if (visibleReagentIndex != -1)
		{
			Vector2 pos = reagentPositions[visibleReagentIndex];
			DrawTexture(reagents[visibleReagentIndex], pos.x, pos.y, RAYWHITE);
		}

		// Check if the mouse is over the exit button
		bool isMouseOverExitButton = CheckCollisionPointRec(mousePosition, exitButton);
		DrawTextEx(font, "Exit", Vector2{ exitButtonPosition.x + 100, exitButtonPosition.y + 25 }, 50, 10, isMouseOverExitButton ? BLACK : WHITE);

		if (isMouseOverExitButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			break;
		}

		EndDrawing();
	}

	UnloadTexture(background); // Unload the background texture
	UnloadFont(font); // Unload the font

	// Unload textures
	for (int i = 0; i < 12; i++)
	{
		UnloadTexture(reagents[i]);
	}
}