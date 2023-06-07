#include <iostream>
#include <numbers>
#include <string>
#include <sstream>


class Rectangle : Figure {
private:
    double x, y; 
public:
    Rectangle(double _x, double _y) : x(_x), y(_y) {}

    double get_square() const override {
        return x * y;
    }

    static Rectangle* make(std::string arg) {
        double _x, _y;
        std::stringstream loc_stream(arg);
        loc_stream >> _x >> _y;
        Rectangle *new_rect = new Rectangle(_x, _y);
        return new_rect;
    }
};


class Square : Figure {
private:
    double x;
public:
    Square(double _x) : x(_x) {}

    double get_square() const override {
        return x * x;
    }

    static Square* make(std::string arg) {
        double _x;
        std::stringstream loc_stream(arg);
        loc_stream >> _x;
        Square *new_sqr = new Square(_x);
        return new_sqr;
    }
};


class Circle : Figure {
private:
    double r;
public:
    Circle(double _r) : r(_r) {}

    double get_square() const override {
        return std::numbers::pi * r * r; 
    }

    static Circle* make(std::string arg) {
        double _r;
        std::stringstream loc_stream(arg);
        loc_stream >> _r;
        Circle *new_cir = new Circle(_r);
        return new_cir;

    }
};

