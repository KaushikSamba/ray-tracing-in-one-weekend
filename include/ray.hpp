#ifndef RAY_HPP
#define RAY_HPP

#include "vec3.hpp"

class Ray
{
public:
    Ray() {}
    Ray(Point3 const& origin, Point3 const& direction)
        : orig {origin}
        , dir {direction}
    {}

    Point3 origin() const
    {
        return orig;
    }
    Point3 direction() const
    {
        return dir;
    }

    Point3 at(double t) const
    {
        return orig + t * dir;
    }

private:
    Point3 orig;
    Point3 dir;
};

#endif  // RAY_HPP