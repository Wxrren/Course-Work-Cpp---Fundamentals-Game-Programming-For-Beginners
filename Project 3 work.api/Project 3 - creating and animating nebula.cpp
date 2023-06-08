//Nebula Variables.
Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");
Rectangle nebulaRec {
    0.0, 0.0, nebula.width/8,
    nebula.height/8};
Vector2 nebulaPos {windowWidth, 
        windowHeight - nebulaRec.height};

// Nevula x velocity (pixels/second)
int nebvel{-200};

// Draw Nebula
DrawTextureRec(nebula, nebulaRec, nebulaPos, WHITE);

//update Nebula position
nebulaPos.x += nebvel * dT;

// Nebula animation variables
int nebFrame{};
//amount of time before we update the animation frame
const float nebUpdateTime{1.0/12.0};
float nebRunningTime {};

//update nebula running time - (This is done inside the while loop)
nebRunningTime += dT;
if (nebRunningTime >= nebUpdateTime)
{
nebRunningTime = 0.0;
   // update nebula animation frame
nebulaRec.x = nebFrame * nebulaRec.width;
nebFrame++;
if (nebFrame > 7)
{
    nebFrame = 0;
}
}
