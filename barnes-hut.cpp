#include "barnes-hut.h"


Point::Point() {
    x = 0.0;
    y = 0.0;
}

Point::Point(double xx, double yy) {
    x = xx;
    y = yy;
}

Data::Data() {
    coordinates = Point(0.0,0.0);
    force = Point(0.0,0.0);
    mass = 0.0;
}

Data::Data(Point p, Point f, double m) {
    coordinates = p;
    force = f;
    mass = m;
}

Rectangle::Rectangle() {
    center = Point(0.0,0.0);
    diameter = 0;
}

Rectangle::Rectangle(Point c, double d) {
    center = c;
    diameter = d;
}

quadTree::quadTree(quadTree* p, Rectangle r) {
    area = r;
    centerMass = Data(Point(0.0,0.0),Point(0.0,0.0),0.0);
    parent = p;
    NE = nullptr;
    NW = nullptr;
    SE = nullptr;
    SW = nullptr;
}

void quadTree::insert(Data* d) {
    if(d->mass == 0.01) return;
    if(centerMass.mass == 0.0 && NE == nullptr) {
        centerMass = *d;
        return;
    }
    //if just now "eaten"
    if(centerMass.mass != 0 && (d->coordinates.x == centerMass.coordinates.x && d->coordinates.y == centerMass.coordinates.y)) {
        centerMass.mass += d->mass;
        d->mass = 0.01;
        return;
    }
    //if leaf, create subtrees
    if(NE == nullptr) {
        NE = new quadTree(this,Rectangle(Point(area.center.x-area.diameter/2,area.center.y+area.diameter/2),area.diameter/2));
        NW = new quadTree(this,Rectangle(Point(area.center.x+area.diameter/2,area.center.y+area.diameter/2),area.diameter/2));
        SE = new quadTree(this,Rectangle(Point(area.center.x-area.diameter/2,area.center.y-area.diameter/2),area.diameter/2));
        SW = new quadTree(this,Rectangle(Point(area.center.x+area.diameter/2,area.center.y-area.diameter/2),area.diameter/2));
        //move old data
        if(centerMass.coordinates.x <= area.center.x && centerMass.coordinates.y >= area.center.y)
            NE->insert(new Data(Point(centerMass.coordinates.x,centerMass.coordinates.y),Point(centerMass.force.x,centerMass.force.y),centerMass.mass));
        else  if(centerMass.coordinates.x >= area.center.x && centerMass.coordinates.y >= area.center.y)
            NW->insert(new Data(Point(centerMass.coordinates.x,centerMass.coordinates.y),Point(centerMass.force.x,centerMass.force.y),centerMass.mass));
        else if(centerMass.coordinates.x <= area.center.x && centerMass.coordinates.y <= area.center.y)
            SE->insert(new Data(Point(centerMass.coordinates.x,centerMass.coordinates.y),Point(centerMass.force.x,centerMass.force.y),centerMass.mass));
        else if(centerMass.coordinates.x >= area.center.x && centerMass.coordinates.y <= area.center.y)
            SW->insert(new Data(Point(centerMass.coordinates.x,centerMass.coordinates.y),Point(centerMass.force.x,centerMass.force.y),centerMass.mass));
        centerMass.mass = 0.0;
    }

    //insert into children
    if(d->coordinates.x <= area.center.x && d->coordinates.y >= area.center.y)
        NE->insert(d);
    else if(d->coordinates.x >= area.center.x && d->coordinates.y >= area.center.y)
        NW->insert(d);
    else if(d->coordinates.x <= area.center.x && d->coordinates.y <= area.center.y)
        SE->insert(d);
    else if(d->coordinates.x >= area.center.x && d->coordinates.y <= area.center.y)
        SW->insert(d);
}

void quadTree::calculateCenterMass() {
    //if leaf, already has centerMass
    if(NE == nullptr)
        return;
    //calculate children first
    double x,y,m;
    NE->calculateCenterMass();
    NW->calculateCenterMass();
    SE->calculateCenterMass();
    SW->calculateCenterMass();
    //calculate
    m = NE->centerMass.mass + NW->centerMass.mass + SE->centerMass.mass + SW->centerMass.mass;
    x = NE->centerMass.coordinates.x*NE->centerMass.mass + NW->centerMass.coordinates.x*NW->centerMass.mass +
            SE->centerMass.coordinates.x*SE->centerMass.mass + SW->centerMass.coordinates.x*SW->centerMass.mass;
    y = NE->centerMass.coordinates.y*NE->centerMass.mass + NW->centerMass.coordinates.y*NW->centerMass.mass +
            SE->centerMass.coordinates.y*SE->centerMass.mass + SW->centerMass.coordinates.y*SW->centerMass.mass;
    centerMass.coordinates.x = x/m;
    centerMass.coordinates.y = y/m;
    centerMass.mass = m;
}

double P = 55555;

void quadTree::calculateForce(Data* d) {
    //nothing in node (empty leaf)
    if(centerMass.mass == 0.0) return;

    //if(d->mass == 0.01) return;

    double deltaX = centerMass.coordinates.x - d->coordinates.x;
    double deltaY = centerMass.coordinates.y - d->coordinates.y;
    double distance = sqrt(pow(deltaX,2) + pow(deltaY,2));

    //does not exert force on itself
    if(distance == 0) return;
    //if too close, "gets eaten"
    if(distance < 8) {
        d->coordinates.x = centerMass.coordinates.x;
        d->coordinates.y = centerMass.coordinates.y;
        return;
    }

    //for bodies, calculate directly
    if(NE == nullptr) {
        d->force.x += P * (deltaX / distance) * (d->mass * centerMass.mass / pow(distance,2));
        d->force.y += P * (deltaY / distance) * (d->mass * centerMass.mass / pow(distance,2));
        return;
    }
    //for sufficiently far centerMasses
    if(area.diameter / distance < 0.5) {
        d->force.x += P * (deltaX / distance) * (d->mass * centerMass.mass / pow(distance,2));
        d->force.y += P * (deltaY / distance) * (d->mass * centerMass.mass / pow(distance,2));
        return;
    }
    //all exist because first 'if' failed
    NE->calculateForce(d);
    NW->calculateForce(d);
    SE->calculateForce(d);
    SW->calculateForce(d);
}
