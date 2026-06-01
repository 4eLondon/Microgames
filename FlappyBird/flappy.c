#include <raylib.h>
// Constants
const int winWidth = 850, winHeight = 650;
// Functions
void spawnPipe(){
    // Global Pipe dimensions
    int pipeWidth = winWidth/8, pipeHeight = winHeight/3;
    // Pipe Positions
    int topPipeXPosition = winWidth - pipeWidth, 
        topPipeYPosition = 0;
    int botPipeXPosition = winWidth - pipeWidth, 
        botPipeYPosition = winHeight - pipeHeight;
    // Top Pipe object
    Rectangle topPipe = {topPipeXPosition, 
        topPipeYPosition,
        pipeWidth,
        pipeHeight
    };
    // Bottom Pipe object
    Rectangle botPipe = {botPipeXPosition, 
        botPipeYPosition,
        pipeWidth, 
        pipeHeight
    };
    // Draw Both pipes
    DrawRectangleRec(topPipe, DARKGRAY);
    DrawRectangleRec(botPipe, DARKGRAY);
}
void spawnPlayer(){
    // Player Scale (Height & Width)
    int playerScale = 40; 
    // Player Position
    int playerXPosition = 0, playerYPosition = winHeight/2 - playerScale/2;
    // Player object (x,y,width,height)
    Rectangle player = {playerXPosition,
        playerYPosition,
        playerScale,
        playerScale
    };
    // Draw player
    DrawRectangleRec(player, RED);
}
void grid(){
    Vector2 X = {(float)winWidth/2, (float)winHeight};
    Vector2 Y = {(float)winWidth/2, 0};
    Vector2 A = {0, (float)winHeight/2};
    Vector2 B = {(float)winWidth, (float)winHeight/2};
    DrawLineV(X, Y, BLUE);
    DrawLineV(A, B, BLUE);
}
int main(){
    InitWindow(winWidth, winHeight, "Flappy bird");
    while(!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(LIGHTGRAY);
            spawnPipe();
            spawnPlayer();
            grid();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
