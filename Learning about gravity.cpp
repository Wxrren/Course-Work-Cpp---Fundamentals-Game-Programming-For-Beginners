//acceleration due to gravity (pixels/frame)/frame
const int gravity{1};

//rectangle dimensions
const int RectangleWidth{50};
const int Rectangleheight{80};

int posY{windowHeight - Rectangleheight};
int velocity{0};

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
}
else
{
    velocity += gravity;
}

DrawRectangle (windowWidth/2, posY, RectangleWidth, Rectangleheight, BLUE);

if (IsKeyPressed(KEY_SPACE))
{
    velocity -= 10;
}
