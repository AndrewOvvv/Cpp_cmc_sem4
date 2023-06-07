#include <iostream>
#include <string>

/*
 A -> a S d | a B d
 B -> b B c | b eps c
 */



void print(int len, int cnt_a) {
    if (len == 0) {
        return;
    }

    if (cnt_a > 0) {
        std::cout << 'a';
        --cnt_a;
        print(len - 2, cnt_a);
        std::cout << 'd';
    } else {
        std::cout << 'b';
        print(len - 2, cnt_a);
        std::cout << 'c';
    }
}


int main()
{
    int n; std::cin >> n;
    if (n % 2 == 1) {
        return 0;
    }
    for (int i = (n / 2) - 1; i > 0; --i) {
        print(n, i);
        std::cout << std::endl;
    }
    return 0;
}
