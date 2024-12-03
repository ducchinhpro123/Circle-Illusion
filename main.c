#include <raylib.h>
#include <math.h>
#include <stdbool.h>


#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000
#define DOT_COUNT 10
#define T 10 // Oscillation period

int main()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "CIRCLE");
    SetTargetFPS(60);

    float circle_radius_x = WINDOW_WIDTH/2.0f;
    float circle_radius_y = WINDOW_HEIGHT/2.0f;
    float circle_radius = WINDOW_WIDTH/3.0f;

    /* float moving_circle_radius = 10.0f; */
    /* float direction = 1; */
    /* float angle = 0.0f; */
    float amplitude = circle_radius;
    float fre = 0.2f;
    float phase = PI / DOT_COUNT;
    float theta = PI / DOT_COUNT;
    float time = 0.0f;

    while(!WindowShouldClose()) {
        BeginDrawing();
            time += GetFrameTime();
            ClearBackground(BLACK);
            DrawCircleLines(circle_radius_x, circle_radius_y, circle_radius, RED);
            // Draw lines
            for (int i = 0; i < DOT_COUNT; i++) {
                float x_start = circle_radius_x - amplitude * cos(i*theta);
                float y_start = circle_radius_y - amplitude * sin(i*theta);
                float x_end = circle_radius_x + amplitude * cos(i*theta);
                float y_end = circle_radius_y + amplitude * sin(i*theta);
                DrawLine(x_start, y_start, x_end, y_end, WHITE);
            }

            /* https://www.mathworks.com/matlabcentral/fileexchange/90591-circle-illusion-moving-dots-to-rotating-circle
             for i = 1:N
                px(:,i) = A*sin(2*pi*f*t + i*ph) * cos(i*th);
                py(:,i) = A*sin(2*pi*f*t + i*ph) * sin(i*th);
             end
             */
            for (int i = 0; i < DOT_COUNT; i++) {
            /* RLAPI void DrawCircle(int centerX, int centerY, float radius, Color color); */
                float x = circle_radius_x + amplitude * sin(2*PI*fre*time + i*phase) * cos(i*theta);
                float y = circle_radius_y + amplitude * sin(2*PI*fre*time + i*phase) * sin(i*theta);
                DrawCircle(x, y, 10, RED);
            }


            /* DrawLine(circle_radius_x, circle_radius_y - circle_radius, circle_radius_x, circle_radius_y + circle_radius, RED); */
            /* DrawLine(circle_radius_x - circle_radius, circle_radius_y, circle_radius_x + circle_radius, circle_radius_x, RED); */

            /* /1* RLAPI void DrawCircle(int centerX, int centerY, float radius, Color color);      // Draw a color-filled circle *1/ */
            /* DrawCircle(circle_radius_x, moving_circle, moving_circle_radius, YELLOW); */
            /* DrawCircle(moving_circle_2, circle_radius_y, moving_circle_radius, YELLOW); */

            /* DrawLine(circle_radius_x, moving_circle, moving_circle, circle_radius_y, GREEN); */
            /* DrawCircle(circle_radius_x + (moving_circle - circle_radius_x)/2.0f, circle_radius_y + (moving_circle - circle_radius_y)/2.0f, 10, YELLOW); */
            /* DrawCircle(moving_circle, (moving_circle + circle_radius)/2.0f, 10, YELLOW); */

            /* DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, Color color); */
        EndDrawing();
    }
    CloseWindow();

    return 0;
}