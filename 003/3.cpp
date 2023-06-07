#include <iostream>
#include <vector>
#include <algorithm>

void process(const std::vector<int> &v, std::vector<int> &v2)
{
    int cnt = 0;
    std::vector<int> v1 = v;
    std::sort(v1.begin(), v1.end());
    v1.erase(std::unique(v1.begin(), v1.end()), v1.end());

    for (auto it : v1) {
        if (-1 < it - cnt && it - cnt < (int)v2.size()) {
            v2.erase(v2.begin() + it - cnt);
            ++cnt;
        }
    }
}
