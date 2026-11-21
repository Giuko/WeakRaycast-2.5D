#ifndef __RAYCASTER_H
#define __RAYCASTER_H

#include "raylib.h"

#define CAST_RAY_RANGE   1.2f
#define CAST_RAY_DENSITY 100
#define CAST_RAY_STEP    20.0f

typedef struct{
  float dist;
  Vector2 startPos;
  Vector2 endPos;
  float angle;
} Ray2D;

typedef struct{
  Ray2D rays[CAST_RAY_DENSITY];
} Raycaster; 

float CastRay(float x, float y, float angle);
float CastRayV(Vector2 pos, float angle);
Ray2D CastRay_DDA(float x, float y, float angle);
Ray2D CastRayV_DDA(Vector2 pos, float angle);
#endif
