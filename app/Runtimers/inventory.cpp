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


    Image logo = LoadImage("../assets/logo/logoTransparent.png");

    SetWindowIcon(logo);

    Vector2 exitButtonPosition = { GetScreenWidth() / 2 + 650, GetScreenHeight() / 2 + 425 };
    Vector2 shelfButtonPosition = { GetScreenWidth() / 2 + 600, GetScreenHeight() / 2 - 50 };
    Vector2 chembenchButtonPosition = { GetScreenWidth() / 2 - 650, GetScreenHeight() / 2 + 100 };


    const Rectangle exitButton = { exitButtonPosition.x + 90, exitButtonPosition.y + 20, 115, 70 };
    const Rectangle shelfButton = { shelfButtonPosition.x , shelfButtonPosition.y , 400, 500 };
    const Rectangle chembenchButton = { chembenchButtonPosition.x , chembenchButtonPosition.y , 600, 300 };

    Texture2D background = LoadTexture("../assets/inventory/labBackground.png");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        Vector2 mousePosition = GetMousePosition();

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, RAYWHITE);

        bool isMouseOverChembenchButton = CheckCollisionPointRec(mousePosition, chembenchButton);

        if (CheckCollisionPointRec(mousePosition, chembenchButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            displayChembenchZoomed();
        }

        bool isMouseOverShelfButton = CheckCollisionPointRec(mousePosition, shelfButton);

        if (CheckCollisionPointRec(mousePosition, shelfButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            displayShelfInside();
        }

        bool isMouseOverExitButton = CheckCollisionPointRec(mousePosition, exitButton);

        DrawText("Exit", exitButtonPosition.x + 100, exitButtonPosition.y + 55, 50, isMouseOverExitButton ? BLACK : WHITE);

        if (CheckCollisionPointRec(mousePosition, exitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            break;
        }

        EndDrawing();
    }

    UnloadTexture(background);
}

void displayChembenchZoomed()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    Image logo = LoadImage("../assets/logo/logoTransparent.png");

    SetWindowIcon(logo);

    Vector2 exitButtonPosition = { GetScreenWidth() / 2 + 650, GetScreenHeight() / 2 + 425 };

    const Rectangle exitButton = { exitButtonPosition.x + 90, exitButtonPosition.y + 20, 115, 70 };

    Texture2D background = LoadTexture("../assets/inventory/chembenchZoomed/chembenchZoomed.png");

    Texture2D H2O = LoadTexture("../assets/inventory/chembenchZoomed/cards/H2OCard.png");
    Texture2D HCl = LoadTexture("../assets/inventory/chembenchZoomed/cards/HClCard.png");
    Texture2D HNO3 = LoadTexture("../assets/inventory/chembenchZoomed/cards/HNO3Card.png");
    Texture2D NaOH = LoadTexture("../assets/inventory/chembenchZoomed/cards/NaOHCard.png");
    Texture2D CaOH2 = LoadTexture("../assets/inventory/chembenchZoomed/cards/CaOH2Card.png");
    Texture2D NaCl = LoadTexture("../assets/inventory/chembenchZoomed/cards/NaClCard.png");
    Texture2D O2 = LoadTexture("../assets/inventory/chembenchZoomed/cards/O2Card.png");
    Texture2D H2 = LoadTexture("../assets/inventory/chembenchZoomed/cards/H2Card.png");
    Texture2D N2 = LoadTexture("../assets/inventory/chembenchZoomed/cards/N2Card.png");
    Texture2D Cl2 = LoadTexture("../assets/inventory/chembenchZoomed/cards/Cl2Card.png");
    Texture2D Na = LoadTexture("../assets/inventory/chembenchZoomed/cards/NaCard.png");
    Texture2D Ca = LoadTexture("../assets/inventory/chembenchZoomed/cards/CaCard.png");


    float x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8, x9, y9, x10, y10, x11, y11, x12, y12;
    x1 = 690, y1 = - 170, x2 = 840, y2 = - 170, x3 = 870, y3 = - 430, x4 = 490, y4 = - 228;
    x5 = 820, y5 = - 235, x6 = 730, y6 = - 230, x7 = 865, y7 = - 230, x8 = 280, y8 = 62;
    x9 = 610, y9 = - 10, x10 = 765, y10 = 135, x11 = 680, y11 = 383, x12 = 740, y12 = 210;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        Vector2 mousePosition = GetMousePosition();

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, RAYWHITE);

        DrawTexture(H2, x1, y1, RAYWHITE);
        DrawTexture(H2O, x2, y2, RAYWHITE);
        DrawTexture(O2, x3, y3, RAYWHITE);
        DrawTexture(Cl2, x4, y4, RAYWHITE);
        DrawTexture(N2, x5, y5, RAYWHITE);
        DrawTexture(Ca, x6, y6, RAYWHITE);
        DrawTexture(Na, x7, y7, RAYWHITE);
        DrawTexture(HCl, x8, y8, RAYWHITE);
        DrawTexture(NaOH, x9, y9, RAYWHITE);
        DrawTexture(NaCl, x10, y10, RAYWHITE);
        DrawTexture(HNO3, x11, y11, RAYWHITE);
        DrawTexture(CaOH2, x12, y12, RAYWHITE);


        bool isMouseOverExitButton = CheckCollisionPointRec(mousePosition, exitButton);

        DrawText("Exit", exitButtonPosition.x + 100, exitButtonPosition.y + 55, 50, isMouseOverExitButton ? BLACK : WHITE);

        if (CheckCollisionPointRec(mousePosition, exitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            break;
        }

        EndDrawing();
    }

    UnloadTexture(background);
    UnloadTexture(H2O);
    UnloadTexture(HCl);
    UnloadTexture(HNO3);
    UnloadTexture(NaOH);
    UnloadTexture(CaOH2);
    UnloadTexture(NaCl);
    UnloadTexture(O2);
    UnloadTexture(H2);
    UnloadTexture(N2);
    UnloadTexture(Cl2);
    UnloadTexture(Na);
    UnloadTexture(Ca);
}

void displayShelfInside()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;


    Image logo = LoadImage("../assets/logo/logoTransparent.png");

    SetWindowIcon(logo);

    Vector2 exitButtonPosition = { GetScreenWidth() / 2 + 650, GetScreenHeight() / 2 + 425 };

    Vector2 H2OButtonPosition = { GetScreenWidth() / 2 - 550, GetScreenHeight() / 2 - 330 };
    Vector2 HClButtonPosition = { GetScreenWidth() / 2 + 650, GetScreenHeight() / 2 + 425 };
    Vector2 HNO3ButtonPosition = { GetScreenWidth() / 2 + 650, GetScreenHeight() / 2 + 425 };
    Vector2 NaOHButtonPosition = { GetScreenWidth() / 2 + 650, GetScreenHeight() / 2 + 425 };
    Vector2 CaOH2ButtonPosition = { GetScreenWidth() / 2 + 650, GetScreenHeight() / 2 + 425 };
    Vector2 NaClButtonPosition = { GetScreenWidth() / 2 + 650, GetScreenHeight() / 2 + 425 };
    Vector2 O2ButtonPosition = { GetScreenWidth() / 2 + 650, GetScreenHeight() / 2 + 425 };
    Vector2 H2ButtonPosition = { GetScreenWidth() / 2 + 650, GetScreenHeight() / 2 + 425 };
    Vector2 N2ButtonPosition = { GetScreenWidth() / 2 - 600, GetScreenHeight() / 2 + 100 };
    Vector2 Cl2ButtonPosition = { GetScreenWidth() / 2 + 650, GetScreenHeight() / 2 + 425 };
    Vector2 NaButtonPosition = { GetScreenWidth() / 2 + 650, GetScreenHeight() / 2 + 425 };
    Vector2 CaButtonPosition = { GetScreenWidth() / 2 + 650, GetScreenHeight() / 2 + 425 };

    const Rectangle exitButton = { exitButtonPosition.x + 90, exitButtonPosition.y + 20, 115, 50 };

    const Rectangle H2OButton = { H2OButtonPosition.x + 90, H2OButtonPosition.y + 20, 200, 100 };
    const Rectangle HClButton = { HClButtonPosition.x + 90, HClButtonPosition.y + 20, 115, 50 };
    const Rectangle HNO3Button = { HNO3ButtonPosition.x + 90, HNO3ButtonPosition.y + 20, 115, 50 };
    const Rectangle NaOHButton = { NaOHButtonPosition.x + 90, NaOHButtonPosition.y + 20, 115, 50 };
    const Rectangle CaOH2Button = { CaOH2ButtonPosition.x + 90, CaOH2ButtonPosition.y + 20, 115, 50 };
    const Rectangle NaClButton = { NaClButtonPosition.x + 90, NaClButtonPosition.y + 20, 115, 50 };
    const Rectangle O2Button = { O2ButtonPosition.x + 90, O2ButtonPosition.y + 20, 115, 50 };
    const Rectangle H2Button = { H2ButtonPosition.x + 90, H2ButtonPosition.y + 20, 115, 50 };
    const Rectangle N2Button = { N2ButtonPosition.x + 90, N2ButtonPosition.y + 20, 115, 50 };
    const Rectangle Cl2Button = { Cl2ButtonPosition.x + 90, Cl2ButtonPosition.y + 20, 115, 50 };
    const Rectangle NaButton = { NaButtonPosition.x + 90, NaButtonPosition.y + 20, 115, 50 };
    const Rectangle CaButton = { CaButtonPosition.x + 90, CaButtonPosition.y + 20, 115, 50 };


    Texture2D background = LoadTexture("../assets/inventory/shelfInside.png");

    Texture2D H2O = LoadTexture("../assets/inventory/info/H2OInfo.png");
    Texture2D HCl = LoadTexture("../assets/inventory/info/HClInfo.png");
    Texture2D HNO3 = LoadTexture("../assets/inventory/info/HNO3Info.png");
    Texture2D NaOH = LoadTexture("../assets/inventory/info/NaOHInfo.png");
    Texture2D CaOH2 = LoadTexture("../assets/inventory/info/CaOH2Info.png");
    Texture2D NaCl = LoadTexture("../assets/inventory/info/NaClInfo.png");
    Texture2D O2 = LoadTexture("../assets/inventory/info/O2Info.png");
    Texture2D H2 = LoadTexture("../assets/inventory/info/H2Info.png");
    Texture2D N2 = LoadTexture("../assets/inventory/info/N2Info.png");
    Texture2D Cl2 = LoadTexture("../assets/inventory/info/Cl2Info.png");
    Texture2D Na = LoadTexture("../assets/inventory/info/NaInfo.png");
    Texture2D Ca = LoadTexture("../assets/inventory/info/CaInfo.png");


    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        Vector2 mousePosition = GetMousePosition();
        bool isH2OVisible = false;
        bool isHClVisible = false;

        if (CheckCollisionPointRec(mousePosition, H2OButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            isH2OVisible = true;
        }
        if (CheckCollisionPointRec(mousePosition, HClButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            isHClVisible = true;
        }
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, RAYWHITE);

        bool isMouseOverExitButton = CheckCollisionPointRec(mousePosition, exitButton);

        bool isMouseOverH2OButton = CheckCollisionPointRec(mousePosition, H2OButton);
        bool isMouseOverHClButton = CheckCollisionPointRec(mousePosition, HClButton);
        bool isMouseOverHNO3Button = CheckCollisionPointRec(mousePosition, HNO3Button);
        bool isMouseOverNaOHButton = CheckCollisionPointRec(mousePosition, NaOHButton);
        bool isMouseOverCaOH2Button = CheckCollisionPointRec(mousePosition, CaOH2Button);
        bool isMouseOverNaClButton = CheckCollisionPointRec(mousePosition, NaClButton);
        bool isMouseOverO2Button = CheckCollisionPointRec(mousePosition, O2Button);
        bool isMouseOverH2Button = CheckCollisionPointRec(mousePosition, H2Button);
        bool isMouseOverN2Button = CheckCollisionPointRec(mousePosition, N2Button);
        bool isMouseOverCl2Button = CheckCollisionPointRec(mousePosition, Cl2Button);
        bool isMouseOverNaButton = CheckCollisionPointRec(mousePosition, NaButton);
        bool isMouseOverCaButton = CheckCollisionPointRec(mousePosition, CaButton);


        DrawText("Exit", exitButtonPosition.x + 100, exitButtonPosition.y + 25, 50, isMouseOverExitButton ? BLACK : WHITE);

        if (CheckCollisionPointRec(mousePosition, exitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            break;
        }

        if (isH2OVisible)
        {
            DrawTexture(H2O, 400, 200, RAYWHITE); // Adjust position as needed
        }
        if (isHClVisible)
        {
            DrawTexture(HCl, HClButtonPosition.x, HClButtonPosition.y + 60, RAYWHITE);
        }

        if (CheckCollisionPointRec(mousePosition, exitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            DrawTexture(H2O, H2OButtonPosition.x + 90, H2OButtonPosition.y + 20, RAYWHITE);
        }
        if (CheckCollisionPointRec(mousePosition, exitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            DrawTexture(H2O, H2OButtonPosition.x + 90, H2OButtonPosition.y + 20, RAYWHITE);
        }
        if (CheckCollisionPointRec(mousePosition, exitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            DrawTexture(H2O, H2OButtonPosition.x + 90, H2OButtonPosition.y + 20, RAYWHITE);
        }
        if (CheckCollisionPointRec(mousePosition, exitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            DrawTexture(H2O, H2OButtonPosition.x + 90, H2OButtonPosition.y + 20, RAYWHITE);
        }
        if (CheckCollisionPointRec(mousePosition, exitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            DrawTexture(H2O, H2OButtonPosition.x + 90, H2OButtonPosition.y + 20, RAYWHITE);
        }
        if (CheckCollisionPointRec(mousePosition, exitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            DrawTexture(H2O, H2OButtonPosition.x + 90, H2OButtonPosition.y + 20, RAYWHITE);
        }
        if (CheckCollisionPointRec(mousePosition, exitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            DrawTexture(H2O, H2OButtonPosition.x + 90, H2OButtonPosition.y + 20, RAYWHITE);
        }
        if (CheckCollisionPointRec(mousePosition, exitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            DrawTexture(H2O, H2OButtonPosition.x + 90, H2OButtonPosition.y + 20, RAYWHITE);
        }
        if (CheckCollisionPointRec(mousePosition, exitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            DrawTexture(H2O, H2OButtonPosition.x + 90, H2OButtonPosition.y + 20, RAYWHITE);
        }
        if (CheckCollisionPointRec(mousePosition, exitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            DrawTexture(H2O, H2OButtonPosition.x + 90, H2OButtonPosition.y + 20, RAYWHITE);
        }

        EndDrawing();
    }

    UnloadTexture(background);
    UnloadTexture(H2O);
    UnloadTexture(HCl);
    UnloadTexture(HNO3);
    UnloadTexture(NaOH);
    UnloadTexture(CaOH2);
    UnloadTexture(NaCl);
    UnloadTexture(O2);
    UnloadTexture(H2);
    UnloadTexture(N2);
    UnloadTexture(Cl2);
    UnloadTexture(Na);
    UnloadTexture(Ca);
}


