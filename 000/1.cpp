#include <iostream>

class Sum {
private:
    int sum = {};

public:
    Sum(int a = 0, int b = 0) 
    {
        Sum::sum = a + b;    
    }

    Sum(Sum s, int a) 
    {
        Sum::sum = s.get() + a;
    }

    int get() const 
    {
        return Sum::sum;
    }
};


