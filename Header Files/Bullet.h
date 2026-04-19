    #ifndef BULLET_H
    #define BULLET_H

    #include <raylib.h>

    class Bullet
    {
        private:
            float x;
            float y;

            double speed;

            float directionX;
            float directionY;

            int radius;

        public:
            Bullet(float x, float y, float dirX, float dirY);

            void updateDirection();
            void drawBullet();

            //Vector2 To get 2 Variables Vector (Co-ordinates of the BULLET)
            Vector2 getPosition();

            int getRadius();

    };

    #endif