// created a window and drew in a texture of a world map that I created in the "tiled" app. 

#include "raylib.h"
int main() {

// Window Variables.
double windowDimensions [2];
windowDimensions[0] = 384;
windowDimensions[1] = 384;

//initialise the window
InitWindow (windowDimensions[0], windowDimensions[1], "Warren's Game");

//Textures for world map
Texture2D background = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
float bgX{};

while (!WindowShouldClose())
{
SetTargetFPS(60);
BeginDrawing();
ClearBackground(WHITE);

//Draw the background
Vector2 bg1Pos{bgX, 0.0};
DrawTextureEx(background, bg1Pos, 0.0, 1.0, WHITE);



//Stop Drawing.
EndDrawing();
}
CloseWindow();
UnloadTexture(background);
}
