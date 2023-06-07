#include <iostream>
#include <iomanip>
#include <vector>


class Point {
public:
    int x, y;

    Point(int x = 0, int y = 0) 
    {
        Point::x = x;
        Point::y = y;
    }

    Point(Point arg1, Point arg2)
    {
        Point::x = arg2.x - arg1.x;
        Point::y = arg2.y - arg1.y;
    }

    int cross_prod(Point arg) 
    {
        return Point::x * arg.y - Point::y * arg.x;
    }
};


class Line {
public:
    double a, b, c;

    Line(Point arg1, Point arg2) {
        Line::a = arg2.y - arg1.y;
        Line::b = -(arg2.x - arg1.x);
        Line::c = -a * arg1.x - b * arg1.y;
    }
};


double det(double arg1, double arg2, double arg3, double arg4)
{
    return arg1 * arg4 - arg2 * arg3;
}


std::pair<double, double> intersect(Line &f, Line &s)
{
    double x = -det(f.c, f.b, s.c, s.b) / det(f.a, f.b, s.a, s.b);
    double y = -det(f.a, f.c, s.a, s.c) / det(f.a, f.b, s.a, s.b);
    return {x, y};
}


int main()
{   
    std::vector<Point> all(4);
    for (int i = 0; i < 4; ++i) {
        std::cin >> all[i].x >> all[i].y;
    }    
    Point AB(all[0], all[1]);
    Point CD(all[2], all[3]);

    Point AC(all[0], all[2]);

    if (AB.cross_prod(CD) == 0) {
        if (AC.cross_prod(AB) != 0) {
            std::cout << 0 << std::endl;
        } else {
            std::cout << 2 << std::endl;
        }
    } else {
        std::cout << 1 << " ";
        Line f(all[0], all[1]), s(all[2], all[3]);
        auto interP = intersect(f, s);
        std::cout << std::fixed << std::setprecision(5) << interP.first << " " << interP.second << std::endl;
    }
    return 0;
}
