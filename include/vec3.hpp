#ifndef VEC3_HPP
#define VEC3_HPP

#include <cmath>
#include <ostream>

class Vec3
{
public:
    Vec3()
        : elems {0, 0, 0}
    {}
    Vec3(double e0, double e1, double e2)
        : elems {e0, e1, e2}
    {}


    double x() const
    {
        return elems[0];
    }
    double y() const
    {
        return elems[1];
    }
    double z() const
    {
        return elems[2];
    }

    Vec3 operator-() const
    {
        return Vec3 {-elems[0], -elems[1], -elems[2]};
    }
    double operator[](std::size_t i) const
    {
        return elems[i];
    }
    double& operator[](int i)
    {
        return elems[i];
    }

    Vec3& operator+=(Vec3 const& other)
    {
        elems[0] += other.x();
        elems[1] += other.y();
        elems[2] += other.z();

        return *this;
    }

    Vec3& operator*=(double t)
    {
        elems[0] *= t;
        elems[1] *= t;
        elems[2] *= t;

        return *this;
    }

    Vec3& operator/=(double t)
    {
        return *this *= (1.0 / t);
    }

    double length() const
    {
        return std::sqrt(length_squared());
    }
    double length_squared() const
    {
        return std::pow(elems[0], 2) + std::pow(elems[1], 2) + std::pow(elems[2], 2);
    }

private:
    double elems[3];
};

// Type aliases
using Point3 = Vec3;  // 3D point
using Color  = Vec3;  // RGB color

// Utility functions
std::ostream& operator<<(std::ostream& stream, Vec3 const& v)
{
    return stream << v.x() << ' ' << v.y() << ' ' << v.z();
}

Vec3 operator+(Vec3 const& u, Vec3 const& v)
{
    return Vec3 {u.x() + v.x(), u.y() + v.y(), u.z() + v.z()};
}
Vec3 operator-(Vec3 const& u, Vec3 const& v)
{
    return Vec3(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
}
Vec3 operator*(Vec3 const& u, Vec3 const& v)
{
    return Vec3(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
}
Vec3 operator*(double t, Vec3 const& v)
{
    return Vec3(t * v.x(), t * v.y(), t * v.z());
}
Vec3 operator*(Vec3 const& v, double t)
{
    return t * v;
}
Vec3 operator/(Vec3 const& v, double t)
{
    return (1.0 / t) * v;
}
double dot(Vec3 const& u, Vec3 const& v)
{
    return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
}
Vec3 cross(Vec3 const& u, Vec3 const& v)
{
    return Vec3(u.y() * v.z() - u.z() * v.y(), -1 * (u.x() * v.z() - u.z() * v.x()), u.x() * v.y() - u.y() * v.x());
}
Vec3 unit_vector(Vec3 const& v)
{
    return v / v.length();
}

#endif  // VEC3_HPP