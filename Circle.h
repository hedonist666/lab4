#pragma once
#include <iostream>

struct Point {
    double x, y;
    Point();
    Point(double, double);
    Point(const Point&);
    bool operator==(Point&);
};

struct Circle {
    Point p;
    double radius;
    Circle();
    Circle(double, double, double);
    Circle(Point, double);
    bool operator==(Circle&);
    friend std::ostream& operator<<(std::ostream&, Circle);
    friend std::istream& operator>>(std::istream&, Circle);
};

std::ostream& operator<<(std::ostream&, Circle);
std::istream& operator>>(std::istream&, Circle);
