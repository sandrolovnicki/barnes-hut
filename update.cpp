#include "update.h"

UpdateBH::UpdateBH(QObject* parent) : QObject(parent) {
    p0 = new Data(Point(150,100),Point(0,0),40);
    p3 = new Data(Point(550,150),Point(0,0),20);
    p4 = new Data(Point(450,250),Point(0,0),15);
    p1 = new Data(Point(100,400),Point(0,0),10);
    p2 = new Data(Point(250,550),Point(0,0),15);
    p5 = new Data(Point(950,250),Point(0,0),15);
    p6 = new Data(Point(1000,500),Point(0,0),60);
    p7 = new Data(Point(850,450),Point(0,0),10);
    BH = new quadTree(nullptr,Rectangle(Point(0.0,0.0),1024));
    countB = new int;
    countC = new int;
}

void UpdateBH::clearTree() {
    BH->NE = nullptr;
    BH->NW = nullptr;
    BH->SE = nullptr;
    BH->SW = nullptr;
    BH->centerMass.coordinates.x = 0;
    BH->centerMass.coordinates.y = 0;
    BH->centerMass.mass = 0;

    p0->force.x = 0;
    p0->force.y = 0;
    p1->force.x = 0;
    p1->force.y = 0;
    p2->force.x = 0;
    p2->force.y = 0;
    p3->force.x = 0;
    p3->force.y = 0;
    p4->force.x = 0;
    p4->force.y = 0;
    p5->force.x = 0;
    p5->force.y = 0;
    p6->force.x = 0;
    p6->force.y = 0;
    p7->force.x = 0;
    p7->force.y = 0;
}

double t = 0.1;

void UpdateBH::nextStep() {
    clearTree();

    BH->insert(p0);
    BH->insert(p1);
    BH->insert(p2);
    BH->insert(p3);
    BH->insert(p4);
    BH->insert(p5);
    BH->insert(p6);
    BH->insert(p7);

    BH->calculateCenterMass();

    //qDebug() << "--------------";
    (*countB) = 0;
    (*countC) = 0;

    BH->calculateForce(p0);
    BH->calculateForce(p1);
    BH->calculateForce(p2);
    BH->calculateForce(p3);
    BH->calculateForce(p4);
    BH->calculateForce(p5);
    BH->calculateForce(p6);
    BH->calculateForce(p7);

    //qDebug() << (*countB) << (*countC);

   // qDebug() << forceSteps;

    p0->coordinates.x += pow(t,2) * p0->force.x / p0->mass;
    p0->coordinates.y += pow(t,2) * p0->force.y / p0->mass;
    p1->coordinates.x += pow(t,2) * p1->force.x / p1->mass;
    p1->coordinates.y += pow(t,2) * p1->force.y / p1->mass;
    p2->coordinates.x += pow(t,2) * p2->force.x / p2->mass;
    p2->coordinates.y += pow(t,2) * p2->force.y / p2->mass;
    p3->coordinates.x += pow(t,2) * p3->force.x / p3->mass;
    p3->coordinates.y += pow(t,2) * p3->force.y / p3->mass;
    p4->coordinates.x += pow(t,2) * p4->force.x / p4->mass;
    p4->coordinates.y += pow(t,2) * p4->force.y / p4->mass;
    p5->coordinates.x += pow(t,2) * p5->force.x / p5->mass;
    p5->coordinates.y += pow(t,2) * p5->force.y / p5->mass;
    p6->coordinates.x += pow(t,2) * p6->force.x / p6->mass;
    p6->coordinates.y += pow(t,2) * p6->force.y / p6->mass;
    p7->coordinates.x += pow(t,2) * p7->force.x / p7->mass;
    p7->coordinates.y += pow(t,2) * p7->force.y / p7->mass;
}

double UpdateBH::get0x() {
    return round(p0->coordinates.x * 100) / 100;
}
double UpdateBH::get0y() {
    return round(p0->coordinates.y * 100) / 100;
}
double UpdateBH::get1x() {
    return round(p1->coordinates.x * 100) / 100;
}
double UpdateBH::get1y() {
    return round(p1->coordinates.y * 100) / 100;
}
double UpdateBH::get2x() {
    return round(p2->coordinates.x * 100) / 100;
}
double UpdateBH::get2y() {
    return round(p2->coordinates.y * 100) / 100;
}
double UpdateBH::get3x() {
    return round(p3->coordinates.x * 100) / 100;
}
double UpdateBH::get3y() {
    return round(p3->coordinates.y * 100) / 100;
}
double UpdateBH::get4x() {
    return round(p4->coordinates.x * 100) / 100;
}
double UpdateBH::get4y() {
    return round(p4->coordinates.y * 100) / 100;
}
double UpdateBH::get5x() {
    return round(p5->coordinates.x * 100) / 100;
}
double UpdateBH::get5y() {
    return round(p5->coordinates.y * 100) / 100;
}
double UpdateBH::get6x() {
    return round(p6->coordinates.x * 100) / 100;
}
double UpdateBH::get6y() {
    return round(p6->coordinates.y * 100) / 100;
}
double UpdateBH::get7x() {
    return round(p7->coordinates.x * 100) / 100;
}
double UpdateBH::get7y() {
    return round(p7->coordinates.y * 100) / 100;
}

double UpdateBH::get0m() {
    return p0->mass;
}
double UpdateBH::get1m() {
    return p1->mass;
}
double UpdateBH::get2m() {
    return p2->mass;
}
double UpdateBH::get3m() {
    return p3->mass;
}
double UpdateBH::get4m() {
    return p4->mass;
}
double UpdateBH::get5m() {
    return p5->mass;
}
double UpdateBH::get6m() {
    return p6->mass;
}
double UpdateBH::get7m() {
    return p7->mass;
}

double UpdateBH::getcx() {
    return BH->centerMass.coordinates.x;
}
double UpdateBH::getcy() {
    return BH->centerMass.coordinates.y;
}
