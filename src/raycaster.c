// raycaster.c

#include "raylib.h"
#include "world.h"
#include <math.h>

int PixelCollides(float x, float y){
  float xTile = x / TILE_SIZE;
  float yTile = y / TILE_SIZE;

  return IsWall(xTile, yTile);
}
int PixelCollidesV(Vector2 pos){
  return PixelCollides(pos.x, pos.y);
}

float CastRay(Vector2 pos, float angle){
  Vector2 startPos = pos;
  Vector2 endPos = startPos;
  Color RayColor = YELLOW;

  float step = 1.0f;
  float dist = 0.0f;

  while(!PixelCollidesV(endPos)){
    endPos.x = startPos.x + cosf(angle) * dist;
    endPos.y = startPos.y + sinf(angle) * dist;
    dist += step;
  }


  DrawLineV(startPos, endPos, RayColor);

  return dist;
}


