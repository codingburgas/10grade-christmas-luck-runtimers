#include "inventory.h"


void displayInventoryBg()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    Font font = LoadFont("../font/font.ttf");

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
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    Font font = LoadFont("../font/font.ttf");

    Image logo = LoadImage("../assets/logo/logoTransparent.png");

    SetWindowIcon(logo);

    Vector2 exitButtonPosition = { GetScreenWidth() / 2 + 650, GetScreenHeight() / 2 + 425 };

    const Rectangle exitButton = { exitButtonPosition.x + 90, exitButtonPosition.y + 20, 115, 50 };

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
    x1 = 690, y1 = -170, x2 = 840, y2 = -170, x3 = 870, y3 = -430, x4 = 490, y4 = -228;
    x5 = 820, y5 = -235, x6 = 730, y6 = -230, x7 = 865, y7 = -230, x8 = 280, y8 = 62;
    x9 = 610, y9 = -10, x10 = 765, y10 = 135, x11 = 680, y11 = 383, x12 = 740, y12 = 210;

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

        DrawTextEx(font, "Exit", Vector2{ exitButtonPosition.x + 100, exitButtonPosition.y + 25 }, 50, 10, isMouseOverExitButton ? BLACK : WHITE);

        if (CheckCollisionPointRec(mousePosition, exitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            break;
        }

        EndDrawing();
    }

    UnloadTexture(background);
    UnloadFont(font);

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

    Font font = LoadFont("../font/font.ttf");

    Image logo = LoadImage("../assets/logo/logoTransparent.png");
    SetWindowIcon(logo);

    Vector2 exitButtonPosition = { GetScreenWidth() / 2 + 650, GetScreenHeight() / 2 + 425 };

    Vector2 buttonPositions[] = {
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

    const Rectangle exitButton = { exitButtonPosition.x + 90, exitButtonPosition.y + 20, 115, 50 };

    const Rectangle buttons[] = {
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

    Texture2D background = LoadTexture("../assets/inventory/shelfInside.png");
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

        for (int i = 0; i < 12; i++)
        {
            bool isMouseOver = CheckCollisionPointRec(mousePosition, buttons[i]);

            if (isMouseOver && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                visibleReagentIndex = i;
            }
        }

        if (IsKeyDown(KEY_SPACE))
        {
            visibleReagentIndex = -1;
        }

        if (visibleReagentIndex != -1)
        {
            Vector2 pos = reagentPositions[visibleReagentIndex];
            DrawTexture(reagents[visibleReagentIndex], pos.x, pos.y, RAYWHITE);
        }

        bool isMouseOverExitButton = CheckCollisionPointRec(mousePosition, exitButton);

        DrawTextEx(font, "Exit", Vector2{ exitButtonPosition.x + 100, exitButtonPosition.y + 25 }, 50, 10, isMouseOverExitButton ? BLACK : WHITE);

        if (CheckCollisionPointRec(mousePosition, exitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            break;
        }

        EndDrawing();
    }

    UnloadTexture(background);
    UnloadFont(font);

    for (int i = 0; i < 12; i++)
    {
        UnloadTexture(reagents[i]);
    }
}