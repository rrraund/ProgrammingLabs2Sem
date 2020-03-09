#ifndef LAB1_PROCEDURE_H
#define LAB1_PROCEDURE_H

#include <iostream>
#include <complex>

using namespace std;

void change_pointer(int *a, int *b);
void change_link(int &a, int &b);

void rounding_down_pointer(double* a);
void rounding_down_link(double &a);

void complex_multiplying_pointer(complex<double> *a, double *b);
void complex_multiplying_link(complex<double> &a, double &b);

struct circle_struct
{
    double center_x;
    double center_y;
    double radius;
    circle_struct();
};
void shift_circle_pointer(circle_struct *circle, pair<int, int> *shift_vector);
void shift_circle_link(circle_struct &circle, pair<int, int> &shift_vector);


#endif