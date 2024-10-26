#ifndef PADDLE_H
#define PADDLE_H

#include <raylib.h>

class Paddle{
    protected:
      void LimitMovement();
    public:
      Paddle();
      void Draw();
      void Update();

      float x,y;
      float width, height;
      int speed;
};


#endif