#include <cstdlib>
#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::vector<double>> ReadData();
void PrintVector(std::vector<std::vector<double>> v);
void CircleHoughVote(double x, double y);

const int N_CenterX = 200;
double Min_CenterX = 0.;
double Max_CenterX = 100.;
double Step_X = (Max_CenterX - Min_CenterX) / double(N_CenterX);
const int N_CenterY = 200;
double Min_CenterY = 0.;
double Max_CenterY = 100.;
double Step_Y = (Max_CenterY - Min_CenterY) / double(N_CenterY);

int main()
{
    auto v = ReadData();
    PrintVector(v);
    for (auto itr = v.begin(); itr != v.end(); ++itr)
    {
        auto row = *itr;
        auto x = row[0];
        auto y = row[1];
        CircleHoughVote(x, y);
    }

    return 0;
}

void CircleHoughVote(double x, double y)
{

    for (int i_x = 0; i_x < N_CenterX; i_x++)
    {
        for (int i_y = 0; i_y < N_CenterY; i_y++)
        {
            double x_temp = double(i_x) * Step_X + Min_CenterX;
            double y_temp = double(i_y) * Step_Y + Min_CenterY;
            double radius_temp = sqrt((x - x_temp) * (x - x_temp) + (y - y_temp) * (y - y_temp));

            std::ofstream fout("hough.dat", std::ios_base::app);
            fout << x_temp << " " << y_temp << " " << radius_temp << std::endl;
        }
    }
}

std::vector<std::vector<double>> ReadData()
{
    std::vector<std::vector<double>> v{};
    std::ifstream fin("circle.dat");
    double x, y;
    while (fin >> x >> y)
    {
        std::vector<double> row({x, y});
        v.push_back(row);
    }
    return v;
}

void PrintVector(std::vector<std::vector<double>> v)
{
    for (auto itr = v.begin(); itr != v.end(); ++itr)
    {
        auto vv = *itr;
        std::cout << vv[0] << " " << vv[1] << std::endl;
    }
}
