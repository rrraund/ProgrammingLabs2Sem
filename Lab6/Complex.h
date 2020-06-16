#pragma once

#include <iostream>


class Complex
{
private:
    float real;
    float imaginary;
    double module() const;

public:
    Complex(const float&, const float&);
    Complex(const Complex& object);
    Complex(Complex&);
    Complex();
    Complex operator * (const float&);
    Complex operator * (const Complex&);
    Complex operator + (const Complex&);
    bool operator < (const Complex&) const;
    bool operator > (const Complex&) const;
    bool operator == (const Complex&) const;
    bool operator <= (const Complex&) const;
    bool operator >= (const Complex&) const;
    bool operator != (const Complex&) const;
    operator double();
    friend std::istream& operator>>(std::istream&, Complex&);
    friend std::ostream& operator<<(std::ostream&, const Complex&);
};