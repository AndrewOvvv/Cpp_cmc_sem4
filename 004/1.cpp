#include <iostream>
#include <vector>
#include <bit>
#include <algorithm>


bool cmp(const int arg1, const int arg2) {
    return __builtin_popcount(arg1) < __builtin_popcount(arg2);
}


int main()
{
    std::vector<unsigned int> numbers;

    unsigned int current;
    while (std::cin >> current) {
        numbers.push_back(current);
    }

    stable_sort(numbers.begin(), numbers.end(), cmp);

    for (auto &v : numbers) {
        std::cout << v << std::endl;
    }
    return 0;
}
