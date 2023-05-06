// This is a few bits of code across seperate areas of my full workspace that I've cut and placed underneath eachother. 
// Window Variables.
double windowDimensions [2];
windowDimensions[0] = 1920;
windowDimensions[1] = 1080;
InitWindow (windowDimensions[0], windowDimensions[1], "Warren's Game");
//Animdata for Nebula
Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");

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
       
// Nebula's running time and animation frames
        for (int i = 0; i < sizeOfNebulas; i++ )
        {
         //update nebula running time
        multipleNebulas[i].runningTime += dT;
        if (multipleNebulas[i].runningTime >= multipleNebulas[i].updateTime)
        {
        multipleNebulas[i].runningTime = 0.0;
        // update nebula animation frame
        multipleNebulas[i].rec.x = multipleNebulas[i].frame * multipleNebulas[i].rec.width;
        multipleNebulas[i].frame++;
        if (multipleNebulas[i].frame > 7)
        {
            multipleNebulas[i].frame = 0;}
        } 
        }
 // Draw Nebulas
        for (int i = 0; i < sizeOfNebulas; i++)
        {
        DrawTextureRec(nebula, multipleNebulas[i].rec, multipleNebulas[i].pos, WHITE);
        }
