#include "BaseFigure.h"


CVector2D::CVector2D()
{
    double x = 0;
    double y = 0;
}


BaseFigure::BaseFigure() {}
BaseFigure::BaseFigure(int length, int width, int mass, CVector2D vector2D)
        : length_(length)
        , width_(width)
        , mass_(mass)
        , position_(vector2D) {}

double BaseFigure::getLength()
{
    return length_;
}
double BaseFigure::getWidth()
{
    return width_;
}
double BaseFigure::getSquare()
{
    return length_ * width_;
}
double BaseFigure::getPerimetr()
{
    return 2 * (length_ + width_);
}
double BaseFigure::getMass() const
{
    return mass_;
}
CVector2D BaseFigure::getPosition() const
{
    return position_;
}

void BaseFigure::initFromDialog() {}

bool BaseFigure::operator==(const IPhysObject &object) const
{
    return getMass() == object.getMass();
}
bool BaseFigure::operator<(const IPhysObject &object) const
{
    return getMass() < object.getMass();
}

void BaseFigure::draw()
{
    cout << "Length: " << getLength() << endl;
    cout << "Width: " << getWidth() << endl;
    cout << "Square: " << getSquare() << endl;
    cout << "Perimetr: " << getPerimetr() << endl;
    cout << "Mass: " << getMass() << endl;
    cout << "Position: x = " << getPosition().x << ", y = " << getPosition().y << endl;
    cout << "Class name: " << className() << endl;
    cout << "Size: " << getSize() << endl;
}

const char *BaseFigure::className()
{
    return typeid(*this).name();
}

uint BaseFigure::getSize()
{
    return sizeof(*this);
}