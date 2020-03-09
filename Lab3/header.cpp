#include <iostream>
#include "header.h"

using namespace std;



Square::Square(double x_, double y_, double side_, double angle_)
{
    coordinate = Point(x_, y_);
    side = side_;
    angle = angle_;
}

Square::Point::Point()
{
    x = 0;
    y = 0;
}

Square::Point::Point(double x_, double y_)
{
    x = x_;
    y = y_;
}

bool Square::operator==(const Square &x) const
{
    if (side == x.side)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Square::operator!=(const Square &x) const
{
    if (side != x.side)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Square::operator>(const Square &x) const
{
    if (side > x.side)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Square::operator<(const Square &x) const
{
    if (side < x.side)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Square Square::operator*(const double &x) const
{
    Square newSquare(coordinate.x, coordinate.y, side * x, angle);
    return newSquare;
}

Square Square::operator+(const pair<double, double> &x) const
{
    Square newSquare(coordinate.x + x.first, coordinate.y + x.second, side, angle);
    return newSquare;
}

void Square::printSquare()
{
    cout << endl;
    cout << "Coordinates: " << coordinate.x << ' ' << coordinate.y << endl;
    cout << "Side: " << side << endl;
    cout << "Angle: " << angle << endl;
}



Array::Array()
{
    for (int i = 0; i < 100; i++)
    {
        array[i] = 0;
    }
    length = 0;
}

Array::Array(int array_[], int length_)
{
    for (int i = 0; i < length_; i++)
    {
        array[i] = array_[i];
    }
    length = length_;
}

Array Array::operator+(const Array &arr)
{
    int resultLength = length + arr.length;
    if (resultLength > 100)
    {
        cout << "Array overflow" << endl;
        return Array(array, length);
    }

    int resultArray[100];
    int i;
    for (i = 0; i < length; i++)
    {
        resultArray[i] = array[i];
    }
    for (int j = 0; j < arr.length; j++)
    {
        resultArray[i] = arr.array[j];
        i++;
    }

    return Array(resultArray, resultLength);
}

bool Array::operator==(const Array &arr) const
{
    if (length == arr.length)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Array::operator!=(const Array &arr) const
{
    if (length != arr.length)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Array::operator>(const Array &arr) const
{
    if (length > arr.length)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Array::operator<(const Array &arr) const
{
    if (length < arr.length)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Array::printArray()
{
    cout << endl;
    cout << "Length: " << length << endl;
    cout << "Values: ";
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;
}