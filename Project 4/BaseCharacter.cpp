
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