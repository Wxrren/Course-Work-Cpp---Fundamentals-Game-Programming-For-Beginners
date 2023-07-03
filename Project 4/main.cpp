#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "prop.h"
#include "enemy.h"
#include <string>

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
    const float mapScale{4.0};

    // Draw Character
    Character knight{windowDimensions[0], windowDimensions[1]};

    // Textures for props
    Prop rock{Vector2{0.f, 0.f}, LoadTexture("nature_tileset/Rock.png")};

    // Draw the props
    Prop props[2]{
        Prop{Vector2{100.f, 600.f}, LoadTexture("nature_tileset/Rock.png")},
        {Vector2{700.f, 500.f}, LoadTexture("nature_tileset/log.png")}};

    Enemy goblin{
        Vector2{},
        LoadTexture("characters/goblin_idle_spritesheet.png"),
        LoadTexture("characters/goblin_run_spritesheet.png"),
    };

    Enemy slime{
        Vector2{800.f, 700.f},
        LoadTexture("characters/slime_idle_spritesheet.png"),
        LoadTexture("characters/slime_run_spritesheet.png"),
    };

    // Draw multiple enemies
    Enemy *enemies[]{
        &goblin,
        &slime};

    for (auto enemy : enemies)
    {
        enemy->setTarget(&knight);
    }

    while (!WindowShouldClose())
    {
        SetTargetFPS(60);
        BeginDrawing();
        ClearBackground(WHITE);

        // Moving the map
        mappos = Vector2Scale(knight.getworldPos(), -1.f);

        // Draw the background
        DrawTextureEx(background, mappos, 0.0, mapScale, WHITE);

        // Draw the props
        for (auto prop : props)
        {
            prop.Render(knight.getworldPos());
        }

        // draw health
        if (!knight.getAlive()) // Character is not alive
        {
            DrawText("game Over!", 55.f, 45.f, 40, RED);
            EndDrawing();
            continue;
        }
        else // character is alive
        {
            std::string knightsHealth = "Health: ";
            knightsHealth.append(std::to_string(knight.getHealth()), 0, 5);
            DrawText(knightsHealth.c_str(), 55.f, 45.f, 40, RED);
        }

        knight.tick(GetFrameTime());
        // Check map bounds
        if (knight.getworldPos().x < 0.f ||
            knight.getworldPos().y < 0.f ||
            knight.getworldPos().x + windowDimensions[0] > background.width * mapScale ||
            knight.getworldPos().y + windowDimensions[1] > background.height * mapScale)
        {
            knight.undoMovement();
        }

        // Collision
        for (auto prop : props)
        {
            if (CheckCollisionRecs(prop.GetCollisionRec(knight.getworldPos()), knight.GetCollisionRec()))
            {
                knight.undoMovement();
            }
        }

        for (auto enemy : enemies)
        {
            enemy->tick(GetFrameTime());
        }

        // Damage goblin
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            for (auto enemy : enemies)
            {
                if (CheckCollisionRecs(enemy->GetCollisionRec(), knight.getWeaponCollisionRec()))
                {
                    enemy->setAlive(false);
                }
            }
        }

        // Stop Drawing.
        EndDrawing();
    }
    CloseWindow();
}