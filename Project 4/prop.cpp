#include "prop.h"
#include "raylib.h"
#include "raymath.h"



Prop::Prop(Vector2 pos, Texture2D tex) : 
    worldPos(pos), 
    texture(tex)
{

}

void Prop::Render(Vector2 KnightPos)
{
    Vector2 screenPos{ Vector2Subtract(worldPos, KnightPos) };
    DrawTextureEx(texture, screenPos, 0.f, scale, WHITE);
}