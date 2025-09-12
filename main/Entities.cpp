#include "vector2d.cpp"

class Bullet{

};


class Player
{
public:
    vector2d position;
    vector2d direction;

    Player()
    {
        position = *(new vector2d(0.0, 0.0));
        direction = *(new vector2d(1.0, 1.0));
        direction._normalize();
    };

    void moveTick(vector2d direction_)
    {
        direction_._normalize();
        position._add(direction_);
    }

    void rotateTick(double angle)
    {
        direction._rotate(angle);
    };
};