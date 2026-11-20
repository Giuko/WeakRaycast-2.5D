#ifndef __WORLD_H
#define __WORLD_H

#define TILE_SIZE    64 
#define MAP_WIDTH     8
#define MAP_HEIGHT    8

#include "raylib.h"

void DrawMapGrid();
void DrawMap();
int IsWall(float x, float y);
int IsWallV(Vector2 pos);

#endif
