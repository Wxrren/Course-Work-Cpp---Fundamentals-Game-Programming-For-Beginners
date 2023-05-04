//rectangle dimensions
const int RectangleWidth{50};
const int Rectangleheight{80};

int posY{height - Rectangleheight};
int velocity{0};

while (!WindowShouldClose())
{
SetTargetFPS(60);
BeginDrawing();
ClearBackground(WHITE);

posY += velocity;

DrawRectangle (width/2, posY, RectangleWidth, Rectangleheight, BLUE);

if (IsKeyPressed(KEY_SPACE))
{
    velocity -= 10;
}
