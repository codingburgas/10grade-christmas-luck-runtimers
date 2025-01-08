#include "pch.h"
#include "archive.h"

#pragma once

struct inventoryElement {
    string formula;
    Texture2D texture;
    Rectangle sourceRect;
    Vector2 position;
};


void displayInventoryBg();
void displayShelfInside();
void displayChembenchZoomed();
