#include "Complex.h"


Complex::Complex(const float &inputReal, const float &inputImaginary)
{
    real = inputReal;
    imaginary = inputImaginary;
}

Complex::Complex(const Complex &object)
{
    real = object.real;
    imaginary = object.imaginary;
}

Complex::Complex(Complex &object)
{
    real = object.real;
    imaginary = object.imaginary;
}

Complex::Complex()
{
    imaginary = 0;
    real = 0;
}

Complex Complex::operator*(const float &input)
{
    return Complex(input * this->real, input * this->imaginary);
}

Complex Complex::operator*(const Complex &input)
{
    return Complex(input.real * this->real - input.imaginary * this->imaginary, input.real * this->imaginary + input.imaginary * this->real);
}

Complex Complex::operator+(const Complex &input)
{
    return Complex(this->real + input.real, this->imaginary + input.imaginary);
}

bool Complex::operator<(const Complex &right) const
{
    return this->module() < right.module() ? true : false;
}

bool Complex::operator>(const Complex &right) const
{
    return this->module() > right.module() ? true : false;
}

bool Complex::operator==(const Complex &right) const
{
    return !(*this < right) && !(*this > right) ? true : false;
}

bool Complex::operator<=(const Complex &right) const
{
    return (*this < right) || (*this == right) ? true : false;
}

bool Complex::operator>=(const Complex &right) const
{
    return (*this < right) || (*this == right) ? true : false;
}

bool Complex::operator!=(const Complex &right) const
{
    return !(*this == right);
}

Complex::operator double()
{
    return sqrt(pow(this->real, 2) + pow(this->imaginary, 2));
}

double Complex::module() const
{
    return sqrt(pow(real, 2) + pow(imaginary, 2));
}

std::ostream& operator<<(std::ostream &stream, const Complex &output)
{
    stream << output.real;
    if (output.imaginary > 0)
    {
        stream << " + " << output.imaginary << "i";
    }
    else
    {
        stream << " " << output.imaginary << "i";
    }
    return stream;
}

std::istream& operator>>(std::istream &stream, Complex &input)
{
    stream >> input.real >> input.imaginary;
    return stream;
}