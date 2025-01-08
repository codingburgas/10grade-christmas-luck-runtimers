#include "hallway.h"

void displayHallway()
{
    Font font = LoadFont("../font/font.ttf"); // Load font

    const int screenWidth = 1920;
    const int screenHeight = 1080;

    // Position for the buttons
    Vector2 exitButtonPosition = { GetScreenWidth() / 2 + 650, GetScreenHeight() / 2 + 425 }; 
    Vector2 labButtonPosition = { GetScreenWidth() / 2 - 295, GetScreenHeight() / 2 - 135 }; 
    Vector2 archiveButtonPosition = { GetScreenWidth() / 2 + 260, GetScreenHeight() / 2 - 135 }; 

    // Define the button's rectangles
    const Rectangle exitButton = { exitButtonPosition.x + 90, exitButtonPosition.y + 20, 115, 50 }; 
    const Rectangle labButton = { labButtonPosition.x , labButtonPosition.y, 220, 100 };
    const Rectangle archiveButton = { archiveButtonPosition.x , archiveButtonPosition.y, 220, 100 }; 

    Texture2D background = LoadTexture("../assets/hallway/hallway.png"); // Load background texture

    SetTargetFPS(60); 

    while (!WindowShouldClose()) 
    {
        Vector2 mousePosition = GetMousePosition(); 

        BeginDrawing(); 

        ClearBackground(RAYWHITE); 

        DrawTexture(background, 0, 0, RAYWHITE); 

        // Check if the mouse is over the lab button
        bool isMouseOverLabButton = CheckCollisionPointRec(mousePosition, labButton);
        DrawTextEx(font, "INV", Vector2{ labButtonPosition.x + 102, labButtonPosition.y + 25 }, 50, 10, isMouseOverLabButton ? BLACK : WHITE); // Draw the lab button text

        if (CheckCollisionPointRec(mousePosition, labButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            displayInventoryBg(); 
        }


        // Check if the mouse is over the archive button
        bool isMouseOverArchiveButton = CheckCollisionPointRec(mousePosition, archiveButton); 
        DrawTextEx(font, "ARCH", Vector2{ archiveButtonPosition.x + 95, archiveButtonPosition.y + 25 }, 50, 10, isMouseOverArchiveButton ? BLACK : WHITE); // Draw the archive button text

        if (CheckCollisionPointRec(mousePosition, archiveButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            displayArchive(); 
        }


        // Check if the mouse is over the exit button
        bool isMouseOverExitButton = CheckCollisionPointRec(mousePosition, exitButton); 
        DrawTextEx(font, "Exit", Vector2{ exitButtonPosition.x + 100, exitButtonPosition.y + 25 }, 50, 10, isMouseOverExitButton ? BLACK : WHITE); // Draw the exit button text

        if (CheckCollisionPointRec(mousePosition, exitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            break; 
        }

        EndDrawing(); 
    }

    UnloadTexture(background); // Unload the background texture
    UnloadFont(font); // Unload the font
}