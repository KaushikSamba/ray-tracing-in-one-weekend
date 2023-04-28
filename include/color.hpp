#ifndef COLOR_HPP
#define COLOR_HPP

#include <ostream>
#include "vec3.hpp"

void write_color(std::ostream& stream, Color rgb)
{
    // Write the translated [0,255] value of each color component
    stream << static_cast<int>(255.999 * rgb.x()) << ' ' << static_cast<int>(255.999 * rgb.y()) << ' '
           << static_cast<int>(255.999 * rgb.z()) << '\n';
}

#endif  // COLOR_HPP