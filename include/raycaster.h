#ifndef __RAYCASTER_H
#define __RAYCASTER_H

#include "raylib.h"

#define CAST_RAY_RANGE   2.0f
#define CAST_RAY_DENSITY 50
#define CAST_RAY_STEP    20.0f

float CastRay(float x, float y, float angle);
float CastRayV(Vector2 pos, float angle);
#endif
