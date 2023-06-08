//Textures for background
Texture2D background = LoadTexture("textures/far-buildings.png");
float bgX{};

//Textures for Midground
Texture2D midground = LoadTexture("textures/back-buildings.png");
float mgX{};

//Textures for Foreground
Texture2D foreground = LoadTexture("textures/foreground.png");
float fgX{};


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
