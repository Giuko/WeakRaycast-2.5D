// world.c

#include "raylib.h"
#include "world.h"
#include "math.h"

// 2D map representation
const int map[MAP_HEIGHT][MAP_WIDTH] = {
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 1, 0, 1, 1, 0, 1},
  {1, 0, 1, 0, 0, 1, 0, 1},
  {1, 0, 1, 1, 0, 1, 0, 1},
  {1, 0, 1, 1, 1, 1, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
};

void DrawMapGrid(){
  for(int i = 0; i < MAP_HEIGHT; i++)
    for(int j = 0; j < MAP_WIDTH; j++){
      int x0 = (j+0) * TILE_SIZE;
      int y0 = (i+0) * TILE_SIZE;
      int x1 = (j+1) * TILE_SIZE;
      int y1 = (i+1) * TILE_SIZE;

      DrawLine(x0, y0, x0, y1, BLACK);
      DrawLine(x0, y0, x1, y0, BLACK);
    }
}

void DrawMap(){
  for(int i = 0; i < MAP_HEIGHT; i++)
    for(int j = 0; j < MAP_WIDTH; j++){
      int x0 = (j+0) * TILE_SIZE;
      int y0 = (i+0) * TILE_SIZE;
      Color c;

      c = (map[i][j]) ? DARKGRAY : LIGHTGRAY;

      DrawRectangle(x0, y0, TILE_SIZE, TILE_SIZE, c);
    }


  DrawMapGrid();
}

int IsWall(float x, float y){
  int mapX = (int)floorf(x);
  int mapY = (int)floorf(y);

  if(mapX < 0 || mapX >= MAP_WIDTH || mapY < 0 || mapY >= MAP_HEIGHT) 
    return 1;
  return map[mapY][mapX];
}
