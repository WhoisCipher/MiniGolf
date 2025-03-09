#include "raylib.h"
#include "raymath.h"

struct Circle {
    Vector2 Position;
    Vector2 Velocity;
    float radius;
    bool isMoving;
};

void checkCollision(Rectangle& Rec, Circle& Cir){
    if (CheckCollisionCircleRec(Cir.Position, Cir.radius, Rec)) {
            // Determine the side of the rectangle that was hit and reflect velocity accordingly
            Rectangle expandedObst = {Rec.x - Cir.radius, Rec.y - Cir.radius, Rec.width + 2 * Cir.radius, Rec.height + 2 * Cir.radius};

            Vector2 ballCenterToObstCenter = Vector2Subtract(Cir.Position, (Vector2){Rec.x + Rec.width / 2, Rec.y + Rec.height / 2});
            float overlapX = Rec.width / 2 + Cir.radius - fabs(ballCenterToObstCenter.x);
            float overlapY = Rec.height / 2 + Cir.radius - fabs(ballCenterToObstCenter.y);

            if (overlapX < overlapY) {
                // Horizontal collision
                if (ballCenterToObstCenter.x > 0) {
                    Cir.Position.x = Rec.x + Rec.width + Cir.radius;
                } else {
                    Cir.Position.x = Rec.x - Cir.radius;
                }
                Cir.Velocity.x = -Cir.Velocity.x * 0.8f;
            } else {
                // Vertical collision
                if (ballCenterToObstCenter.y > 0) {
                    Cir.Position.y = Rec.y + Rec.height + Cir.radius;
                } else {
                    Cir.Position.y = Rec.y - Cir.radius;
                }
                Cir.Velocity.y = -Cir.Velocity.y * 0.8f;
            }
        }
}

int main() {
    const int screenWidth = 1000;
    const int screenHeight = 750;

    const Color grass = {9, 93, 64, 255};
    const Color pot = {40, 40, 40, 255};

    Rectangle obst = {600, 120, 60, 250};
    Rectangle obst2 = {200, 380, 60, 250};

    Circle ball = {{750, 600}, {0, 0}, 30, false};
    Circle ballPot = {{200, 100}, {0, 0}, 25, false};

    float friction = 0.9995f;

    bool isBallPotted = false;

    InitWindow(screenWidth, screenHeight, "Golf");


    while (!WindowShouldClose()) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !ball.isMoving && !isBallPotted) {
            Vector2 distanceToBall = Vector2Subtract(GetMousePosition(), ball.Position);
            ball.Velocity = Vector2Negate(distanceToBall);
            ball.Velocity = Vector2Scale(ball.Velocity, 5);
            ball.isMoving = true;
        }

        ball.Position = Vector2Add(ball.Position, Vector2Scale(ball.Velocity, GetFrameTime()));

        ball.Velocity.x *= friction;
        ball.Velocity.y *= friction;

        if (Vector2Length(ball.Velocity) < 10.0f) {
            ball.Velocity = Vector2Zero();
            ball.isMoving = false;
        }

        if(CheckCollisionCircles(ball.Position, ball.radius, ballPot.Position, ballPot.radius)){
            if(Vector2Length(ball.Velocity) < 20.0f){
                ball.Position = ballPot.Position;
                isBallPotted = true;
            }
        }

        // Handle window boundary collision
        if (ball.Position.x - ball.radius <= 0) {
            ball.Position.x = ball.radius;
            ball.Velocity.x = -ball.Velocity.x * 0.8f;
        }

        else if (ball.Position.x + ball.radius >= screenWidth) {
            ball.Position.x = screenWidth - ball.radius;
            ball.Velocity.x = -ball.Velocity.x * 0.8f;
        }

        if (ball.Position.y - ball.radius <= 0) {
            ball.Position.y = ball.radius;
            ball.Velocity.y = -ball.Velocity.y * 0.8f;
        }

        else if (ball.Position.y + ball.radius >= screenHeight) {
            ball.Position.y = screenHeight - ball.radius;
            ball.Velocity.y = -ball.Velocity.y * 0.8f;
        }

        checkCollision(obst, ball);
        checkCollision(obst2, ball);

        if(isBallPotted){
            ball.radius -= 0.05;
        }

        BeginDrawing();

            ClearBackground(grass);
            DrawCircleV(ballPot.Position, 36, pot);
            DrawCircleV(ballPot.Position, 25, (Color){60, 60, 60, 255});
            DrawRectanglePro(obst, {0, 0}, 0, {40, 40, 40, 255});
            DrawRectanglePro(obst2, {0, 0}, 0, {40, 40, 40, 255});
            DrawCircleV(ball.Position, ball.radius, WHITE);


            if(!isBallPotted && !ball.isMoving){
                DrawLineV((GetMousePosition()), ball.Position, BLACK);
            }

            if(isBallPotted)
                DrawText("ball Potted!", screenWidth/2 - 280, screenHeight/2 - 50, 100, LIME);


        EndDrawing();
    }

    CloseWindow();
    return 0;
}
