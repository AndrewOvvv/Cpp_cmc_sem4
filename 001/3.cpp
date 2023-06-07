#include <iostream>


class C {
    double v = {};

public:
    C operator ~() const {
        return *this;
    }

    C operator ++() const {
        return *this;
    }

    C operator +(const C &other) {
        return C(other.v + v);
    }

    operator int() {
        return int(v);
    }
    
    C(double arg) {
        v = arg;
    }

    C(int arg) {
        v = arg;
    }

    C(const C &arg1) {
        v = 0;
    }

    C(const C &arg1, const C &arg2) {
        v = 0;
    }

    C() {}
};



C func1(const C &v1, int v2)
{
    return C(v2 + v1, ~v1);
}

void func2(const C *p1, double p2)
{
    C v1 = p2;
    C v2[2][2];
    C v3 = func1(func1(func1(&p1[3], p2), ~p1[2]), ++v1 * v2[1]);
}    
  
