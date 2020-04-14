#include <cmath>
#include "Triangle.h"

const double pi = M_PI;


Triangle::Triangle()
{
    this->Triangle::initFromDialog();
    length_ = sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));;
    width_ = length_;
}

Triangle::~Triangle() = default;


double Triangle::getSquare()
{
    return (pow(length_, 2) * sqrt(3)) / 4;
}
double Triangle::getPerimetr()
{
    return length_ * 3;
}
double Triangle::getMass() const
{
    return mass;
}
CVector2D Triangle::getPosition() const
{
    CVector2D center;
    center.x = (A.x + B.x + C.x) / 3;
    center.y = (A.y + B.y + C.y) / 3;
    return center;
}


void Triangle::draw()
{
    cout << "Length: " << getLength() << endl;
    cout << "Square: " << getSquare() << endl;
    cout << "Perimetr: " << getPerimetr() << endl;
    cout << "Mass: " << getMass() << endl;
    cout << "Position(center): x = " << getPosition().x << ", y = " << getPosition().y << endl;
    cout << "Class name: " << className() << endl;
    cout << "Size: " << getSize() << endl;
}

void Triangle::initFromDialog()
{
    cout << "Add coords: ";
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    cout << endl;

    cout << "Add mass: ";
    cin >> mass;
    cout << endl;
}