#include "paddle.h"
#include <raylib.h>

Paddle::Paddle(){
    width = 25;
    height = 120;
    x = GetScreenWidth() - width - 10;
    y = GetScreenHeight()/2 - height/2;
    speed = 6;
}

void Paddle::Draw(){
  DrawRectangle(x, y, width, height, WHITE);
}

void Paddle::Update(){
  if(IsKeyDown(KEY_UP)){
    y = y - speed;
  }
  if(IsKeyDown(KEY_DOWN)){
    y = y + speed;
  }

  LimitMovement();
}

//Collision
void Paddle::LimitMovement(){
  if(y <= 0){
    y = 0;
  };
  if(y + height >= GetScreenHeight()){
    y = GetScreenHeight() - height;
  };
};