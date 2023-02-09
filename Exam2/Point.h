#pragma once
#include <iostream>

class Point{
    public:
        double x;
        double y;
        Point(){};
        Point(double set_x, double set_y);
        Point& operator=(const Point& p);
        friend std::ostream& operator << (std::ostream& o, const Point& p);
};