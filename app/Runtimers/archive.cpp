#include "archive.h"

void displayArchive()
{
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


        DrawText("Exit", exitButtonPosition.x + 100, exitButtonPosition.y + 25, 50, isMouseOverExitButton ? BLACK : WHITE);

        if (CheckCollisionPointRec(mousePosition, exitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            break;
        }

        EndDrawing();
    }

    UnloadTexture(background);
}


void displayTablet()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;


    Image logo = LoadImage("../assets/logo/logoTransparent.png");

    SetWindowIcon(logo);

    Vector2 exitButtonPosition = { GetScreenWidth() / 2 + 650, GetScreenHeight() / 2 + 425 };

    const Rectangle exitButton = { exitButtonPosition.x + 90, exitButtonPosition.y + 20, 115, 50 };

    Texture2D background = LoadTexture("../assets/archive/tabletInside.png");

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
            break;
        }

        EndDrawing();
    }

    UnloadTexture(background);
}