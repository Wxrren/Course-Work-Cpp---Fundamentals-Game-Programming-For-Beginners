
#include "BaseCharacter.h"
#include "enemy.h"
#include "raymath.h"

BaseCharacter::BaseCharacter()
{

}

void BaseCharacter::undoMovement()
    {
        worldPos = worldPosLastFrame;
    }

     Rectangle BaseCharacter::GetCollisionRec()
     {
    
    return Rectangle{
        getScreenPos().x,
        getScreenPos().y,
        width * scale,
        height * scale
    };
     }

    
void BaseCharacter::tick(float deltaTime)
{
     worldPosLastFrame = worldPos;

     // update animation frame
    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.f;
        if (frame > maxFrames)
            frame = 0;
    }
    
    //update Movement
    if (Vector2Length(velocity) != 0.0)
    {
        // Set worldPos = worldPos + velocity
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));
        // changes sprite direction depending on if left or right
        velocity.x < 0.f ? rightleft = -1.f : rightleft = 1.f;
        texture = run;
    }
    else
    {
        texture = idle;
    }

velocity = {};

    // draw character
    Rectangle source{frame * width, 0.f, rightleft * width, height};
    Rectangle dest{getScreenPos().x, getScreenPos().y, scale * width, scale * height};
    Vector2 origin{};
    DrawTexturePro(texture, source, dest, origin, 0.f, WHITE);
}