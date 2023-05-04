Texture2D Scarfy = LoadTexture("textures/scarfy.png");
Rectangle scarfyRec;
scarfyRec.width = Scarfy.width/6;
scarfyRec.height = Scarfy.height;
scarfyRec.x = 0;
scarfyRec.y = 0;
Vector2 scarfyPos;
scarfyPos.x = windowWidth/2 - scarfyRec.width/2;
scarfyPos.y = windowHeight - scarfyRec.height;

//update position
scarfyPos.y += velocity;

//perform ground check
if (scarfyPos.y >= windowHeight - scarfyRec.height)
{
   velocity = 0;
   isInAir = false;
}
else
{
    velocity += gravity;
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
