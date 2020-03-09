#include <iostream>
#include <complex>
#include "procedure.h"

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    change_pointer(&a, &b);
    cout << a << " " << b << endl;

    change_link(a, b);
    cout << a << " " << b << endl << endl;

    double a1;
    cin >> a1;
    rounding_down_pointer(&a1);
    cout << a1 << endl;

    rounding_down_link(a1);
    cout << a1 << endl << endl;

    complex<double> z1;
    double z2;
    cin >> z1 >> z2;
    complex_multiplying_pointer(&z1, &z2);
    cout << z1 << endl;

    complex_multiplying_link(z1, z2);
    cout << z1 << endl << endl;

    circle_struct circle;
    pair<int, int> center;
    center.first = a;
    center.second = b;
    shift_circle_pointer(&circle, &center);
    cout << circle.center_x << " " << circle.center_y << " " << circle.radius << endl;

    shift_circle_link(circle, center);
    cout << circle.center_x << " " << circle.center_y << " " << circle.radius << endl;
}