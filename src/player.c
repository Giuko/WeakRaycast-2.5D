// player.c

#include "raylib.h"
#include "raycaster.h"
#include "player.h"
#include "world.h"
#include <stdio.h>
#include "math.h"

extern int map[MAP_HEIGHT][MAP_WIDTH];
Player player;

static int Collides(float x, float y){
  const float r = 0.0f;
  int collision = 0; 
  x /= TILE_SIZE;
  y /= TILE_SIZE;
  collision |= IsWall(x-r, y-r);
  collision |= IsWall(x-r, y+r);
  collision |= IsWall(x+r, y-r);
  collision |= IsWall(x+r, y+r);

  return collision;
}

void SpawnPlayer(){
  int posX;
  int posY;

  player.angle = 0.0f;

  while(1){
    posX = GetRandomValue(0, 7);
    posY = GetRandomValue(0, 7);
    if(map[posY][posX]) continue;
    player.pos.x = (posX + 0.5f) * TILE_SIZE;
    player.pos.y = (posY + 0.5f) * TILE_SIZE;
    return;
  }
}

void DrawPlayer(){
  Color playerColor = RED;
  DrawCircleV(player.pos, (float)TILE_SIZE/4, playerColor);
/*
  float rayAngleX;
  float rayAngleY;
  int rayLen = 60;

  rayAngleX = cx + cosf(player.angle) * rayLen;
  rayAngleY = cy + sinf(player.angle) * rayLen;

  DrawLine(cx, cy, rayAngleX, rayAngleY, YELLOW);
*/
  CastRay(player.pos, player.angle);
}

void InputPlayer(){
  int up    = IsKeyDown(KEY_W) || IsKeyDown(KEY_UP); 
  int down  = IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN); 
  int right = IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT); 
  int left  = IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT); 

  float rotationSpeed =  5.0f;
  float movementSpeed =  50.0f;

  Vector2 nextPos = player.pos;

  if(right) player.angle += rotationSpeed * GetFrameTime();
  if(left)  player.angle -= rotationSpeed * GetFrameTime();
  float angle = player.angle;
  
  if(up)    nextPos.x += movementSpeed * GetFrameTime() * cosf(angle);
  if(up)    nextPos.y += movementSpeed * GetFrameTime() * sinf(angle);
  
  if(down)  nextPos.x -= movementSpeed * GetFrameTime() * cosf(angle);
  if(down)  nextPos.y -= movementSpeed * GetFrameTime() * sinf(angle);

  if(Collides(nextPos.x, nextPos.y)) return;
  player.pos = nextPos;
}
