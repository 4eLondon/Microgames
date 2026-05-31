
#include <raylib.h>
#include <stdio.h>

// Fucntion to find the exact center of the screen
void enableCenter() {
  DrawLine(0, GetScreenHeight() / 2, GetScreenWidth(), GetScreenHeight() / 2,BLUE); // x
  DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(),BLUE); // y
}

// Function to draw up a divider
void drawDivider(int screenWidth, int screenHeight) {
  int thickness = 2;
  DrawRectangle((screenWidth / 2 ) - (thickness / 2), 0, thickness, screenHeight,DARKGRAY);  
}

// Function to draw score
void drawScore(){
    int player_1_Score, player_2_Score = 0;
    int fontSize = 42;
    int xPosition =  GetScreenWidth()/2 - fontSize/4, yPosition = 40;
    DrawText(TextFormat("%i",player_1_Score), xPosition + GetScreenWidth()/4, yPosition, fontSize, LIGHTGRAY);
    DrawText(TextFormat("%i", player_2_Score), xPosition - GetScreenWidth()/4, yPosition, fontSize, GRAY);
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
    float ballVelocity_X, ballVelocity_Y = 150.0;
    int isBallActive = 0;


    // - - - Objects (x,y,w,h)
    Rectangle player1Paddle = {paddle1_X, paddle1_Y, paddleWidth, paddleHeight};

    Rectangle player2Paddle = {paddle2_X, paddle2_Y, paddleWidth, paddleHeight};

    Rectangle ball = {(float)windowWidth/2 - ballWidth/2,(float)windowHeight/2 - ballHeight/2,ballWidth,ballHeight};


    // - - - UI
    float boundingBoxThickness = 4;
    Rectangle boundingBox = {10,10,windowWidth-20,windowHeight-20};


    // - - - Global Settings
    InitWindow(windowWidth,windowHeight,"Pong");
    SetTargetFPS(30);


    // - - - Main game loop
    while(!WindowShouldClose()){

    float dt = GetFrameTime();

        // + + Limits

         if(player1Paddle.y >= windowHeight ){
            paddle1_Y = windowHeight - paddleHeight;
        }

       
        if(player1Paddle.y < 0){
            paddle1_Y = 0;
        }

        if(player2Paddle.y > windowHeight ){
            paddle2_Y = windowHeight - player2Paddle.height;
        }
        
        if(player2Paddle.y < 0){
            paddle2_Y = 0;
        }

        if(ball.y - ballHeight <= 0 || ballHeight + ball.y >= windowHeight ){
            ballVelocity_Y *=-1;
        }


        // + + Controls
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


        if(IsKeyPressed(KEY_SPACE)){
            isBallActive = 1; 
        }
        if(isBallActive==1){
            ball.x -= ballVelocity_X * dt;
            ball.y -= ballVelocity_Y * dt;
        }

        //enableCenter();
    
    
        // - - - Drawing
        BeginDrawing();
          ClearBackground(BLACK);

          drawScore(); // Draw Score to the screen
          drawDivider(windowWidth,windowHeight); // draw divider
                                               
          DrawRectangleRec(player1Paddle, LIGHTGRAY); // draw left paddle
          DrawRectangleRec(player2Paddle, GRAY); // draw right paddle
          DrawRectangleRec(ball, RED); // draw ball
                                       
          DrawRectangleLinesEx(boundingBox, boundingBoxThickness, DARKGRAY);// draw bounding box
  
        EndDrawing();
    }
    CloseWindow();

    return 0;
}

