#include <iostream>
#include <cstdint>
#include <vector>

void process(std::vector<int64_t> &v, int64_t bound) 
{
    v.reserve(2 * v.size());
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        if (*it >= bound) {
            v.push_back(*it);
        }
    }
}
