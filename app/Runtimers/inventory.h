#include "pch.h"
#include "archive.h"

#pragma once

// Structure to represent an inventory element
struct inventoryElement {
    string formula;
    Texture2D texture;
    Rectangle sourceRect;
    Vector2 position;
};

// Function declarations
void displayInventoryBg();
void displayShelfInside();
void displayChembenchZoomed();
