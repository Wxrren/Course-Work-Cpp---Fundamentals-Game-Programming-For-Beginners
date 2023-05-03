//Is rectangle in the air?
bool isInAir{};

// Jump velocity
const int JumpVel{-22};

while (!WindowShouldClose())
{
SetTargetFPS(60);
BeginDrawing();
ClearBackground(WHITE);

//update position
posY += velocity;

//perform ground check
if (posY >= windowHeight - Rectangleheight)
{
   velocity = 0;
   isInAir = false;
}
else
{
    velocity += gravity;
    isInAir = true;
}

DrawRectangle (windowWidth/2, posY, RectangleWidth, Rectangleheight, BLUE);

//jump check
if (IsKeyPressed(KEY_SPACE) && !isInAir)
{
    velocity += JumpVel;
