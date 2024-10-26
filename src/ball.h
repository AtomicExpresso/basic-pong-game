#ifndef BALL_H
#define BALL_H

#include <raylib.h>


class Ball{
    public:
      Ball();
      void Draw();
      void Update(void (*updateScore)(int));
      void resetBall();

      float x, y;
      int speed_x, speed_y;
      int radius;
      Sound ballHitWav;
};

#endif