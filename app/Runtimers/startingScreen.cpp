#include "startingScreen.h"

void displayStartingScreen()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "RUNTIMERS");

    Image logo = LoadImage("../assets/logo/logoTransparent.png");

    SetWindowIcon(logo);

    Vector2 exitButtonPosition = { GetScreenWidth() / 2 + 175, GetScreenHeight() / 2 + 425 };
    Vector2 enterButtonPosition = { GetScreenWidth() / 2 - 175, GetScreenHeight() / 2 + 375 };

    const Rectangle exitButton = { exitButtonPosition.x + 90, exitButtonPosition.y + 20, 115, 50 };
    const Rectangle enterButton = { enterButtonPosition.x - 90, enterButtonPosition.y + 20, 200, 50 };

    Texture2D background = LoadTexture("../assets/startingScreen/startingScreen.png");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        Vector2 mousePosition = GetMousePosition();

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, RAYWHITE);

        bool isMouseOverEnterButton = CheckCollisionPointRec(mousePosition, enterButton);

        if (CheckCollisionPointRec(mousePosition, enterButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
           return;
        }

        bool isMouseOverExitButton = CheckCollisionPointRec(mousePosition, exitButton);

        DrawText("Exit", exitButtonPosition.x + 100, exitButtonPosition.y + 25, 50, isMouseOverExitButton ? RED : WHITE);

        if (CheckCollisionPointRec(mousePosition, exitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            return;
        }

        EndDrawing();
    }

    UnloadTexture(background);
}