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

bool isOnGround(AnimData data, int windowheight)
{
    return data.pos.y >= windowheight - data.rec.height;
}

// Scarfy animation update function.
AnimData updateAnimData(AnimData data, float deltaTime, int maxframe)
{
    // update running time
    data.runningTime += deltaTime;
    if (data.runningTime >= data.updateTime)
    {
        data.runningTime = 0.0;
        // Update animation frame
        data.rec.x = data.frame * data.rec.width;
        data.frame++;
        if (data.frame > 7 > maxframe)
        {
            data.frame = 0;
        }
        
    }
    return data;
}

//nebula animation update function.

AnimData UpdateNebulaData(AnimData data, float deltaTime, int MaxFrame)
{
       //update nebula running time
        data.runningTime += deltaTime;
        if (data.runningTime >= data.updateTime)
        {
       data.runningTime = 0.0;
        // update nebula animation frame
        data.rec.x = data.frame * data.rec.width;
        data.frame++;
        if (data.frame > 7)
        {
            data.frame = 0;}
        } 
return data;

}

int main() {

// Window Variables.
double windowDimensions [2];
windowDimensions[0] = 1920;
windowDimensions[1] = 1080;


InitWindow (windowDimensions[0], windowDimensions[1], "Warren's Game");

//acceleration due to gravity (pixels/sec)/sec
const int gravity{1'000};

//Animdata for Nebula
Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");

// Scarfy Variables
Texture2D Scarfy = LoadTexture("textures/scarfy.png");
AnimData scarfyData {{0.0, 0.0, Scarfy.width/6, Scarfy.height}, // Rectangle Rec
                     {windowDimensions[0]/2, windowDimensions[1] - Scarfy.height}, // Vector2 Pos
                     0, // int Frame
                     1.0/12.0, // float Update time
                     0.0}; // float runningtime
                     
// Nebdata Array
const int sizeOfNebulas{30};
AnimData multipleNebulas[sizeOfNebulas]{};

for (int i = 0; i < sizeOfNebulas; i++)
{
multipleNebulas[i].rec.x = 0.0;
multipleNebulas[i].rec.y = 0.0;
multipleNebulas[i].rec.width = nebula.width/8;
multipleNebulas[i].rec.height = nebula.height/8;
multipleNebulas[i].pos.y =  windowDimensions[1] - nebula.height/8;
multipleNebulas[i].frame = 0;
multipleNebulas[i].runningTime = 0.0;
multipleNebulas[i].updateTime = 1.0/16.0;
multipleNebulas[i].pos.x = windowDimensions[0] + i * 300;
}


// Finish Line
float finishline{multipleNebulas[sizeOfNebulas - 1].pos.x};

//Textures for background
Texture2D background = LoadTexture("textures/far-buildings.png");
float bgX{};

//Textures for Midground
Texture2D midground = LoadTexture("textures/back-buildings.png");
float mgX{};

//Textures for Foreground
Texture2D foreground = LoadTexture("textures/foreground.png");
float fgX{};

int velocity{0};

// Nevula x velocity (pixels/second)
int nebvel{-200};

//Is Scarfy in the air?
bool isInAir{};

// Jump velocity - pixels per second
const int JumpVel{-600};

bool collision{};

while (!WindowShouldClose())
{
SetTargetFPS(60);
BeginDrawing();
ClearBackground(WHITE);

// Delta time (time since last frame)
const float dT{GetFrameTime() };

// Collision
for (AnimData nebula : multipleNebulas)
{
    float pad{50};
    Rectangle nebrec{
        nebula.pos.x + pad,
        nebula.pos.y + pad,
        nebula.rec.width - 2 * pad,
        nebula.rec.height - 2 * pad
    };
    Rectangle scarfyrec {
        scarfyData.pos.x,
        scarfyData.pos.y,
        scarfyData.rec.width,
        scarfyData.rec.height
        };
        if (CheckCollisionRecs(nebrec, scarfyrec))
        {
            collision = true;
        }
};

//moving background
bgX -= 50 * dT; 

if (bgX <= -background.width * 8)
{
    bgX = 0.0;
}

//moving midground
mgX -= 100 * dT; 

if (mgX <= -midground.width * 8)
{
    mgX = 0.0;
}

//moving foreground
fgX -= 150 * dT; 

if (fgX <= -foreground.width * 8)
{
    fgX = 0.0;
}


//Draw the background
Vector2 bg1Pos{bgX, 0.0};
DrawTextureEx(background, bg1Pos, 0.0, 8.0, WHITE);
Vector2 bg2Pos{bgX + background.width * 8, 0.0};
DrawTextureEx(background, bg2Pos, 0.0, 8.0, WHITE);

//Draw the midground
Vector2 mg1Pos{mgX, 0.0};
DrawTextureEx(midground, mg1Pos, 0.0, 8.0, WHITE);
Vector2 mg2Pos{mgX + midground.width * 8, 0.0};
DrawTextureEx(midground, mg2Pos, 0.0, 8.0, WHITE);

//Draw the foreground
Vector2 fg1Pos{fgX, 0.0};
DrawTextureEx(foreground, fg1Pos, 0.0, 8.0, WHITE);
Vector2 fg2Pos{fgX + foreground.width * 8, 0.0};
DrawTextureEx(foreground, fg2Pos, 0.0, 8.0, WHITE);

for (int i = 0; i < sizeOfNebulas; i++)
{
   // Update the position of each nebula
   multipleNebulas[i].pos.x += nebvel * dT;
}

//update finishline
finishline += nebvel *dT;

//update Scarfy position
scarfyData.pos.y += velocity * dT;

//perform ground check
if (isOnGround(scarfyData, windowDimensions[1]))
{
   velocity = 0;
   isInAir = false;
}
else
{
    velocity += gravity * dT;
    isInAir = true;
}

// Updating scarfy animation frames
if (!isInAir)
{
   scarfyData = updateAnimData(scarfyData, dT, 5);
}
       
 // Nebula's running time and animation frames
        for (int i = 0; i < sizeOfNebulas; i++ )
        {
    multipleNebulas[i] = updateAnimData(multipleNebulas[i], dT, 7);
        }

if (collision)
{
    //lose the game
     DrawText ("Game over!!!", 960, 540, 100, WHITE);
}
else if (scarfyData.pos.x >= finishline)
{
    // win the game
    DrawText ("You Win!!!", 960, 540, 100, GREEN);
}
else
{
 // Draw Nebulas
for (int i = 0; i < sizeOfNebulas; i++)
{
   
DrawTextureRec(nebula, multipleNebulas[i].rec, multipleNebulas[i].pos, WHITE);
}

//Draw Scarfy
DrawTextureRec(Scarfy, scarfyData.rec, scarfyData.pos, WHITE);
}
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
UnloadTexture(background);
UnloadTexture(midground);
UnloadTexture(foreground);
CloseWindow();
}
