//code split accross different sections - compiled into 1 here for visibility of what was done.

// Moved the vector2 pos out of my while loop so we can save the value between itterations of the loop.
Vector2 mappos{bgX, 0.0};

// Speed/movement variables
float speed {4.0};

Vector2 direction{};
if (IsKeyDown(KEY_A)) direction.x -= 1.0;
if (IsKeyDown(KEY_D)) direction.x += 1.0;
if (IsKeyDown(KEY_W)) direction.y -= 1.0;
if (IsKeyDown(KEY_S)) direction.y += 1.0;
if (Vector2Length(direction) != 0.0)
{
   // Set Mappos = mappos - direction
    mappos = Vector2Subtract(mappos, Vector2Scale(Vector2Normalize(direction),speed));
}
