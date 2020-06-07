#include <iostream>
#include <exception>
#include "Exception.h"

using namespace std;


template <class T>
class Array
{
private:
    int size;
    T *arr;
public:
    Array();
    explicit Array(int);
    T &operator[] (int);

    int getSize();
    void printArray();
};

template<class T>
Array<T>::Array()
{
    size = 0;
    arr = new T[size];
}

template<class T>
Array<T>::Array(int size_)
{
    size = size_;
    arr = new T[size];
}

template<class T>
T &Array<T>::operator[](int i)
{
    if (i >= 0 && i < size)
    {
        return arr[i];
    }
    else
    {
        throw Exception("Index out of range", 1);
    }
}

template<class T>
int Array<T>::getSize()
{
    return size;
}

template<class T>
void Array<T>::printArray()
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}



template <typename T>
double Pow(const T &n, const int p)
{
    if (p >= 0)
    {
        double result = 1;
        for (int i = 0; i < p; i++)
        {
            result *= n;
        }
        return result;
    }
    else
    {
        double result = 1;
        for (int i = p; i < 0; i++)
        {
            result /= n;
        }
        return result;
    }
}



int main()
{
    int n, p;

    try
    {
        cout << "Enter length of your array: " << endl;
        cin >> n;
        Array<int> a(n);

        cout << "Enter values of your array: " << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        cout << "Enter p: " << endl;
        cin >> p;
        cout << a[0] << "^" << p << " = " << Pow(a[0], p);
    }
    catch (Exception &exception)
    {
        exception.printMessage();
    }

    return 0;
}