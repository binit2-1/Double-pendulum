    #include <cmath>
    #include "raylib.h"

    #define SCREEN_WIDTH 800
    #define SCREEN_HEIGHT 600

    #define BOB_RADIUS 10
    #define BOB_MASS 10.0
    #define G 1400


    //global variables
    float l1, l2, m1, m2, theta1, theta2, theta1_d, theta2_d, theta1_dd, theta2_dd;


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



    void step(float dt){

        theta1_dd = (-G*(2 * m1 + m2)*sinf(theta1) - m2 * G * sinf(theta1 - 2 * theta2) - 2 * sinf(theta1 - theta2) * m2 * (theta2_d * theta2_d * l2 + theta1_d * theta1_d * l1 * cosf(theta1 - theta2))) / (l1 * (2 * m1 + m2 - m2 * cosf(2 * theta1 - 2 * theta2)));
        theta2_dd = (2 * sinf(theta1 - theta2) * (theta1_d * theta1_d * l1 * (m1 + m2) + G * (m1 + m2) * cosf(theta1) + theta2_d * theta2_d * l2 * m2 * cosf(theta1 - theta2))) / (l2 * (2 * m1 + m2 - m2 * cosf(2 * theta1 - 2 * theta2)));

        theta1_d += theta1_dd * dt;
        theta2_d += theta2_dd * dt;

        theta1 += theta1_d * dt;
        theta2 += theta2_d * dt;
    }


    void solver(){
        l1 = SCREEN_HEIGHT / 3;
        l2 = SCREEN_HEIGHT / 3;
        m1 = BOB_MASS;
        m2 = BOB_MASS;
        theta1 = GetRandomValue(-90, 90) * DEG2RAD;
        theta2 = GetRandomValue(-90, 90) * DEG2RAD;
        theta1_d = 0;
        theta2_d = 0;

    }

    int main()
    {
        InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Double Pendulum");

        SetTargetFPS(60);
        solver();

        while (!WindowShouldClose())
        {   
            float dt = GetFrameTime();

            Vector2 start_pos = (Vector2){SCREEN_WIDTH / 2, 0};
            step(dt);
            BeginDrawing();
                ClearBackground(BLACK);
                DrawDoublePendulum(l1, l2, start_pos, theta1, theta2);
            EndDrawing();
        }
    }