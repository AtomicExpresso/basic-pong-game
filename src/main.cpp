#include <raylib.h>
#include "ball.h"
#include "paddle.h"
#include "aipaddle.h"

int playerScore = 0;
int aiScore = 0;

void updateScore(int num);

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitAudioDevice();
    InitWindow(screenWidth, screenHeight, "Raylib Pong");
    SetTargetFPS(60);

    Ball myBall;
    Paddle player;
    AiPaddle aipaddle;

    // Sounds
    Sound paddleHit = LoadSound("../resources/ball-paddle-hit.wav");

    // Main game loop
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        // Checking for ball collision
        if (CheckCollisionCircleRec(Vector2{myBall.x, myBall.y}, myBall.radius, Rectangle{player.x, player.y, player.width, player.height}))
        {
            myBall.speed_x *= -1;
            myBall.x = player.x - myBall.radius;
            PlaySound(paddleHit);
        }

        if (CheckCollisionCircleRec(Vector2{myBall.x, myBall.y}, myBall.radius, Rectangle{aipaddle.x, aipaddle.y, aipaddle.width, aipaddle.height}))
        {
            myBall.speed_x *= -1;
            myBall.x = aipaddle.x + aipaddle.width + myBall.radius;
            PlaySound(paddleHit);
        }

        // Update
        myBall.Update(updateScore);
        player.Update();
        aipaddle.Update(myBall.y);

        // Drawing
        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, LIGHTGRAY);
        myBall.Draw();
        aipaddle.Draw();
        player.Draw();
        DrawText(TextFormat("%i", aiScore), screenWidth / 4 - 20, 20, 60, WHITE);
        DrawText(TextFormat("%i", playerScore), 3 * screenWidth / 4 - 20, 20, 60, WHITE);

        EndDrawing();
    }

    // Unload sounds and close window, if game loop ends
    UnloadSound(myBall.ballHitWav);
    UnloadSound(paddleHit);

    CloseAudioDevice();
    CloseWindow();

    return 0;
}

// Function for updating score
void updateScore(int num)
{
    if (num == 1)
    {
        playerScore += 1;
    }
    else if (num == 2)
    {
        aiScore += 1;
    }
}