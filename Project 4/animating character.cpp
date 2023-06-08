// split across different areas in the main code - here is how I animated the knight - See FULL CODE.cpp when this project is finished for the full code. 

//Draw Knight
Texture2D knight_idle = LoadTexture("characters/knight_idle_spritesheet.png");
Texture2D knight_run = LoadTexture("characters/knight_run_spritesheet.png");

// 1 : facing right, -1 : facing left
float rightleft{1.f};

//animation variables
float runningTime{};
int frame{};
const int maxFrames{6};
const float updateTime{1.f/12.f};

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

//within the previously set direction commands
 direction.x < 0.f ? rightleft = -1.f : rightleft = 1.f;
    knight = knight_run;
}
else
{
    knight = knight_idle;
}

// After drawing has stopped
unloadTexture(knight_idle);
UnloadTexture(knight_run);
UnloadTexture(knight);
