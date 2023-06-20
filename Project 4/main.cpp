#include "raylib.h"
#include "raymath.h"

class Character
{

public:
Vector2 getworldPos() { return worldPos; }
void setScreenPos(int winWidth, int winHeight);

private:
    Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D idle   {LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D run    {LoadTexture("characters/knight_run_spritesheet.png")};
    Vector2 screenPos;
    Vector2 worldPos;
    // 1 : facing right, -1 : facing left
    float rightleft{1.f};
    //animation variables
    float runningTime{};
    int frame{};
    const int maxFrames{6};
    const float updateTime{1.f/12.f};
    const float speed{4.f};

};

void Character::setScreenPos(int winWidth, int winHeight)
{
    screenPos={
        (float)winWidth/2 - 4.f * (0.5f * (float)texture.width/6.0f),
        (float)winHeight/2 - 4.0f * (0.5f * (float)texture.height)
    };
}


int main() {

// Window Variables.
double windowDimensions [2];
windowDimensions[0] = 500;
windowDimensions[1] = 500;

//initialise the window
InitWindow (windowDimensions[0], windowDimensions[1], "Warren's Game");

//Textures for world map
Texture2D background = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
float bgX{};
Vector2 mappos{bgX, 0.0};

//Draw Knight
Texture2D knight_idle = LoadTexture("characters/knight_idle_spritesheet.png");
Texture2D knight_run = LoadTexture("characters/knight_run_spritesheet.png");
Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");
Vector2 knightpos{
    windowDimensions[0]/2 - 4.f * (0.5f * (float)knight.width/6.0),
    windowDimensions[1]/2 - 4.0f * (0.5f * (float)knight.height)
};
// 1 : facing right, -1 : facing left
float rightleft{1.f};

//animation variables
float runningTime{};
int frame{};
const int maxFrames{6};
const float updateTime{1.f/12.f};

// Speed/movement variables
float speed {4.0};

while (!WindowShouldClose())
{
SetTargetFPS(60);
BeginDrawing();
ClearBackground(WHITE);

//Draw the background
DrawTextureEx(background, mappos, 0.0, 1.0, WHITE);

//Delta Time Variables
const float dT{GetFrameTime()};

//update animation frame
runningTime += dT;
if (runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.f;
        if ( frame > maxFrames) frame = 0;
    }


// draw character
Rectangle source{frame * (float)knight.width/6.f, 0.f, rightleft * (float)knight.width/6.f, (float)knight.height};
Rectangle dest{knightpos.x, knightpos.y, 4.0f * (float)knight.width/6.0, 4.0f * (float)knight.height};
Vector2 origin{};
DrawTexturePro(knight, source, dest, origin, 0.f, WHITE);


Vector2 direction{};
if (IsKeyDown(KEY_A)) direction.x -= 1.0;
if (IsKeyDown(KEY_D)) direction.x += 1.0;
if (IsKeyDown(KEY_W)) direction.y -= 1.0;
if (IsKeyDown(KEY_S)) direction.y += 1.0;
if (Vector2Length(direction) != 0.0)
{
    // Set Mappos = mappos - direction
    mappos = Vector2Subtract(mappos, Vector2Scale(Vector2Normalize(direction),speed));
    // changes sprite direction depending on if left or right
    direction.x < 0.f ? rightleft = -1.f : rightleft = 1.f;
    knight = knight_run;
}
else
{
    knight = knight_idle;
}
//Stop Drawing.
EndDrawing();
}
CloseWindow();
UnloadTexture(background);
UnloadTexture(knight);
UnloadTexture(knight_idle);
UnloadTexture(knight_run);
}