#include <iostream>
#include <cassert>


class Figure {
public:
    virtual bool equals(const Figure *other) const = 0;

    virtual ~Figure() = default;
};


class Rectangle : public Figure {
private:
    int width{};
    int height{};
public:

    Rectangle(int w, int h) : width(w), height(h) {}

    bool equals(const Figure *other) const override {
        const Rectangle *rect_other = dynamic_cast<const Rectangle*>(other);
        if (rect_other) {
            return width == rect_other->width && height == rect_other->height;
        }
        return false;
    } 
};


class Triangle : public Figure {
private:
    int a{};
    int b{};
    int c{};
public:

    Triangle(int a1, int b1, int c1) : a(a1), b(b1), c(c1) {}

    bool equals(const Figure *other) const override {
        const Triangle *tri_other = dynamic_cast<const Triangle*>(other);
        if (tri_other) {
            return a == tri_other->a && b == tri_other->b && c == tri_other->c;
        }
        return false;
    }
};
