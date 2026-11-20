// raycaster.c

#include "raycaster.h"
#include "raylib.h"
#include "raymath.h"
#include "world.h"
#include <math.h>
#include <stdio.h>

Raycaster raycaster;

// Deprecated don't use
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

// Deprecated don't use
float CastRayV(Vector2 pos, float angle){
  return CastRay(pos.x, pos.y, angle);
}

Ray2D CastRay_DDA(float x, float y, float angle){
  Ray2D ray;
  float dist = 0.0f;
  
  Vector2 startPos;
  Vector2 endPos;
  startPos = (Vector2){x, y};
  Vector2 dir;
  Vector2 distToNextCell;
  Vector2 timeToNextCell;
  float shortestTimeToNextCell;
  Vector2 hit;

  dir.x = cosf(angle);
  dir.y = sinf(angle);

  // Initialize hit = startPos, in next loop startPos will be the next hit
  hit = startPos;

  while(1){
    startPos = hit;
    if(dir.x >= 0)
      distToNextCell.x = TILE_SIZE - ((int)startPos.x % TILE_SIZE);
    else
      distToNextCell.x = ((int)startPos.x % TILE_SIZE);

    if(dir.y >= 0)
      distToNextCell.y = TILE_SIZE - ((int)startPos.y % TILE_SIZE);
    else
      distToNextCell.y = ((int)startPos.y % TILE_SIZE);
    

    // We are on the border, so the next TILE is at the after an entire TILE_SIZE
    // But if we are going back, we don't need to reach the next TILE, but we need to stop.
    // The problem is that if we put 0, we are never going to exceed and reaching the wall (infinite loop)
    // instead with a small amount of movement we are capable of going out of the loop
    if(distToNextCell.x == 0) distToNextCell.x = (dir.x >= 0.0f) ? TILE_SIZE : 0.1f;
    if(distToNextCell.y == 0) distToNextCell.y = (dir.y >= 0.0f) ? TILE_SIZE : 0.1f;

    if(dir.x >= -0.01f && dir.x <= 0.01f)
      timeToNextCell.x = INFINITY;  // division by 0
    else
      timeToNextCell.x = fabsf(distToNextCell.x / dir.x);

    if(dir.y >= -0.01f && dir.y <= 0.01f)
      timeToNextCell.y = INFINITY;  // division by 0
    else
      timeToNextCell.y = fabs(distToNextCell.y / dir.y);
    
    shortestTimeToNextCell = (timeToNextCell.x < timeToNextCell.y) ? timeToNextCell.x : timeToNextCell.y;

    hit.x = startPos.x + dir.x * shortestTimeToNextCell;
    hit.y = startPos.y + dir.y * shortestTimeToNextCell;
    if(PixelCollidesV(hit)) break;
  }
  
  startPos = (Vector2){x, y};
  endPos   = hit;
  dist = Vector2Distance(startPos, endPos);
  ray.dist = dist;
  ray.startPos = startPos;
  ray.endPos = endPos;
  return ray;
}

Ray2D CastRayV_DDA(Vector2 pos, float angle){
  return CastRay_DDA(pos.x, pos.y, angle);
}
