
#include "BaseCharacter.h"
#include "enemy.h"

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
        screenPos.x,
        screenPos.y,
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

    // draw character
    Rectangle source{frame * width, 0.f, rightleft * width, height};
    Rectangle dest{screenPos.x, screenPos.y, scale * width, scale * height};
    Vector2 origin{};
    DrawTexturePro(texture, source, dest, origin, 0.f, WHITE);
}