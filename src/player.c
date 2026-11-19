// player.c

#include "raylib.h"
#include "player.h"
#include "world.h"
#include <stdio.h>

extern int map[MAP_HEIGHT][MAP_WIDTH];
Player player;

void SpawnPlayer(){
  int posX;
  int posY;

  while(1){
    posX = GetRandomValue(0, 7);
    posY = GetRandomValue(0, 7);
    if(map[posY][posX]) continue;
    player.pos.x = posX;
    player.pos.y = posY;
    return;
  }
}

void DrawPlayer(){
  int cx, cy;
  Color playerColor = RED;
  
  cx = (player.pos.x+1) * TILE_SIZE - (int)(TILE_SIZE/2);
  cy = (player.pos.y+1) * TILE_SIZE - (int)(TILE_SIZE/2);

  DrawCircle(cx, cy, (int)(TILE_SIZE/4), playerColor);
}
