// Split across multi sections 


// Finish Line
float finishline{multipleNebulas[sizeOfNebulas - 1].pos.x};

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
