#include <iostream>
#include <cmath>
#include <vector>
#include <functional>
#include "pso.hpp"

int main() 
{
    std::vector<double> targetPosition = {3.0, 5.0, -2.0};
    std::vector<std::function<double(const std::vector<double>&)>> equations = {
        [](const std::vector<double>& pos) { return std::sin(pos[1]) * 2 + std::cos(pos[2]) * 3; },
        [](const std::vector<double>& pos) { return std::cos(pos[0]) * 4 + std::sin(pos[2]) * 5; },
        [](const std::vector<double>& pos) { return std::sin(pos[0]) * 6 + std::cos(pos[1]) * 7; }
    };

    PSO pso(equations, targetPosition);

    std::cout << "PSO_app" << std::endl;
    return EXIT_SUCCESS;
}
