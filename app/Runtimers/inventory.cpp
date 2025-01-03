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

//void displayInventory(vector<Chemical>& inventory) {
    //for (const auto& chem : inventory) {
        //cout << "Name: " << chem.name
            //<< "casNumber: " << chem.casNumber
            //<< "expiryDate: " << chem.expiryDate
            //<< "hazardLevel: " << chem.hazardLevel
            //<< "quantity: " << chem.quantity
            //<< endl;
    //}
//}

void displayInventory()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "RUNTIMERS");

    Image logo = LoadImage("../assets/logo/logoTransparent.png");

    SetWindowIcon(logo);

    Vector2 exitButtonPosition = { GetScreenWidth() / 2 + 650, GetScreenHeight() / 2 + 425 };
    Vector2 shelfButtonPosition = { GetScreenWidth() / 2 + 600, GetScreenHeight() / 2 - 50 };
    Vector2 tableButtonPosition = { GetScreenWidth() / 2 - 160, GetScreenHeight() / 2 + 350 };


    const Rectangle exitButton = { exitButtonPosition.x + 90, exitButtonPosition.y + 20, 115, 50 };
    const Rectangle shelfButton = { shelfButtonPosition.x , shelfButtonPosition.y , 400, 500 };
    const Rectangle tableButton = { shelfButtonPosition.x , shelfButtonPosition.y , 250, 100 };

    Texture2D background = LoadTexture("../assets/inventory/labBackground.png");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        Vector2 mousePosition = GetMousePosition();

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, RAYWHITE);

        bool isMouseOverShelfButton = CheckCollisionPointRec(mousePosition, shelfButton);

        if (CheckCollisionPointRec(mousePosition, shelfButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            displayShelfInside();
        }

        bool isMouseOverExitButton = CheckCollisionPointRec(mousePosition, exitButton);

        DrawText("Exit", exitButtonPosition.x + 100, exitButtonPosition.y + 55, 50, isMouseOverExitButton ? BLACK : WHITE);

        if (CheckCollisionPointRec(mousePosition, exitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            return;
        }

        EndDrawing();
    }

    UnloadTexture(background);
}

void displayShelfInside()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "RUNTIMERS");

    Image logo = LoadImage("../assets/logo/logoTransparent.png");

    SetWindowIcon(logo);

    Vector2 exitButtonPosition = { GetScreenWidth() / 2 + 650, GetScreenHeight() / 2 + 425 };

    const Rectangle exitButton = { exitButtonPosition.x + 90, exitButtonPosition.y + 20, 115, 50 };

    Texture2D background = LoadTexture("../assets/inventory/shelfInside.png");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        Vector2 mousePosition = GetMousePosition();

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, RAYWHITE);

        bool isMouseOverExitButton = CheckCollisionPointRec(mousePosition, exitButton);

        DrawText("Exit", exitButtonPosition.x + 100, exitButtonPosition.y + 25, 50, isMouseOverExitButton ? BLACK : WHITE);

        if (CheckCollisionPointRec(mousePosition, exitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            return;
        }

        EndDrawing();
    }

    UnloadTexture(background);
}

