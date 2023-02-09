#include "Polygon.h"
#include "Point.h"

using namespace std;

Polygon::Polygon(){
    //numOfCoords = 2;
    numOfPoints = 0;
    points = NULL;
    size = 0;  
}

void Polygon::add(const Point& p){
    if(size == 0){
        size = 2;
        points = new Point[2];
    }
    if(numOfPoints >= size){
        int newSize = size+2;
        Point* newPoints = new Point[newSize];
        //memcpy(newPoints, points, newSize);
        for(int counter = 0; counter < numOfPoints; counter++){
            newPoints[counter] = points[counter]; 
        }
        delete[] points;
        points = newPoints;
        size = newSize;
    }
    points[numOfPoints] = p;
    numOfPoints++;
}

ostream& operator << (ostream&o, const Polygon& p){
    for(int counter = 0; counter < p.numOfPoints; counter++){
        o << p.points[counter] << endl;
    }

    return o;
}

Polygon::~Polygon(){
    delete[] points;
}

Polygon Polygon::operator+(const Point& p){
    cout << "operator +" << endl;
    Polygon result;
    result = *this;
    for(int counter = 0; counter < numOfPoints; counter++){
        result.points[counter].x = points[counter].x + p.x;
        result.points[counter].y = points[counter].y + p.y;
    }

    return result;
}
Polygon& Polygon::operator=(const Polygon& sourceP){
    cout << "Assignment operator here is used" << endl;
    size = sourceP.size;
    numOfPoints = sourceP.numOfPoints;
    points = new Point[size];
    for(int counter = 0; counter < numOfPoints; counter++){
        points[counter] = sourceP.points[counter];
    }

    return *this;
}

Point& Polygon::operator[](int index){
    return points[index];
}