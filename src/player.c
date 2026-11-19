// player.c

#include "raylib.h"
#include "player.h"
#include "world.h"
#include <stdio.h>
#include "math.h"

extern int map[MAP_HEIGHT][MAP_WIDTH];
Player player;

void SpawnPlayer(){
  int posX;
  int posY;

  player.angle = 0.0f;

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

  DrawCircle(cx, cy, (float)TILE_SIZE/4, playerColor);

  float rayAngleX;
  float rayAngleY;
  int rayLen = 60;

  rayAngleX = cx + cosf(player.angle) * rayLen;
  rayAngleY = cy + sinf(player.angle) * rayLen;

  DrawLine(cx, cy, rayAngleX, rayAngleY, YELLOW);
}

void InputPlayer(){
  int up    = IsKeyDown(KEY_W) || IsKeyDown(KEY_UP); 
  int down  = IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN); 
  int right = IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT); 
  int left  = IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT); 

  float rotationSpeed =  5.0f;
  float movementSpeed =  5.0f;
  float angle = player.angle;

  if(right) player.angle += rotationSpeed * GetFrameTime();
  if(left)  player.angle -= rotationSpeed * GetFrameTime();
  
  if(up)    player.pos.x += movementSpeed * GetFrameTime() * cosf(angle);
  if(up)    player.pos.y += movementSpeed * GetFrameTime() * sinf(angle);
  
  if(down)  player.pos.x -= movementSpeed * GetFrameTime() * cosf(angle);
  if(down)  player.pos.y -= movementSpeed * GetFrameTime() * sinf(angle);
}
