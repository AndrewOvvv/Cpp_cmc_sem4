#include <iostream>
#include <iomanip>
#include <cmath>


int main()
{
    int n = 0;
    double sum = 0, sq_sum = 0;
    double current;
    while (std::cin >> current) {
        ++n;
        sum += current;
        sq_sum += current * current;
    }
    sum /= n;
    sq_sum /= n;
    std::cout << std::fixed  << std::setprecision(10) << sum << " " << std::sqrt(sq_sum - sum * sum) << std::endl;
}
