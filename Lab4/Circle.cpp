#include <cmath>
#include "Circle.h"

const double pi = M_PI;


Circle::Circle()
{
    length_ = 2 * radius;
    width_ = 2 * radius;
    this->Circle::initFromDialog();
}

Circle::~Circle() = default;


double Circle::getSquare()
{
    return pi * radius * radius;
}
double Circle::getPerimetr()
{
    return 2 * pi * radius;
}
double Circle::getMass() const
{
    return mass;
}
CVector2D Circle::getPosition() const
{
    return center;
}


void Circle::draw()
{
    cout << "Length: " << getLength() << endl;
    cout << "Square: " << getSquare() << endl;
    cout << "Perimetr: " << getPerimetr() << endl;
    cout << "Mass: " << getMass() << endl;
    cout << "Position(center): x = " << getPosition().x << ", y = " << getPosition().y << endl;
    cout << "Class name: " << className() << endl;
    cout << "Size: " << getSize() << endl;
}

void Circle::initFromDialog()
{
    cout << "Add center coords: ";
    cin >> center.x >> center.y;
    cout << endl;

    cout << "Add radius: ";
    cin >> radius;
    cout << endl;

    cout << "Add mass: ";
    cin >> mass;
    cout << endl;
}