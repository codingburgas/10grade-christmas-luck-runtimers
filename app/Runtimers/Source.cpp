#include "raylib.h"
#include "pch.h"
#include "inventory.h"
#include "archive.h"

// Define Vector2Subtract manually
Vector2 Vector2Subtract(Vector2 v1, Vector2 v2) {
    return { v1.x - v2.x, v1.y - v2.y };
}

int main() {
    // Initialize window
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Simple Drag and Drop Example");

    // Load a texture
    Texture2D texture = LoadTexture("../assets/logo/logoMain.png");

    // Initial position of the texture
    Vector2 texturePosition = { 200, 150 };

    // Variables to track dragging
    bool isDragging = false;
    Vector2 offset = { 0, 0 };

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        Vector2 mousePosition = GetMousePosition();

        // Detect if the texture is clicked
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Rectangle textureBounds = { texturePosition.x, texturePosition.y, (float)texture.width, (float)texture.height };
            if (CheckCollisionPointRec(mousePosition, textureBounds)) {
                isDragging = true;
                offset = Vector2Subtract(mousePosition, texturePosition); // Calculate offset
            }
        }

        // Stop dragging on mouse release
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            isDragging = false;
        }

        // Update position if dragging
        if (isDragging) {
            texturePosition = Vector2Subtract(mousePosition, offset);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw the texture at its current position
        DrawTexture(texture, (int)texturePosition.x, (int)texturePosition.y, WHITE);

        // Visualize the boundary for debugging
        DrawRectangleLines((int)texturePosition.x, (int)texturePosition.y, texture.width, texture.height, RED);

        DrawText("Drag the texture!", 10, 10, 20, DARKGRAY);

        EndDrawing();
    }

    // Clean up
    UnloadTexture(texture);
    CloseWindow();

    return 0;
}