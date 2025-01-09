#include "pch.h"
#include "archive.h"

#pragma once

// Structure to represent an inventory element
struct inventoryElement {
    string formula = "";
    Texture2D texture = Texture2D();
    Rectangle sourceRect = Rectangle();
    Vector2 position = Vector2();
};

// Function declarations
void displayInventoryBg();
void displayShelfInside();
void displayChembenchZoomed();
