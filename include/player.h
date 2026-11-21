#ifndef __PLAYER_H
#define __PLAYER_H

#include "raylib.h"

#define ROTATION_SPEED 5.0f
#define MOVEMENT_SPEED 100.0f

typedef struct {
  Vector2 pos;
  float angle;
  float movementSpeed;
  float rotationSpeed;
  int hasMoved;
} Player;

void SpawnPlayer();
void DrawPlayer();
void InputPlayer();
#endif 
