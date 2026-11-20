#ifndef __WORLD_H
#define __WORLD_H

#define TILE_SIZE    64 
#define MAP_WIDTH     8
#define MAP_HEIGHT    8

#define WORLD_WIDTH  800
#define WORLD_HEIGHT 600

#define MAX_WALL_SIZE (WORLD_WIDTH)*8

#include "raylib.h"

void DrawMapGrid();
void DrawMap();
void DrawWorld();
int IsWall(float x, float y);
int IsWallV(Vector2 pos);
int CircleCollides(float x, float y, float r);
int CircleCollidesV(Vector2 pos, float r);
int PixelCollides(float x, float y);
int PixelCollidesV(Vector2 pos);

#endif
