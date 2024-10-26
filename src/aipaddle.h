#ifndef AI_PADDLE_H
#define AI_PADDLE_H

#include "paddle.h"
#include "ball.h"

//Inherits from paddle class
class AiPaddle : public Paddle{
  public:
    AiPaddle();
    void Update(int ball_y);
};

#endif