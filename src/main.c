// main.c
#include "player.h"
#include "raylib.h"
#include "world.h"
#include <stdio.h>

#define SCREEN_WIDTH  (WORLD_WIDTH)
#define SCREEN_HEIGHT (WORLD_HEIGHT)

int main(void){
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Window");
  SetTargetFPS(60);
  SetTraceLogLevel(LOG_DEBUG);

  SpawnPlayer();
  while(!WindowShouldClose()){

    // ----- Update -----
    InputPlayer();

    // -----  Draw  ----- 
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawRectangle(0, 0, WORLD_WIDTH, WORLD_HEIGHT / 2, SKYBLUE); // Sky
    DrawRectangle(0, WORLD_HEIGHT / 2, WORLD_WIDTH, WORLD_HEIGHT / 2, WHITE); // Floor
    
    //DrawMap();
    //DrawPlayer();
    DrawWorld();

    DrawFPS(SCREEN_WIDTH - 100, 40);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
