#include <cmath>
#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define BOB_RADIUS 10

Vector2 GetEnd(Vector2 start_pos, float len, float theta)
{
    return (Vector2){start_pos.x + len * sinf(theta), start_pos.y + len * cosf(theta)};
}

void DrawDoublePendulum(float l1, float l2, Vector2 start_pos, float theta1, float theta2)
{

    Vector2 end_pos = GetEnd(start_pos, l1, theta1);
    Vector2 end_pos2 = GetEnd(end_pos, l2, theta2);

    // First Pendulum
    DrawLineV(start_pos, end_pos, WHITE);
    // second pendulum
    DrawLineV(end_pos, end_pos2, WHITE);

    // First Ball
    DrawCircleV(end_pos, BOB_RADIUS, RED);
    // Second Ball
    DrawCircleV(end_pos2, BOB_RADIUS, RED);
}

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Double Pendulum");

    while (!WindowShouldClose())
    {

        Vector2 start_pos = (Vector2){SCREEN_WIDTH / 2, 0};
        BeginDrawing();
        ClearBackground(BLACK);
        DrawDoublePendulum(SCREEN_HEIGHT / 3, SCREEN_HEIGHT / 3, start_pos, PI / 4, -PI / 4);
        EndDrawing();
    }
}