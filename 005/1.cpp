#include <iostream>
#include <vector>


template<typename T>
auto process(const T &stl_cont) 
{
    typename T::value_type sum{};

    auto moving_it = stl_cont.rbegin();

    int cnt = 0;
    while (moving_it != stl_cont.rend()) {
        if (cnt > 4) {
            break;
        } else if (cnt % 2) {
            ++moving_it;
        } else {
            sum += *moving_it;
            ++moving_it;
        }
        ++cnt;
    }
    return sum;
}
