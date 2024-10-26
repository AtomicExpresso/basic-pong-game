#include "ball.h"
#include <raylib.h>

Ball::Ball(){
  radius = 10;
  x = 800 / 2;
  y = 450 / 2;
  speed_x = 7;
  speed_y = 7;
  ballHitWav = LoadSound("../resources/ball-hit.wav");
}

void Ball::Draw(){
  DrawCircle(x, y, radius, WHITE);
}

//Update ball position
void Ball::Update(void (*updateScore)(int)){
  x += speed_x;
  y += speed_y;

  //Bounce if hitting top or bottom border
  if (y + radius >= GetScreenHeight() || y - radius <= 0){
      speed_y *= -1;
      PlaySound(ballHitWav);
  }
          
  //Bounce if hitting left or right border, AI WINS
  if (x + radius >= GetScreenWidth()){
    updateScore(2);
    PlaySound(ballHitWav);
    resetBall();
  }
  //Player wins
  if(x - radius <= 0){
    updateScore(1);
    PlaySound(ballHitWav);
    resetBall();
  }
}

void Ball::resetBall(){
  x = GetScreenWidth()/2;
  y = GetScreenHeight()/2;

  int speed_choices[2] = {-1, 1};
  speed_x *= speed_choices[GetRandomValue(0,1)];
  speed_y *= speed_choices[GetRandomValue(0,1)];

}