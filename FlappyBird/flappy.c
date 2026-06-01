#include <raylib.h>

int main(){

    // Constants
    int winWidth = 850, winHeight = 650;



    InitWindow(winWidth,winWidth,"Flappy bird");

    while(!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
