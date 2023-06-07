#include <iostream>
#include <chrono>
#include <complex>
#include <vector>


namespace Equations
{

template<typename T>
std::pair<bool, std::vector<std::complex<T>>> quadratic(std::array<std::complex<T>, 3> coeffs)
{
    constexpr T eps = 32 * std::numeric_limits<T>::epsilon();
    if (std::norm(coeffs[2]) <= eps) {
        if (std::norm(coeffs[1]) <= eps) {
            if (std::norm(coeffs[0]) <= eps) {
                // f(x) = 0 => inf solutions
                return {false, {}};
            } else {
                // f(x) = C => 0 solutions
                return {true, {}};
            }
        } else {
            // f(x) = bx + c => solve linear => 1 solution
            auto solution = -coeffs[0] / coeffs[1];
            return {true, {solution}};
        }
    } else {
        // f(x) = ax^2 + bx + c => solve quadratic => 2 solutions
        auto discriminant = std::sqrt(coeffs[1] * coeffs[1] - std::complex<T>(4) * coeffs[2] * coeffs[0]);
        auto solution_f = (-coeffs[1] + discriminant) / (std::complex<T>(2) * coeffs[2]);
        auto solution_s = (-coeffs[1] - discriminant) / (std::complex<T>(2) * coeffs[2]);
        return {true, {solution_f, solution_s}};
    }
} // function quadrantic

} // namespace Equations
