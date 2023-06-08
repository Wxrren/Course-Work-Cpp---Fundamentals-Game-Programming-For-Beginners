// See note document for indepth notes.
#include "raylib.h"
int main() {

// window dimensions.
const int width{1920};
const int height{1080};
//initialise the window
InitWindow (width, height, "Warren's Game");

while (!WindowShouldClose())
{
SetTargetFPS(60);
BeginDrawing();
ClearBackground(WHITE);

//Stop Drawing.
EndDrawing();
}
CloseWindow();
}
