#include <raylib.h>

int main(){
    // - - - Variables
    const int windowWitdth = 850 , windowHeight = 650;
    
    // - - - Make window
    InitWindow(windowWitdth,windowHeight,"Pong");

    // - - - Main game loop
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
