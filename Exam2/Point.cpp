#include "Point.h"

using namespace std;

Point::Point(double set_x, double set_y){
    x = set_x;
    y = set_y;
}

ostream& operator << (ostream& o, const Point& p){
    o << "(" << p.x << ", " << p.y << ")";
    return o;
}

Point& Point::operator=(const Point& p){
    x = p.x;
    y = p.y;
    return *this;
}