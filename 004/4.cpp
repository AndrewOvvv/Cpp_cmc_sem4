#include <iostream>
#include <map>


int main()
{
    constexpr long long MOD = 4294967161;
    std::map<std::pair<long long, long long>, long long> matrix1, matrix2;
    
    long long row, column, value;

    while (std::cin >> row >> column >> value) {
        if (value == MOD && row == 0 && column == 0) {
            break;
        }
        if (matrix1.find({row, column}) == matrix1.end()) {
            matrix1[{row, column}] = 0;
        }
        matrix1[{row, column}] += value;
        matrix1[{row, column}] %= MOD;
    }



    for (auto &[position, value] : matrix) {
        if (value != 0) {
            std::cout << position.first << " " << position.second << " " << value << std::endl;
        }
    }
    return 0;
}
