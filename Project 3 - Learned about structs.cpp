{
    Rectangle rec;
    Vector2 pos;
    int frame;
    float updateTime;
    float runningTime;
};


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
