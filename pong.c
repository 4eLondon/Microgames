#include <raylib.h>

// Fucntion to find the exact center of the screen
void enableCenter() {
  DrawLine(0, GetScreenHeight() / 2, GetScreenWidth(), GetScreenHeight() / 2,
           BLUE); // x
  DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(),
           BLUE); // y
}

int main(){
    // - - - Variables
    const int windowWidth = 850 , windowHeight = 650;
    float paddleHeight = 70.0, paddleWidth = 10.0;
    float ballHeight = 10.0, ballWidth = 10.0;


    // - - - Objects (x,y,w,h)
    Rectangle player1Paddle = {50,(float)windowHeight/2-(float)paddleHeight/2, paddleWidth,paddleHeight};

    Rectangle player2Paddle = {(float)windowWidth-paddleWidth - 50,(float)windowHeight/2-paddleHeight/2, paddleWidth,paddleHeight};

    Rectangle ball = {(float)windowWidth/2 - ballWidth/2,(float)windowHeight/2 - ballHeight/2,ballWidth,ballHeight};


    // - - - Global Settings
    InitWindow(windowWidth,windowHeight,"Pong");
    SetTargetFPS(30);

    // - - - Main game loop
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);

        // Drawing
        DrawRectangleRec(player1Paddle, WHITE);
        DrawRectangleRec(player2Paddle, GRAY);
        DrawRectangleRec(ball, RED);
  
        //enableCenter(); 

        
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
