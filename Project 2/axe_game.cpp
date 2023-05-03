// See notepad for notes and summarys
#include "raylib.h"

int main()
{
// Window Dimensions
int width = 1920; 
int height = 1080;

InitWindow(width, height, "Warren's Window.");

// Circle Cooirdinates
int circle_x{960};
int circle_y{540};
int Circle_radius{100};

// Circle Edges
int l_circle_x{circle_x - Circle_radius};
int r_circle_x{circle_x + Circle_radius};
int u_circle_y{circle_y - Circle_radius};
int b_circle_y{circle_y + Circle_radius};

// Axe Coordinates
int axe_x{400};
int axe_y{0};
int axe_length{50};
int direction{10};

// Axe edges
int L_axe_x{axe_x};
int r_axe_x{axe_x + axe_length};
int u_axe_y{axe_y};
int b_axe_y{axe_y + axe_length};

// Collision with Axe
bool Collision_with_axe = 
               (b_axe_y >= u_circle_y) && 
               (u_axe_y <= b_circle_y) && 
               (L_axe_x <= r_circle_x) && 
               (r_axe_x >= l_circle_x);


SetTargetFPS(60);
while (!WindowShouldClose()) {
BeginDrawing();
ClearBackground(BLACK);

if (Collision_with_axe)
{
     DrawText ("Game over!!!", 960, 540, 100, RED);
}
else
{
     // Game logic begins

     // Update the edges
     l_circle_x = circle_x - Circle_radius;
     r_circle_x = circle_x + Circle_radius;
     u_circle_y = circle_y - Circle_radius;
     b_circle_y = circle_y + Circle_radius;
     L_axe_x = axe_x;
     r_axe_x = axe_x + axe_length;
     u_axe_y = axe_y;
     b_axe_y = axe_y + axe_length;

     // Update collision with axe
     Collision_with_axe = 
               (b_axe_y >= u_circle_y) && 
               (u_axe_y <= b_circle_y) && 
               (L_axe_x <= r_circle_x) && 
               (r_axe_x >= l_circle_x);

          DrawCircle(circle_x, circle_y, Circle_radius, BLUE);
          DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);

          // move the axe
          axe_y += direction;
     if (axe_y > height || axe_y < 0)
     {
          direction = -direction;
     }

          if (IsKeyDown(KEY_D) && circle_x < width)
          {
     circle_x += 10;
          }
          if (IsKeyDown(KEY_A) && circle_x > 0)
     
          {
     circle_x -= 10;

          }
          if (IsKeyDown(KEY_W) && circle_y > 0)
          {
     circle_y -= 10;

          }
          if (IsKeyDown(KEY_S) && circle_y < height)
          {
     circle_y += 10;

          }  
     }

EndDrawing();
// Game logic Ends
}
}