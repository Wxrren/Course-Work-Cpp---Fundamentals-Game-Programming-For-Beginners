// See note document for indepth notes.
#include "raylib.h"
struct AnimData
{
    Rectangle rec;
    Vector2 pos;
    int frame;
    float updateTime;
    float runningTime;
};
int main() {

// window dimensions.
const int windowWidth{1920};
const int windowHeight{1080};
//initialise the window
InitWindow (windowWidth, windowHeight, "Warren's Game");

//acceleration due to gravity (pixels/sec)/sec
const int gravity{1'000};

//Animdata for Nebula
Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");
AnimData nebData{{0.0, 0.0, nebula.width/8, nebula.height/8}, // Rectangle Rec
                 {windowWidth, windowHeight - nebula.height/8}, // Vector2 Pos
                 0, // int Frame
                 1.0/12.0, // float Update time
                 0.0}; // float runningtime.


//animdata for 2nd Nebula
AnimData neb2Data{{0.0, 0.0, nebula.width/8, nebula.height/8},
                  {windowWidth + 300, windowHeight - nebula.height/8},
                  0,
                  1.0/16.0,
                  0};


// Scarfy Variables
Texture2D Scarfy = LoadTexture("textures/scarfy.png");
AnimData scarfyData {{0.0, 0.0, Scarfy.width/6, Scarfy.height}, // Rectangle Rec
                     {windowWidth/2, windowHeight - Scarfy.height}, // Vector2 Pos
                     0, // int Frame
                     1.0/12.0, // float Update time
                     0.0 // float runningtime
};
                
int velocity{0};

// Nevula x velocity (pixels/second)
int nebvel{-200};

//Is Scarfy in the air?
bool isInAir{};

// Jump velocity - pixels per second
const int JumpVel{-600};

while (!WindowShouldClose())
{
SetTargetFPS(60);
BeginDrawing();
ClearBackground(WHITE);

// Delta time (time since last frame)
const float dT{GetFrameTime() };

//update Nebula position
nebData.pos.x += nebvel * dT;

//update 2nd Nebula position
neb2Data.pos.x += nebvel * dT;

//update Scarfy position
scarfyData.pos.y += velocity * dT;

//perform ground check
if (scarfyData.pos.y >= windowHeight - scarfyData.rec.height)
{
   velocity = 0;
   isInAir = false;
}
else
{
    velocity += gravity * dT;
    isInAir = true;
}

if (!isInAir)
{
    //update running time
    scarfyData.runningTime += dT;
    if (scarfyData.runningTime >= scarfyData.updateTime)
    {
     //update animation frame
    scarfyData.runningTime = 0.0;
    scarfyData.rec.x = scarfyData.frame * scarfyData.rec.width;
    scarfyData.frame++;
    if (scarfyData.frame > 5)
    {
    scarfyData.frame = 0;
    }
    }
}

//update nebula running time
nebData.runningTime += dT;
if (nebData.runningTime >= nebData.updateTime)
{
nebData.runningTime = 0.0;
   // update nebula animation frame
nebData.rec.x = nebData.frame * nebData.rec.width;
nebData.frame++;
if (nebData.frame > 7)
{
    nebData.frame = 0;
}
}

//update nebula 2 running time
neb2Data.runningTime += dT;
if (neb2Data.runningTime >= neb2Data.updateTime)
{
neb2Data.runningTime = 0.0;
   
// update nebula 2 animation frame
neb2Data.rec.x = neb2Data.frame * neb2Data.rec.width;
neb2Data.frame++;
if (neb2Data.frame > 7)
{
    neb2Data.frame = 0;
}
}


// Draw Nebula
DrawTextureRec(nebula, nebData.rec, nebData.pos, WHITE);

// Draw 2nd Nebula
DrawTextureRec(nebula, neb2Data.rec, neb2Data.pos, RED);

//Draw Scarfy
DrawTextureRec(Scarfy, scarfyData.rec, scarfyData.pos, WHITE);

//jump check
if (IsKeyPressed(KEY_SPACE) && !isInAir)
{
    velocity += JumpVel;
}

//Stop Drawing.
EndDrawing();
}
UnloadTexture(Scarfy);
UnloadTexture(nebula);
CloseWindow();
}
