// player.c

#include "raylib.h"
#include "raycaster.h"
#include "player.h"
#include "world.h"
#include <stdio.h>
#include "math.h"

extern Raycaster raycaster;
extern int map[MAP_HEIGHT][MAP_WIDTH];
Player player;

void SpawnPlayer(){
  int posX;
  int posY;

  player.angle         = 0.0f;
  player.movementSpeed = MOVEMENT_SPEED;
  player.rotationSpeed = ROTATION_SPEED;

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
  Vector2 minimap_pos = (Vector2){player.pos.x/MINIMAP_RESIZE, player.pos.y/MINIMAP_RESIZE};
  DrawCircleV(minimap_pos, (float)TILE_SIZE/4/MINIMAP_RESIZE, playerColor);
/*
  float CastRayRange   = CAST_RAY_RANGE;
  int   CastRayDensity = CAST_RAY_DENSITY;

  float fmin = -CastRayRange/2;
  float fmax =  CastRayRange/2;
  float step =  CastRayRange/CastRayDensity;

  for(float fi = fmin; fi < fmax; fi += step){
    CastRayV(player.pos, player.angle + fi);
  }
*/
}

void InputPlayer(){
  int hasMoved;
  int up    = IsKeyDown(KEY_W) || IsKeyDown(KEY_UP); 
  int down  = IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN); 
  int right = IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT); 
  int left  = IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT); 

  if(up || down || right || left) hasMoved = 1;
  else hasMoved = 0;

  float rotationSpeed =  player.rotationSpeed;
  float movementSpeed =  player.movementSpeed;

  Vector2 nextPos = player.pos;

  if(right) player.angle += rotationSpeed * GetFrameTime();
  if(left)  player.angle -= rotationSpeed * GetFrameTime();
  float angle = player.angle;
  
  if(up)    nextPos.x += movementSpeed * GetFrameTime() * cosf(angle);
  if(up)    nextPos.y += movementSpeed * GetFrameTime() * sinf(angle);
  
  if(down)  nextPos.x -= movementSpeed * GetFrameTime() * cosf(angle);
  if(down)  nextPos.y -= movementSpeed * GetFrameTime() * sinf(angle);

  if(CircleCollides(player.pos.x, nextPos.y, 5.0f)) 
    nextPos.y = player.pos.y;

  if(CircleCollides(nextPos.x, player.pos.y, 5.0f)) 
    nextPos.x = player.pos.x;

  if(CircleCollides(nextPos.x, nextPos.y, 5.0f)) return;

  player.pos = nextPos;


  float CastRayRange   = CAST_RAY_RANGE;
  int   CastRayDensity = CAST_RAY_DENSITY;

  float fmin = -CastRayRange/2;
  float fmax =  CastRayRange/2;
  float step =  CastRayRange/CastRayDensity;

  int i = 0;
  if(hasMoved)
    for(float fi = fmin; fi < fmax; fi += step)
      raycaster.rays[i++] = CastRayV_DDA(player.pos, player.angle + fi);

}
