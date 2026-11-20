// raycaster.c

#include "raycaster.h"
#include "raylib.h"
#include "world.h"
#include <math.h>


float CastRay(float x, float y, float angle){
  Vector2 startPos = (Vector2){x, y};
  Vector2 endPos = startPos;
  Color RayColor = YELLOW;

  float step = CAST_RAY_STEP;
  float dist = 0.0f;

  while(1){
    endPos.x = startPos.x + cosf(angle) * dist;
    endPos.y = startPos.y + sinf(angle) * dist;
    dist += step;
    if(CircleCollidesV(endPos, 3.0f)) break;
    DrawCircleV(endPos, 2, RayColor);
  }

  return dist;
}

float CastRayV(Vector2 pos, float angle){
  return CastRay(pos.x, pos.y, angle);
}


