#include "hallway.h"
#include "inventory.h"
#include "archive.h"

void displayHallway()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;


    Image logo = LoadImage("../assets/logo/logoTransparent.png");

    SetWindowIcon(logo);

    Vector2 exitButtonPosition = { GetScreenWidth() / 2 + 650, GetScreenHeight() / 2 + 425 };
    Vector2 labButtonPosition = { GetScreenWidth() / 2 - 295, GetScreenHeight() / 2 - 135 };
    Vector2 archiveButtonPosition = { GetScreenWidth() / 2 + 260, GetScreenHeight() / 2 - 135 };

    const Rectangle exitButton = { exitButtonPosition.x + 90, exitButtonPosition.y + 20, 115, 50 };
    const Rectangle labButton = { labButtonPosition.x - 50, labButtonPosition.y, 250, 100 };
    const Rectangle archiveButton = { archiveButtonPosition.x + 50, archiveButtonPosition.y, 250, 100 };

    Texture2D background = LoadTexture("../assets/hallway/hallway.png");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        Vector2 mousePosition = GetMousePosition();

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, RAYWHITE);

        bool isMouseOverExitButton = CheckCollisionPointRec(mousePosition, exitButton);
        bool isMouseOverLabButton = CheckCollisionPointRec(mousePosition, labButton);
        bool isMouseOverArchiveButton = CheckCollisionPointRec(mousePosition, archiveButton);

        DrawText("LAB", labButtonPosition.x + 100, labButtonPosition.y + 25, 50, isMouseOverLabButton ? BLACK : WHITE);

        if (CheckCollisionPointRec(mousePosition, labButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            displayInventory();
        }

        DrawText("ARCH", archiveButtonPosition.x + 100, archiveButtonPosition.y + 25, 50, isMouseOverArchiveButton ? BLACK : WHITE);

        if (CheckCollisionPointRec(mousePosition, archiveButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            displayArchive();
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