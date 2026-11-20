// world.c

#include "player.h"
#include "raylib.h"
#include "raycaster.h"
#include "world.h"
#include "math.h"

extern Raycaster raycaster;
extern Player player;

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

void DrawWorld(){
  const int columnWidht = WORLD_WIDTH / CAST_RAY_DENSITY;
  Color WallColor = RED;
  for(int i = 0; i < CAST_RAY_DENSITY; i++){
    int posX = i * columnWidht;
    float d = raycaster.rays[i].dist * cosf(raycaster.rays[i].angle - player.angle);
    int h = MAX_WALL_SIZE / d;
    if(d < 50)
        WallColor = (Color){255, 40, 40, 255};
    else if(d < 100)
        WallColor = (Color){230, 30, 30, 255};
    else if(d < 150)
        WallColor = (Color){200, 20, 20, 255};
    else if(d < 200)
        WallColor = (Color){170, 15, 15, 255};
    else if(d < 250)
        WallColor = (Color){140, 10, 10, 255};
    else if(d < 300)
        WallColor = (Color){110, 5, 5, 255};
    else if(d < 350)
        WallColor = (Color){80, 0, 0, 255};
    else if(d < 400)
        WallColor = (Color){50, 0, 0, 255};
    else
        WallColor = (Color){25, 0, 0, 255};

    int posY = (WORLD_HEIGHT/2) - h/2;
    DrawRectangle(posX, posY, columnWidht, h, WallColor);
  }
}

int IsWall(float x, float y){
  int mapX = (int)floorf(x);
  int mapY = (int)floorf(y);

  if(mapX < 0 || mapX >= MAP_WIDTH || mapY < 0 || mapY >= MAP_HEIGHT) 
    return 1;
  return map[mapY][mapX];
}
int IsWallV(Vector2 pos){
  return IsWall(pos.x, pos.y);
}

int CircleCollides(float x, float y, float r){
  int collision = 0; 
  x /= TILE_SIZE;
  y /= TILE_SIZE;
  r /= TILE_SIZE;
  collision |= IsWall(x-r, y-r);
  collision |= IsWall(x-r, y+r);
  collision |= IsWall(x+r, y-r);
  collision |= IsWall(x+r, y+r);

  return collision;
}
int CircleCollidesV(Vector2 pos, float r){
  return CircleCollides(pos.x, pos.y, r);
}
int PixelCollides(float x, float y){
  float xTile = x / TILE_SIZE;
  float yTile = y / TILE_SIZE;

  return IsWall(xTile, yTile);
}
int PixelCollidesV(Vector2 pos){
  return PixelCollides(pos.x, pos.y);
}
