#include <iostream>

class A {
private:
    int n = {};
    bool deletion = true;

public:
    A() 
    {
        std::cin >> n;
    }

    A(A& arg)
    {
        std::cin >> n;
        n += arg.n;
        arg.deletion = false;
    }

    ~A()
    {
        if (deletion)
        {
            std::cout << n << std::endl;
        }
    }

};

