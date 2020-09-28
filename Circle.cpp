#include "Circle.h"


Point::Point() : x{0}, y{0} {}

Point::Point(double x, double y) : x{x}, y{y} {}

Point::Point(const Point& p) : x {p.x}, y {p.y} { }

bool Point::operator==(Point& p) {
    return (p.x == x && p.y == y);
}


Circle::Circle() : p{}, radius{0} {}
Circle::Circle(double x, double y, double r) : p{x, y}, radius{r} {}
Circle::Circle(Point p, double r) : p{p}, radius{r} {}

bool Circle::operator==(Circle& other) {
    return (radius == other.radius && p == other.p);
}

std::ostream& operator<<(std::ostream& os, Circle c) {
    os << c.p.x << ' ' << c.p.y << ' ' << c.radius << ' ';
    return os;
}
std::istream& operator>>(std::istream& is, Circle c) {
    is >> c.p.x >> c.p.y >> c.radius;
    return is;
}
