#include <iostream>
#include <complex>
#include "procedure.h"

void change_pointer(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void change_link(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void rounding_down_pointer(double* a)
{
    *a = double(int(*a));
}

void rounding_down_link(double &a)
{
    a = double(int(a));
}

void complex_multiplying_pointer(complex<double> *a, double *b)
{
    *a = *a * *b;
}

void complex_multiplying_link(complex<double> &a, double &b)
{
    a = a * b;
}

circle_struct::circle_struct()
{
    center_x = 0;
    center_y = 0;
    radius = 1;
}

void shift_circle_pointer(circle_struct *circle, pair<int, int> *shift_vector)
{
    circle->center_x += shift_vector->first;
    circle->center_y += shift_vector->second;
}

void shift_circle_link(circle_struct &circle, pair<int, int> &shift_vector)
{
    circle.center_x += shift_vector.first;
    circle.center_y += shift_vector.second;
}