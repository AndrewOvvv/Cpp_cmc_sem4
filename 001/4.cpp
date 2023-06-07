#include <iostream>


void print_pressed(char c, int cnt)
{
    if (c == '#' || cnt > 4) {
        std::cout << '#' << c;
        std::cout << cnt;
        std::cout << '#';
    } else {
        for (int i = 0; i < cnt; ++i) {
            std::cout << c;
        }
    }
}


int main()
{
    char current, previous;
    int cnt = 0;


    std::cin >> std::noskipws;
    std::cout << std::hex;
    while (std::cin >> current) {
        if (cnt == 0) {
            previous = current;
            ++cnt;
        } else if (current == previous) {
            ++cnt;
        } else {
            if (cnt > 0) print_pressed(previous, cnt);
            previous = current;
            cnt = 1;
        }
    }
    if (cnt > 0) print_pressed(previous, cnt);
    return 0;
}
