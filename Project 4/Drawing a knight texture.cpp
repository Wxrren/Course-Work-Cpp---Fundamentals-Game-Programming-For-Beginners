// Drawing in the idle version of the knight using Draw texture pro - split across different areas (outside while loop for variables and inside for drawing) 

//Knight variables
Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");
Vector2 knightpos{
    windowDimensions[0]/2 - 4.f * (0.5f * (float)knight.width/6.0),
    windowDimensions[1]/2 - 4.0f * (0.5f * (float)knight.height)
};

// Drawing knight onto screen inside the while loop. 

// draw character
Rectangle source{0.f, 0.f, (float)knight.width/6.f, (float)knight.height};
Rectangle dest{knightpos.x, knightpos.y, 4.0f * (float)knight.width/6.0, 4.0f * (float)knight.height};
Vector2 origin{};
DrawTexturePro(knight, source, dest, origin, 0.f, WHITE);
