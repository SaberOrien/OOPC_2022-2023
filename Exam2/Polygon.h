#pragma once
#include "Point.h"
#include <iostream>
#include <cstring>

class Polygon{
public:
    friend class Point;
    Polygon();
    ~Polygon();
    Polygon& operator=(const Polygon& sourceP);
    Polygon operator+(const Point& p);
    Point& operator[](int index);
    void add(const Point& p);
    void fillArray();
    friend std::ostream& operator << (std::ostream& o, const Polygon& p);
private:
    Point* points;
    //int numOfCoords;
    int numOfPoints;
    int size;
};