#include <iostream>
#include <map>


int main()
{
    constexpr long long MOD = 4294967161;
    std::map<std::pair<unsigned long long, unsigned long long>, unsigned long long> matrix1, matrix2, result;
    
    unsigned long long row, column, value;

    while (std::cin >> row >> column >> value) {
        if (value == MOD && row == 0 && column == 0) {
            break;
        }
        matrix1[{row, column}] += value;
        matrix1[{row, column}] %= MOD;
    }

    while (std::cin >> row >> column >> value) {
        matrix2[{row, column}] += value;
        matrix2[{row, column}] %= MOD;
    }


    for (auto &[position, value] : matrix1) {
        unsigned long long row_m2 = position.second;
        for (auto it = matrix2.lower_bound({row_m2, 0}); it != matrix2.end() && (*it).first.first == row_m2; ++it) {
            result[{position.first, (*it).first.second}] += (value * (*it).second) % MOD;
            result[{position.first, (*it).first.second}] %= MOD;
        }
    }

    for (auto &[position, value] : result) {
        if (value != 0) {
            std::cout << position.first << " " << position.second << " " << value << std::endl;
        }
    }
    return 0;
}
