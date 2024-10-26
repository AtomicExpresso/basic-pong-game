#include "aipaddle.h"

AiPaddle::AiPaddle(){
  x = 10;
}

//Adjust movement according to ball's position 
void AiPaddle::Update(int ball_y){
    int speed_choices[4] = {3, 4, 5, 6};

    if(y + height/2 > ball_y){
      y = y - speed_choices[GetRandomValue(0,3)];
    }
    if(y + height/2 <= ball_y){
      y = y + speed_choices[GetRandomValue(0,3)];
    }
    LimitMovement();
}