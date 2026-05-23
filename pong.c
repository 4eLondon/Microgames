#include <raylib.h>

// Fucntion to find the exact center of the screen
void enableCenter() {
  DrawLine(0, GetScreenHeight() / 2, GetScreenWidth(), GetScreenHeight() / 2,BLUE); // x
  DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(),BLUE); // y
}

// Function to draw up a divider
void drawDivider(int screenWidth, int screenHeight) {
  int thickness = 2;
  DrawRectangle(screenWidth / 2 - thickness / 2, 0, thickness, screenHeight,DARKGRAY);
}

int main(){

    // - - - Variables
    const int windowWidth = 850 , windowHeight = 650;

    // Paddles
    float paddleHeight = 70.0, paddleWidth = 10.0;
    float paddle1_X = 50, paddle1_Y = (float)windowHeight/2-(float)paddleHeight/2;
    float paddle2_X = (float)windowWidth-paddleWidth - 50, paddle2_Y = (float)windowHeight/2-paddleHeight/2;
    float paddleSpeed = 10.0;

    // Ball
    float ballHeight = 10.0, ballWidth = 10.0;


    // - - - Objects (x,y,w,h)
    Rectangle player1Paddle = {paddle1_X, paddle1_Y, paddleWidth, paddleHeight};

    Rectangle player2Paddle = {paddle2_X, paddle2_Y, paddleWidth, paddleHeight};

    Rectangle ball = {(float)windowWidth/2 - ballWidth/2,(float)windowHeight/2 - ballHeight/2,ballWidth,ballHeight};

    // - - - Global Settings
    InitWindow(windowWidth,windowHeight,"Pong");
    SetTargetFPS(30);

    // - - - Main game loop
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);

        // Drawing
        drawDivider(windowWidth,windowHeight); // draw divider
        DrawRectangleRec(player1Paddle, LIGHTGRAY); // draw left paddle
        DrawRectangleRec(player2Paddle, GRAY); // draw right paddle
        DrawRectangleRec(ball, RED); // draw ball
  
        // Controls
        if(IsKeyDown(KEY_W)){
           player1Paddle.y = paddle1_Y -= paddleSpeed;
        }
        if(IsKeyDown(KEY_S)){
          player1Paddle.y =  paddle1_Y += paddleSpeed;
        }
        if(IsKeyDown(KEY_UP)){
           player2Paddle.y = paddle2_Y -= paddleSpeed;
        }
        if(IsKeyDown(KEY_DOWN)){
          player2Paddle.y =  paddle2_Y += paddleSpeed;
        }

        //enableCenter();

        EndDrawing();
    }
    CloseWindow();

    return 0;
}
