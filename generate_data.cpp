#include <math.h>
#include <fstream>

int main()
{
    auto radius = 10.0;
    auto center_x = 20.0;
    auto center_y = 30.0;
    std::ofstream fout("circle.dat");
    for (auto i = 0; i < 36; i++)
    {
        auto x = radius * cos(3.14 * i * 10. / 180) + center_x;
        auto y = radius * sin(3.14 * i * 10. / 180) + center_y;

        fout << x << " " << y << std::endl;
    }
    fout.close();

    return 0;
}
