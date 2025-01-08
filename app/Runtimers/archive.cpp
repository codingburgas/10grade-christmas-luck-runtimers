#include "archive.h"

bool checkIfFileExists(const string& fileName)
{
    ifstream file(fileName);
    return file.good();
}

vector<Chemical> LoadInventoryFromFile(const string& fileName) {
    vector<Chemical> inventory;
    ifstream file(fileName);

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Chemical chemical;

        getline(ss, chemical.name, ',');
        getline(ss, chemical.chemicalFormula, ',');
        ss >> chemical.quantity;
        ss.ignore();
        inventory.push_back(chemical);
    }
    file.close();
    return inventory;
};

void saveInventoryFile(const string& fileName, vector<Chemical>& inventory)
{
    ofstream file(fileName, ios::trunc);

    for (const auto& chemical : inventory) {
        file << chemical.name << ", "
            << chemical.chemicalFormula << ", "
            << chemical.quantity << endl;
    }

    file.close();
}

vector<Chemical> searchInventory(const string& query, const vector<Chemical>& inventory) {
    vector<Chemical> result;
    for (const auto& chemical : inventory) {
        if (chemical.chemicalFormula.find(query) != string::npos) {
            result.push_back(chemical);
            break; // Stop after finding the first match
        }
    }
    return result;
}

// Function to sort chemicals 

void sortInventory(vector<Chemical>& inventory) 
{
    sort(inventory.begin(), inventory.end(), [](const Chemical& a, const Chemical& b) 
    {
        return a.quantity > b.quantity; // Compare quantities
     });
}


void randomSortInventory(vector<Chemical>& inventory) {

    random_device rd;

    mt19937 g(rd());

    shuffle(inventory.begin(), inventory.end(), g);

}

void displayArchive()
{
    Font font = LoadFont("../font/font.ttf");

    const int screenWidth = 1920;
    const int screenHeight = 1080;

    Vector2 exitButtonPosition = { GetScreenWidth() / 2 + 650, GetScreenHeight() / 2 + 425 };
    Vector2 tabletButtonPosition = { GetScreenWidth() / 2 - 200, GetScreenHeight() / 2 - 100 };

    const Rectangle exitButton = { exitButtonPosition.x + 90, exitButtonPosition.y + 20, 115, 50 };
    const Rectangle tabletButton = { tabletButtonPosition.x - 50, tabletButtonPosition.y - 100, 400, 200 };

    Texture2D background = LoadTexture("../assets/archive/archiveBackground.png");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        Vector2 mousePosition = GetMousePosition();

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, RAYWHITE);

        bool isMouseOverExitButton = CheckCollisionPointRec(mousePosition, exitButton);
        bool isMouseOverTabletButton = CheckCollisionPointRec(mousePosition, tabletButton);

        if (CheckCollisionPointRec(mousePosition, tabletButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            displayTablet();
        }


        DrawTextEx(font, "Exit", Vector2{ exitButtonPosition.x + 100, exitButtonPosition.y + 25 }, 50, 10, isMouseOverExitButton ? BLACK : WHITE);

        if (CheckCollisionPointRec(mousePosition, exitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            break;
        }

        EndDrawing();
    }

    UnloadTexture(background);
    UnloadFont(font);

}

vector<Chemical> defaultElements = {
    Chemical{"Hydrogen", "H2", 10},
    Chemical{"Oxygen", "O2", 10},
    Chemical{"Sodium", "Na", 10},
    Chemical{"Calcium", "Ca", 10},
    Chemical{"Chlorine", "Cl2", 10},
    Chemical{"Nitrogen", "N2", 10},
    Chemical{"Water", "H2O", 10},
    Chemical{"Sodium Hydroxide", "NaOH", 10},
    Chemical{"Calcium Hydroxide", "Ca(OH)2", 10},
    Chemical{"Nitric Acid", "HNO3", 10},
    Chemical{"Hydrochloric Acid", "HCl", 10},
    Chemical{"Sodium Chloride", "NaCl", 10},
};

void displayTablet()
{
    // Check if file exists
    if (!checkIfFileExists("../data/inventory.txt"))
    {
        saveInventoryFile("../data/inventory.txt", defaultElements);
    }

    const int screenWidth = 1920;
    const int screenHeight = 1080;

    Font font = LoadFont("../font/font.ttf");

    Vector2 exitButtonPosition = { GetScreenWidth() / 2 + 650, GetScreenHeight() / 2 + 425 };
    Vector2 filterButtonPosition = { GetScreenWidth() / 2 + 620, GetScreenHeight() / 2 - 500 };
    Vector2 searchButtonPosition = { GetScreenWidth() / 2 + 80, GetScreenHeight() / 2 - 280 };
    Vector2 textBoxButtonPosition = { GetScreenWidth() / 2 + 190, GetScreenHeight() / 2 - 260 };
    Vector2 closeButtonPosition = { GetScreenWidth() / 2 + 650, GetScreenHeight() / 2 - 260 };
    Vector2 sortButtonPosition = { GetScreenWidth() / 2 + 730, GetScreenHeight() / 2 + 250 };

    const Rectangle exitButton = { exitButtonPosition.x + 90, exitButtonPosition.y + 20, 115, 50 };
    const Rectangle filterButton = { filterButtonPosition.x + 90, filterButtonPosition.y + 20, 150, 120 };
    const Rectangle searchButton = { searchButtonPosition.x + 90, searchButtonPosition.y + 20, 100, 120 };
    const Rectangle textBoxButton = { textBoxButtonPosition.x + 90, textBoxButtonPosition.y + 20, 300, 120 };
    const Rectangle closeButton = { closeButtonPosition.x + 90, closeButtonPosition.y + 20, 70, 70 };
    const Rectangle sortButton = { sortButtonPosition.x + 0, sortButtonPosition.y + 20, 150, 70 };
    const Rectangle searchResultsBox = { GetScreenWidth() / 2 + 550, GetScreenHeight() / 2 + 250, 250, 200 }; // Textbox for search results

    Texture2D background = LoadTexture("../assets/archive/tabletInside.png");

    vector<Chemical> inventory = LoadInventoryFromFile("../data/inventory.txt");

    randomSortInventory(inventory); // Randomize inventory initially

    bool showInterface = false;
    bool textBoxActive = false;
    bool showSearchResults = false;

    Chemical newChemical;

    string queryText = "";

    vector<Chemical> searchResults;

    // Define rectangles for plus signs
    vector<Rectangle> plusSigns;

    for (int i = 0; i < inventory.size(); i++)
    {
        plusSigns.push_back({ 1500, 540 + (float)i * 28, 20, 20 });
    }

    bool showInventory = false; 

    int frameCounter = 0; 

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        frameCounter++; 

        Vector2 mousePosition = GetMousePosition();

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, RAYWHITE);

        bool isMouseOverExitButton = CheckCollisionPointRec(mousePosition, exitButton);

        DrawTextEx(font, "Exit", Vector2{ exitButtonPosition.x + 100, exitButtonPosition.y + 25 }, 50, 10, isMouseOverExitButton ? BLACK : WHITE);

        if (CheckCollisionPointRec(mousePosition, exitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            break;
        }

        bool isMouseOverFilterButton = CheckCollisionPointRec(mousePosition, filterButton);

        // Check if the test tube button is clicked
        if (CheckCollisionPointRec(mousePosition, filterButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            showInventory = true; // Show inventory when Test Tube is clicked
        }

        // Hide inventory when Space Bar is pressed
        if (IsKeyPressed(KEY_SPACE))
        {
            showInventory = false; 
        }

        if (showInventory)
        {
            int x = 1200;
            int y = 540; 

            // Draw the sort button 
            bool isMouseOverSortButton = CheckCollisionPointRec(mousePosition, sortButton);

            DrawRectangleRec(sortButton, isMouseOverSortButton ? BLUE : SKYBLUE);
            DrawTextEx(font, "SORT", Vector2{ sortButton.x + 17, sortButton.y + 15 }, 40, 10, WHITE);

            if (CheckCollisionPointRec(mousePosition, sortButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                sortInventory(inventory);
                saveInventoryFile("../data/inventory.txt", inventory); // Save updated inventory
            }

            DrawTextEx(font, "Name, quantity\n", Vector2{ (float)x, (float)y - 50 }, 30, 5, SKYBLUE);

            for (int i = 0; i < inventory.size(); i++)
            {
                const auto& chem = inventory[i];
                string chemInfo = chem.name + ", " + to_string(chem.quantity);

                DrawTextEx(font, chemInfo.c_str(), Vector2{ (float)x, (float)y }, 20, 3, SKYBLUE);

                // Draw plus sign

                bool isMouseOverPlusSign = CheckCollisionPointRec(mousePosition, plusSigns[i]);
                DrawRectangleRec(plusSigns[i], isMouseOverPlusSign ? GREEN : LIGHTGRAY);
                DrawText("+", plusSigns[i].x + 5, plusSigns[i].y, 20, BLACK);

                // Increase quantity when plus sign is clicked
                if (CheckCollisionPointRec(mousePosition, plusSigns[i]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    inventory[i].quantity++;
                    saveInventoryFile("../data/inventory.txt", inventory); // Save updated inventory
                }

                y += 28;


            }
        }

        // Handle text input for search
        DrawTextEx(font, queryText.c_str(), Vector2{ textBoxButton.x + 15, textBoxButton.y + 15 }, 40, 2, BLACK);

        // Blink cursor 
        if (textBoxActive && (frameCounter / 30) % 2 == 0)
        {
            float cursorX = textBoxButton.x + 20 + MeasureTextEx(font, queryText.c_str(), 40, 2).x + 4; 
            DrawRectangle(cursorX, textBoxButton.y + 15, 2, 40, BLACK);
        }
    
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            textBoxActive = CheckCollisionPointRec(mousePosition, textBoxButton);
            // Perform search when the search button is clicked

            bool isMouseOverSearchButton = CheckCollisionPointRec(mousePosition, searchButton);

            if (CheckCollisionPointRec(mousePosition, searchButton))
            {
                searchResults = searchInventory(queryText, inventory);
                showSearchResults = true;
            }

            // Clear search results when the close button is clicked
            if (CheckCollisionPointRec(mousePosition, closeButton))
            {
                queryText.clear();

                searchResults.clear();

                showSearchResults = false;
            }
        }

        if (textBoxActive)
        {
            int key = GetCharPressed();

            while (key > 0)
            {
                if ((key >= 32 && key <= 125) && queryText.length() < 50)
                {
                    queryText += static_cast<char>(key);
                }
                key = GetCharPressed();
            }

            if (IsKeyPressed(KEY_BACKSPACE) && !queryText.empty())
            {
                queryText.pop_back();
            }
        }

        // Display search results
        if (showSearchResults)
        {
            int wid = 1140;
            int hei = 500;

            DrawTextEx(font, "Search Results:", Vector2{ (float)wid, (float)hei - 10}, 40, 5, SKYBLUE);

            int y = searchResultsBox.y + 30;

            for (const auto& chem : searchResults)
            {
                string chemInfo = chem.name + "\nQuantity: " + to_string(chem.quantity);

                DrawTextEx(font, chemInfo.c_str(), Vector2{ (float)wid, (float)hei + 50 }, 25, 5, SKYBLUE);

                y += 30;
            }
        }

        // Draw the close button 
        bool isMouseOverCloseButton = CheckCollisionPointRec(mousePosition, closeButton);
        DrawRectangleRec(closeButton, isMouseOverCloseButton ? RED : BLUE);
        DrawTextEx(font, "X", Vector2{ closeButton.x + 23, closeButton.y + 15 }, 40, 10, WHITE);

        EndDrawing();
    }

    UnloadTexture(background);
    UnloadFont(font);

    // Randomize inventory and save to file
    randomSortInventory(inventory);
    saveInventoryFile("../inventory.txt", inventory);
}