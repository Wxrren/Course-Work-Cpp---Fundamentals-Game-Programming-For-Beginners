#include "raylib.h"
#include "raymath.h"



class Prop
{
public:
    Prop(Vector2 pos, Texture2D tex);
    void Render(Vector2 KnightPos);

private:

    Vector2 worldPos{};
    Texture2D texture{};
    float scale{4.f};

};