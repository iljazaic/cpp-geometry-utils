#include <cmath>







class vector2d
{
public:
    double x;
    double y;
    double mag;
    double theta;

    vector2d()
    {
        x = 0;
        y = 0;
        theta = 0;
        mag = 0;
    }

    vector2d(double x_, double y_)
    {
        x = x_;
        y = y_;
        mag = sqrt(x * x + y * y);
        theta = atan(y / x);
    }

    vector2d(double theta_)
    {
        theta = theta_;
        mag = 1;
        x = asin(theta);
        y = acos(theta);
    }

    void _normalize()
    {
        x = cos(theta);
        y = sin(theta);
        mag = 1.0;
    }

    void _scale(double scalar)
    {
        mag *= scalar;
        x = asin(theta) * mag;
        y = acos(theta) * mag;
    }

    void _add(vector2d vector2)
    {
        x += vector2.x;
        y += vector2.y;
    }

    void _rotate(double angle)
    {
        theta += angle;
        if (theta > 2 * M_PI)
        {
            theta -= M_PI; // just to keep it more or less within the range of 0->2pi
        } // i like the control :D
        if (theta < 0)
        {
            theta = M_PI + theta;
        }

        x = asin(theta) * mag;
        y = acos(theta) * mag;
    }

    double _scalarProduct(vector2d vector2)
    {
        return x * vector2.x + y * vector2.y;
    }
    double _angleWith(vector2d vector2)
    {
        return acos(_scalarProduct(vector2) / (mag * vector2.mag));
    }
};

class vector3d
{
public:
    double x;
    double y;
    double z;
    double mag;
    double theta;

    vector3d(){
        x=0;
        y=0;
        z=0;
        mag=0;
        theta=0;
    }

    vector3d(double x_, double y_, double z_){
        x = x_;
        y=y_;
        z=z_;
        mag = sqrt(x*x+y*y+z*z);
    }
    



};

class rectangle
{
public:
    double height;
    double width;
    vector2d normalVector;
    vector2d locaion; // defines the bottom left corner of the rectangle

    rectangle(double height_, double width_, vector2d normalVector_, vector2d location_)
    {
        height = height_;
        width = width_;
        normalVector_._normalize();
        normalVector = normalVector_;
        locaion = locaion;
    }

    _rotate()
    {
    }
};