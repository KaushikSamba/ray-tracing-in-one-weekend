#include <iostream>
#include <fmt/core.h>
#include "color.hpp"
#include "ray.hpp"

Color ray_color(Ray const& r)
{
    auto unit_dir = unit_vector(r.direction());
    auto t        = 0.5 * (unit_dir.y() + 1.0);

    return (1.0 - t) * Color {1.0, 1.0, 1.0}  // White
           + t* Color {0.5, 0.7, 1.0}         // Blue
    ;
}

int main()
{
    // Image
    const auto ASPECT_RATIO = 2.0 / 1.0;
    const int  NUM_COLS     = 400;
    const int  NUM_ROWS     = static_cast<int>(NUM_COLS / ASPECT_RATIO);

    // Camera
    const auto VIEWPORT_HEIGHT = 2.0;
    const auto VIEWPORT_WIDTH  = ASPECT_RATIO * VIEWPORT_HEIGHT;
    const auto FOCAL_LENGTH    = 1.0;

    const auto origin     = Point3 {0, 0, 0};                                   // Camera is placed at the origin
    const auto horizontal = Vec3 {VIEWPORT_WIDTH, 0, 0};                        // X-limits of the image
    const auto vertical   = Vec3 {0, VIEWPORT_HEIGHT, 0};                       // Y-limits of the image
    const auto lower_left_corner =
        origin - horizontal / 2.0 - vertical / 2.0 - Vec3(0, 0, FOCAL_LENGTH);  // Into the screen is the (-Z) direction

    // Render
    std::cout << fmt::format("P3\n{} {}\n255\n", NUM_COLS, NUM_ROWS);

    for(int j = NUM_ROWS - 1; j >= 0; j--)
    {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for(int i = 0; i < NUM_COLS; i++)
        {
            auto u = static_cast<double>(i) / (NUM_COLS - 1);
            auto v = static_cast<double>(j) / (NUM_ROWS - 1);
            Ray  r {origin, lower_left_corner + u * horizontal + v * vertical - origin};

            auto color = ray_color(r);
            write_color(std::cout, color);
        }
    }

    std::cerr << "\nDone";
    return 0;
}