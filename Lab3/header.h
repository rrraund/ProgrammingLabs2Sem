#ifndef LAB3_HEADER_H
#define LAB3_HEADER_H

#include <utility>

using namespace std;

class Square
{
private:
    struct Point
    {
        double x, y;
        Point();
        Point(double x_, double y_);
    };
    Point coordinate;
    double side;
    double angle;

public:
    Square(double x_, double y_, double side_, double angle_);

    bool operator==(const Square &x) const;
    bool operator!=(const Square &x) const;
    bool operator>(const Square &x) const;
    bool operator<(const Square &x) const;
    Square operator*(const double &x) const;
    Square operator+(const pair <double, double> &x) const;

    void printSquare();
};



class Array
{
private:
    int array[100];
    int length;

public:
    Array();
    Array(int array_[], int length_);

    Array operator+(const Array &arr);
    bool operator==(const Array &arr) const;
    bool operator!=(const Array &arr) const;
    bool operator>(const Array &arr) const;
    bool operator<(const Array &arr) const;

    void printArray();
};

#endif