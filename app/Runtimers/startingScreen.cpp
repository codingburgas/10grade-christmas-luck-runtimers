#include "startingScreen.h"

void displayStartingScreen()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "RUNTIMERS"); 

    Font font = LoadFont("../font/font.ttf"); // Load the font 

    Image logo = LoadImage("../assets/logo/logoTransparent.png"); // Load the logo image

    SetWindowIcon(logo); // Set the window icon to the loaded logo

    // Position for the buttons
    Vector2 exitButtonPosition = { GetScreenWidth() / 2 + 650, GetScreenHeight() / 2 + 425 }; 
    Vector2 enterButtonPosition = { GetScreenWidth() / 2 - 200, GetScreenHeight() / 2 + 300 }; 

    // Define the button's rectangles
    const Rectangle exitButton = { exitButtonPosition.x + 90, exitButtonPosition.y + 20, 115, 50 };
    const Rectangle enterButton = { enterButtonPosition.x , enterButtonPosition.y , 400, 200 }; 

    Texture2D background = LoadTexture("../assets/startingScreen/startingScreen.png"); // Load the background texture

    SetTargetFPS(60); 

    while (!WindowShouldClose())
    {
        Vector2 mousePosition = GetMousePosition();

        BeginDrawing(); 

        ClearBackground(RAYWHITE); 

        DrawTexture(background, 0, 0, RAYWHITE); 

        // Check if the mouse is over the enter button
        bool isMouseOverEnterButton = CheckCollisionPointRec(mousePosition, enterButton); 

        if (CheckCollisionPointRec(mousePosition, enterButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            displayHallway(); 
        }

        // Check if the mouse is over the exit button
        bool isMouseOverExitButton = CheckCollisionPointRec(mousePosition, exitButton); 

        DrawTextEx(font, "Exit", Vector2{ exitButtonPosition.x + 100, exitButtonPosition.y + 25 }, 50, 10, isMouseOverExitButton ? BLACK : WHITE); 

        if (CheckCollisionPointRec(mousePosition, exitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            break; 
        }

        EndDrawing(); // End drawing the frame
    }

    UnloadFont(font); // Unload the font
    UnloadTexture(background); // Unload the background texture
    CloseWindow(); // Close the window
}