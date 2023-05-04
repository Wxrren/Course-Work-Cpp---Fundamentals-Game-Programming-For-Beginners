//Nebula Variables.
Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");
Rectangle nebulaRec {0.0, 0.0, nebula.width/8, nebula.height/8};
Vector2 nebulaPos {windowWidth, windowHeight - nebulaRec.height};

// Nevula x velocity (pixels/second)
int nebvel{-600};

// Draw Nebula
DrawTextureRec(nebula, nebulaRec, nebulaPos, WHITE);

//update Nebula position
nebulaPos.x += nebvel * dT;

