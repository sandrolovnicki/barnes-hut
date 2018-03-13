#ifndef BARNESHUT_H
#define BARNESHUT_H

#include <iostream>
#include <cstdio>
#include <QObject>
#include <QDebug>
#include <math.h>


class Point {
public:
    Point();
    Point(double xx, double yy);

    double x;
    double y;
};


class Data {
public:
    Data();
    Data(Point p, Point f, double m);

    Point coordinates;
    Point force;
    double mass;
};

class Rectangle {
public:
    Rectangle();
    Rectangle(Point c, double d);

    Point center;
    double diameter;
};

class quadTree {
public:
    quadTree(quadTree* p, Rectangle r);
    void insert(Data* d);
    void calculateCenterMass();
    void calculateForce(Data* d);

    Rectangle area;
    Data centerMass;

    quadTree* parent;
    //children
    quadTree* NE;
    quadTree* NW;
    quadTree* SE;
    quadTree* SW;
};

#endif // BARNESHUT_H
