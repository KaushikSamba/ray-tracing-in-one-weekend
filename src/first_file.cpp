#include <iostream>
#include <fmt/core.h>

int main()
{
    const int NUM_COLS = 200;
    const int NUM_ROWS = 100;
    const float SCALING_VALUE = 254.99;

    std::cout << fmt::format ("P3\n{} {}\n255\n", NUM_COLS, NUM_ROWS) ;

    for(int j = NUM_ROWS-1; j >=0; j--)
    {
        for(int i = 0; i < NUM_COLS; i++)
        {
            float r = static_cast<float>(i)/NUM_COLS;
            float g = static_cast<float>(j)/NUM_ROWS;
            float b = 0.2;

            int ir = static_cast<int>(SCALING_VALUE * r);
            int ig = static_cast<int>(SCALING_VALUE * g);
            int ib = static_cast<int>(SCALING_VALUE * b);

            std::cout << fmt::format("{} {} {} ", ir, ig, ib);
        }
        std::cout << std::endl;
    }

    return 0;
}