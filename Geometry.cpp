#include "Geometry.hpp"


namespace solution {
    Line::Line(int x_begin, int y_begin, int width, int height, bool is_hor) : start_x(x_begin), start_y(y_begin),
                                                                               width(width), height(height),
                                                                               is_horizontal(is_hor) {}


    Line& Line::operator=(const Line &other) {
        start_x = other.start_x;
        start_y = other.start_y;
        width = other.width;
        height = other.height;
        is_horizontal = other.is_horizontal;
        return *this;
    }

    Point::Point(int x, int y) : x(x), y(y) {}

    Point &Point::operator=(const Point &other) {
        x = other.x;
        y = other.y;
        return *this;
    }

    Rectangle::Rectangle(const Point &A, const Point &B) : A(A), B(B) {}

    Rectangle & Rectangle::operator=(const Rectangle &other) {
        A = other.A;
        B = other.B;
        return *this;
    }
}
