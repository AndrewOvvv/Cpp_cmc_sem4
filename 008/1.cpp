#include <iostream>
#include <string>
#include <vector>


void solve(std::vector<char> &s)
{
    int cnt_zeroes = 0, cnt_ones = 0;

    if (int(s.size()) == 0) {
        std::cout << 0 << std::endl;
        return;
    }

    for (int i = 0; i < int(s.size()); ++i) {
        if (s[i] != '0' && s[i] != '1') {
            std::cout << 0 << std::endl;
            return;
        }
    }
    
    int i = 0;
    while (i < int(s.size()) && s[i] == '0') {
        ++cnt_zeroes;
        ++i;
    }
    while (i < int(s.size()) && s[i] == '1') {
        ++cnt_ones;
        ++i;
    }

    if (cnt_ones == 0 || cnt_zeroes == 0) {
        std::cout << 0 << std::endl;
        return;
    }

    for (i = 0; i < int(s.size());) {
        for (int j = 0; j < cnt_zeroes; ++j) {
            if (i >= int(s.size()) || s[i] != '0') {
                std::cout << 0 << std::endl;
                return;
            }
            ++i;
        }
        for (int j = 0; j < cnt_ones; ++j) {
            if (i >= int(s.size()) && s[i] != '1') {
                std::cout << 0 << std::endl;
                return;
            }
            ++i;
        }
    }
    std::cout << 1 << std::endl;
}


bool cin(std::vector<char> &s)
{
    s.clear();
    char c;
    while (std::cin >> c && !std::isspace(c)) {
        s.push_back(c);
    }
    return int(s.size()) > 0;
}


int main()
{
    std::vector<char> s;
    while (cin(s)) {
        solve(s);
    }
    return 0;
}
