#include <iostream>
#include <fmt/core.h>
#include "color.hpp"

int main()
{
    const int NUM_COLS = 256;
    const int NUM_ROWS = 256;

    std::cout << fmt::format("P3\n{} {}\n255\n", NUM_COLS, NUM_ROWS);

    for(int j = NUM_ROWS - 1; j >= 0; j--)
    {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for(int i = 0; i < NUM_COLS; i++)
        {
            float r = static_cast<float>(i) / (NUM_COLS - 1);
            float g = static_cast<float>(j) / (NUM_ROWS - 1);
            float b = 0.25;

            Color color {r, g, b};
            write_color(std::cout, color);
        }
    }

    std::cerr << "\nDone";
    return 0;
}