#include <iostream>
#include <string>
#include <exception>
#include <stdint.h>


class Result {
public:
    int64_t value{};
};


void func(int64_t a, int64_t b, int64_t k) 
{
    if (k == 0) {
        Result res;
        res.value = a + b;
        throw res;
    } else if (k > 0 && b == 1) {
        Result res;
        res.value = a;
        throw res;
    } else if (k > 0 && b > 1) {
        Result res;
        res.value = 0;
        try {
            func(a, b - 1, k);
        }
        catch (Result &prev) {
            res = std::move(prev);
        }
        func(a, res.value, k - 1);
    }
}


int main()
{
    int64_t a, b, k;
    while (std::cin >> a >> b >> k) {
        try {
            func(a, b, k);
        }
        catch (Result &res) {
            std::cout << res.value << std::endl;
        }
    }
    return 0;
}
