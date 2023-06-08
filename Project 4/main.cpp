#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "prop.h"

int main()
{

    // Window Variables.
    double windowDimensions[2];
    windowDimensions[0] = 500;
    windowDimensions[1] = 500;

    // initialise the window
    InitWindow(windowDimensions[0], windowDimensions[1], "Warren's Game");

    // Textures for world map
    Texture2D background = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    float bgX{};
    Vector2 mappos{bgX, 0.0};
    const float mapScale {4.0};

    Prop rock{Vector2{0.f, 0.f}, LoadTexture("nature_tileset/Rock.png")};

    // Draw Character
    Character knight{windowDimensions[0], windowDimensions[1]};


    while (!WindowShouldClose())
    {
        SetTargetFPS(60);
        BeginDrawing();
        ClearBackground(WHITE);

        //Moving the map
        mappos = Vector2Scale(knight.getworldPos(), -1.f);
        
        rock.Render(knight.getworldPos());

        
        
        // Draw the background
        DrawTextureEx(background, mappos, 0.0, mapScale, WHITE);
        knight.tick(GetFrameTime());
        // Check map bounds
            if (knight.getworldPos().x < 0.f ||
                knight.getworldPos().y < 0.f ||
                knight.getworldPos().x + windowDimensions[0] > background.width * mapScale ||
                knight.getworldPos().y + windowDimensions[1] > background.height * mapScale)
            {
                knight.undoMovement();
            }

    
        // Stop Drawing.
        EndDrawing();
    }
    CloseWindow();

}
