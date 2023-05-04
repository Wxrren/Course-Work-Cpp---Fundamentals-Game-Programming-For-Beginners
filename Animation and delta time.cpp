//Animation frame
int frame{};
//amouny of time before we update the animation frame
const float updateTime{1.0/12.0};
float runningTime {};

int velocity{0};

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

//update position
scarfyPos.y += velocity * dT;

//update running time
runningTime += dT;
if (runningTime >= updateTime)
{
    runningTime = 0.0;
            //update animation frame
            scarfyRec.x = frame * scarfyRec.width;
            frame++;
            if (frame > 5)
            {
                frame = 0;
            }
}


//perform ground check
if (scarfyPos.y >= windowHeight - scarfyRec.height)
{
   velocity = 0;
   isInAir = false;
}
else
{
    velocity += gravity * dT;
    isInAir = true;
}

DrawTextureRec(Scarfy, scarfyRec, scarfyPos, WHITE);

//jump check
if (IsKeyPressed(KEY_SPACE) && !isInAir)
{
    velocity += JumpVel;
}


//Stop Drawing.
EndDrawing();
}
UnloadTexture(Scarfy);
CloseWindow();
