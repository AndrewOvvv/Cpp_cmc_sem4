#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"


int main(int argc, char *argv[])
{
    constexpr double PI = 3.14159265358979323846;

    numbers::complex center(argv[1]);
    double R = std::stod(argv[2]);
    int N = std::stoi(argv[3]);
    std::vector<std::string> function;
    for (int i = 4; i < argc; ++i) {
        function.push_back(argv[i]);
    }


    double dz = (2 * R) * (PI / double(N));
    double rotation_angle = (2 * PI) / double(N);
    double current_angle = 0;
    numbers::complex int_result = 0;


    for (int i = 0; i < N; ++i) {
        numbers::complex moving_complex(std::cos(current_angle), std::sin(current_angle));
        numbers::complex multiplier(-std::sin(current_angle), std::cos(current_angle));
        int_result += numbers::eval(function, center + R * moving_complex) * multiplier * dz;
        current_angle += rotation_angle;
    }
    std::cout << int_result.to_string() << std::endl;
    return 0;
}
