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

void saveInventoryFile(const string& fileName, vector<Chemical>& inventory) {
    ofstream file(fileName);
    for (const auto& chemical : inventory) {
        file << chemical.name << ", "
            << chemical.chemicalFormula << ", "
            << chemical.quantity << endl;
    }
    file.close();
}

vector<Chemical> searchInventory(const string& query, const vector<Chemical>& inventory) {
    vector<Chemical>result;
    for (const auto& chemical : inventory) {
        if (chemical.chemicalFormula.find(query) != string::npos) {
            result.push_back(chemical);
        }
    }
    return result;
}

// Function to sort chemicals alphabetically

void sortInventory(vector<Chemical>& inventory) {

    sort(inventory.begin(), inventory.end(), [](const Chemical& a, const Chemical& b) {

        return a.name < b.name; // Compare names

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

    Image logo = LoadImage("../assets/logo/logoTransparent.png");

    SetWindowIcon(logo);

    Vector2 exitButtonPosition = { GetScreenWidth() / 2 + 650, GetScreenHeight() / 2 + 425 };
    Vector2 tabletButtonPosition = { GetScreenWidth() / 2 - 200, GetScreenHeight() / 2 - 100 };

    const Rectangle exitButton = { exitButtonPosition.x + 90, exitButtonPosition.y + 20, 115, 50 };
    const Rectangle tabletButton = { tabletButtonPosition.x - 50, tabletButtonPosition.y, 300, 150 };

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

vector<Chemical> defaultElements = 
{
   Chemical 
   {
       "Hydrogen",
       "H2",
       0
   },
   Chemical
   {
       "Oxygen",
       "O2",
       0
   },
   Chemical
    {
        "Sodium",
        "Na",
        0
    },
    Chemical
    {
        "Calcium",
        "Ca",
        0
    },
    Chemical
    {
        "Chlorine",
        "Cl2",
        0
    },
    Chemical
    {
        "Nitrogen",
        "N2",
        0
    },
    Chemical
    {
        "Sodium Hydroxide",
        "NaOH",
        0
    },
   Chemical
    {
        "Calcium Hydroxide",
        "Ca(OH)2",
        0
    },
    Chemical
    {
        "Nitric Acid",
        "HNO3",
        0
    },
    Chemical
    {
        "Hydrochloric Acid",
        "HCl",
        0
    },
    Chemical
    {
        "Sodium Chloride",
        "NaCl",
        0
    },
    Chemical
    {
        "Water",
        "N2",
        0
    }
};

Rectangle computerRect = { 50, 10, 100, 100 };

// Area of the test tube on the interface (top right in the computer icon)

Rectangle testTubeRect = { 1080, 20, 60, 60 };

Rectangle textBox = 
{

    (GetScreenWidth() - 300) / 2 + 940,
    (GetScreenHeight() - 50) / 2 + 210,
    300,
    50
}; // Textbox for user input

Rectangle searchButtonRect = 
{
    textBox.x - 40, // Position the search button to the left of the text box
    textBox.y,
    40,
    50
}; // Rectangle for the search button

Rectangle closeButtonRect = 
{
    textBox.x + textBox.width + 10, // Position the close button to the right of the text box
    textBox.y,
    40,
    50
}; // Rectangle for the close button

Rectangle searchResultsBox = 
{
    940,
    270,
    250,
    200
}; // Textbox for search results

void handleElementClick(const string elementName, const int quantity)
{
    vector<Chemical> inventory = LoadInventoryFromFile("inventory.txt");

    for (Chemical& el : inventory)
    {
        if (el.name == elementName)
        {
            el.quantity = quantity;

            saveInventoryFile("inventory.txt", inventory);

            return;
        }
    }
}

void handleRemoveElement(const string elementName)
{
    vector<Chemical> inventory = LoadInventoryFromFile("inventory.txt");

    inventory.erase(std::find_if(inventory.begin(), inventory.end(),
        [&](Chemical const& b) { return b.name == elementName; }));

    saveInventoryFile("inventory.txt", inventory);

}

void displayTablet()
{
    // Check if file exists
    if (!checkIfFileExists("inventory.txt"))
    {
        saveInventoryFile("inventory.txt", defaultElements);
    }

    const int screenWidth = 1920;
    const int screenHeight = 1080;

    Font font = LoadFont("../font/font.ttf");

    Image logo = LoadImage("../assets/logo/logoTransparent.png");

    SetWindowIcon(logo);

    Vector2 exitButtonPosition = { GetScreenWidth() / 2 + 650, GetScreenHeight() / 2 + 425 };

    const Rectangle exitButton = { exitButtonPosition.x + 90, exitButtonPosition.y + 20, 115, 50 };

    Texture2D background = LoadTexture("../assets/archive/tabletInside.png");

    vector<Chemical> inventory = LoadInventoryFromFile("inventory.txt");

    randomSortInventory(inventory); // Randomize inventory initially

    bool showInterface = false;
    bool textBoxActive = false;
    bool showSearchResults = false;

    Chemical newChemical;

    string queryText = "";

    vector<Chemical> searchResults;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
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

        // Display inventory list

        int y = 330; // Move down
        int x = searchResultsBox.x - 230; // Move left

        DrawTextEx(font, "Lab Inventory: \nName, quantity", Vector2{ (float)x, (float)280 }, 20, 5, SKYBLUE);

        for (const auto& chem : inventory)
        {
            string chemInfo = chem.name + ", " + to_string(chem.quantity);

            DrawTextEx(font, chemInfo.c_str(), Vector2{ (float)x, (float)y }, 20, 3, SKYBLUE);

            y += 28;
        }

        // Check for clicks on the test tube
        if (CheckCollisionPointRec(GetMousePosition(), testTubeRect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            sortInventory(inventory); // Sort the inventory
            saveInventoryFile("inventory.txt", inventory); // Save the sorted inventory
        }

        // Handle text input for search
        DrawTextEx(font, queryText.c_str(), Vector2{ textBox.x + 5, textBox.y + 10 }, 20, 2, BLACK);

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            textBoxActive = CheckCollisionPointRec(mousePosition, textBox);

            // Perform search when the search button is clicked
            if (CheckCollisionPointRec(mousePosition, searchButtonRect))
            {
                searchResults = searchInventory(queryText, inventory);
                showSearchResults = true;
            }

            // Clear search results when the close button is clicked
            if (CheckCollisionPointRec(mousePosition, closeButtonRect))
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
            DrawRectangleRec(searchResultsBox, { 0, 110, 216, 255 });

            DrawTextEx(font, "Search Results:", Vector2{ searchResultsBox.x + 5, searchResultsBox.y + 5 }, 20, 5, SKYBLUE);

            int y = searchResultsBox.y + 30;

            for (const auto& chem : searchResults)
            {
                string chemInfo = chem.name + "\nQuantity: " + to_string(chem.quantity);

                DrawTextEx(font, chemInfo.c_str(), Vector2{ searchResultsBox.x + 5, (float)y }, 20, 5, SKYBLUE);

                y += 30;
            }
        }
        // Draw the close button

        DrawRectangleRec(closeButtonRect, { 255, 0, 0, 255 });
        DrawTextEx(font, "X", Vector2{ closeButtonRect.x + 10, closeButtonRect.y + 10 }, 20, 10, WHITE);

        EndDrawing();

    }

    UnloadTexture(background);
    UnloadFont(font);

    // Randomize inventory and save to file
    randomSortInventory(inventory);
    saveInventoryFile("inventory.txt", inventory);
}
   
