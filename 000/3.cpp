#include <cstdlib>
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    bool was_non_zero_num = 0;
    int cnt_zeroes = 0;
    char c;
    std::cin >> std::noskipws;
    while (std::cin >> c) {
        if (c == '0' && !was_non_zero_num) {
            cnt_zeroes++;
        } else if ('0' <= c && c <= '9') {
            was_non_zero_num = 1;
            cnt_zeroes = 0;
            std::cout << c;
        } else {
            if (cnt_zeroes != 0) {
                std::cout << '0';
            }
            cnt_zeroes = 0;
            was_non_zero_num = 0;
            std::cout << c;
        }
    }
    if (cnt_zeroes != 0) {
        std::cout << '0';
    }
    cnt_zeroes = 0;
    return 0;
}
