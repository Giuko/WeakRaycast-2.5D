// raycaster.c

#include "raylib.h"
#include <math.h>

void CastRay(Vector2 pos, float angle){
  Vector2 startPos = pos;
  Vector2 endPos;
  Color RayColor = YELLOW;

  endPos.x = startPos.x + cosf(angle) * 30;
  endPos.y = startPos.y + sinf(angle) * 30;

  DrawLineV(startPos, endPos, RayColor);


}


