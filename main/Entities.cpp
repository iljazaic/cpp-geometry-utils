#include "Geometry.cpp"

enum TEXTURES
{
    SMOOTH,
    ROUGH,
    GLASS
};

class LightSource
{
public:
    double intensity;
    Vector2d position;
    Vector2d direction;
    double FOV; // IN RADIANS REMEMBER

    LightSource(double intensity_, Vector2d position_, Vector2d direction_)
    {
        intensity = intensity_;
        position = position_;
        direction = direction_;
        FOV = M_PI_2; // 45 deg
    }
};

class Player
{
public:
    Vector2d position;
    Vector2d direction;

    Player()
    {
        position = *(new Vector2d(0.0, 0.0));
        direction = *(new Vector2d(1.0, 1.0));
        direction._normalize();
    };

    void moveTick(Vector2d direction_)
    {
        direction_._normalize();
        position._add(direction_);
    }

    void rotateTick(double angle)
    {
        direction._rotate(angle);
    };
};

class Wall
{
public:
    enum TEXTURES texture;
    Line2d lineOnMap;
    int brightness; // from 1 to 100?


    Wall(Line2d line){
        lineOnMap=line;
        brightness=0;
    }
    Wall(Line2d line, enum TEXTURES texture_){
        texture = texture_;
        lineOnMap= lineOnMap;
        brightness=0;
    }

    
};