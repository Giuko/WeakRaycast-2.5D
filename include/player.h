#ifndef __PLAYER_H
#define __PLAYER_H

#include "raylib.h"

typedef struct {
  Vector2 pos;
} Player;

void SpawnPlayer();
void DrawPlayer();
#endif 
