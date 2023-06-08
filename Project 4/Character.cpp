#include "character.h"
#include "raylib.h"
#include "raymath.h"


Character::Character(int winWidth, int winHeight)
{
    width = texture.width / maxFrames;
    height = texture.height;

    //Set Screen Pos
     screenPos = {
        static_cast<float>(winWidth) / 2 - scale * (0.5f * width),
        static_cast<float>(winHeight) / 2 - scale * (0.5f * height)};
}

void Character::tick(float deltaTime)
{
    worldPosLastFrame = worldPos;

    Vector2 direction{};
    if (IsKeyDown(KEY_A))
        direction.x -= 1.0;
    if (IsKeyDown(KEY_D))
        direction.x += 1.0;
    if (IsKeyDown(KEY_W))
        direction.y -= 1.0;
    if (IsKeyDown(KEY_S))
        direction.y += 1.0;
    if (Vector2Length(direction) != 0.0)
    {
        // Set worldPos = worldPos + direction
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));
        // changes sprite direction depending on if left or right
        direction.x < 0.f ? rightleft = -1.f : rightleft = 1.f;
        texture = run;
    }
    else
    {
        texture = idle;
    }

    // update animation frame
    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.f;
        if (frame > maxFrames)
            frame = 0;
    }

    // draw character
    Rectangle source{frame * width, 0.f, rightleft * width, height};
    Rectangle dest{screenPos.x, screenPos.y, scale * width, scale * height};
    Vector2 origin{};
    DrawTexturePro(texture, source, dest, origin, 0.f, WHITE);
}

void Character::undoMovement()
    {
        worldPos = worldPosLastFrame;
    }