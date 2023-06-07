#include <iostream>
#include <string>


void solve(std::string &s)
{
    if (int(s.size()) < 2 || int(s.size()) % 2 == 1) {
        std::cout << 0 << std::endl;
        return;
    }

    int cnt_a = 0, i = 0, j = 0;
    while (i < int(s.size()) && s[i] == 'a') {
        ++cnt_a;
        ++i;
    }
    
    bool only_a_x = true;
    for (int i = 0; i < int(s.size()); ++i) {
        if (i < int(s.size()) / 2 && s[i] != 'a') {
            only_a_x = false;
        } else if (i >= int(s.size()) / 2 && s[i] != 'X') {
            only_a_x = false;
        }
    }

    if (only_a_x) {
        std::cout << 1 << std::endl;
        return;
    }

    int cnt_U = 0;
    for (int i = 0; i < int(s.size()); ++i) {
        if (s[i] == 'U') {
            ++cnt_U;
        }
    } 
    
    for (i = 0; i < cnt_a; ++i) {
        if (s[i] != 'a') {
            std::cout << 0 << std::endl;
            return;
        }
    }
    if (i >= int(s.size()) || s[i] != '0') {
        std::cout << 0 << std::endl;
        return;
    }
    ++i;
    for (j = i; j < i + cnt_a; ++j) {
        if (j >= int(s.size()) || s[j] != 'b') {
            std::cout << 0 <<std::endl;
            return;
        }
    }
    i = j;
    if (i >= int(s.size()) || s[i] != '1') {
        std::cout << 0 << std::endl;
        return;
    }
    ++i;
    for (j = i; j < i + cnt_U; ++j) {
        if (j >= int(s.size()) || s[j] != 'U') {
            std::cout << 0 << std::endl;
            return;
        }
    }
    i = j;
    for (j = i; j < i + cnt_U; ++j) {
        if (j >= int(s.size()) || s[j] != 'V') {
            std::cout << 0 << std::endl;
            return;
        }
    }
    
    std::cout << 1 << std::endl;
}


int main()
{
    std::string s;
    while (std::cin >> s) {
        solve(s);
    }
    return 0;
}
