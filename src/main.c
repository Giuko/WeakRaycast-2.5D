// main.c
#include "player.h"
#include "raylib.h"
#include "world.h"
#include <stdio.h>

#define SCREEN_WIDTH  (TILE_SIZE * 8)
#define SCREEN_HEIGHT (TILE_SIZE * 8)

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
    DrawMap();
    DrawPlayer();

    DrawFPS(SCREEN_WIDTH - 100, 40);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
