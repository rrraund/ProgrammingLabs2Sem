#include <iostream>
#include <vector>
#include <iterator>
#include "Complex.h"

using namespace std;


template <typename iterator, typename object>
bool noneOf(const iterator begin, const iterator end, bool (&func)(object))
{
    for (auto it = begin; it != end; it++)
    {
        if (func(*it))
        {
            return false;
        }
    }
    return true;
}

template <typename iterator, typename object>
bool isSorted(const iterator begin, const iterator end, bool (&func)(object, object))
{
    iterator prevIt = begin;
    for (auto it = begin + 1; it != end; it++)
    {
        if (!func(*prevIt, *it))
        {
            return false;
        }
    }
    return true;
}

template <typename iterator, typename object>
object findNot(const iterator begin, const iterator end, const object obj)
{
    for (auto it = begin; it != end; it++)
    {
        if ((*it) != obj)
        {
            return *it;
        }
    }
    return NULL;
}


bool predFunc0(int x)
{
    return x > 0;
}

bool predFuncMod2(int x)
{
    return x % 2 == 0;
}

bool predFuncSort(int x, int y)
{
    return x < y;
}


class Edge
{
public:
    int x1, y1, x2, y2;
    double length;
};

bool predFunc0_edge(Edge a)
{
    return a.x1 > 0 && a.y1 > 0;
}

bool predFuncMod2_edge(Edge a)
{
    return (int)a.length % 2 == 0;
}

bool predFuncSort_edge(Edge a, Edge b)
{
    return a.length < b.length;
}



int main()
{
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, -4, 6, -8};

    vector<Edge> arrEdges1 = {{1, 1, 1}, {7, 7, 7}, {5, 5, 5}};
    vector<Edge> arrEdges2 = {{-2, -2, 2}, {-4, -4, 4}};

    vector<Complex> arrComplexNumbers1 = {Complex(), Complex(), Complex()};
    vector<Complex> arrComplexNumbers2 = {Complex(1., 1.), Complex(3., 3.)};

    cout << "____Arrays of integer____" << endl;
    cout << "!PredFunc0 for all arr1: " << noneOf(arr1.begin(), arr1.end(), predFunc0) << endl;
    cout << "!PredFunc0 for all arr2: " << noneOf(arr2.begin(), arr2.end(), predFunc0) << endl;
    cout << endl;

    cout << "!PredFuncMod2 for all arr1: " << noneOf(arr1.begin(), arr1.end(), predFuncMod2) << endl;
    cout << "!PredFuncMod2 for all arr2: " << noneOf(arr2.begin(), arr2.end(), predFuncMod2) << endl;
    cout << endl;

    cout << "IsSorted for all arr1: " << isSorted(arr1.begin(), arr1.end(), predFuncSort) << endl;
    cout << "IsSorted for all arr2: " << isSorted(arr2.begin(), arr2.end(), predFuncSort) << endl;
    cout << endl;

    cout << "FindNot for all arr1: " << findNot(arr1.begin(), arr1.end(), 1) << endl;
    cout << "FindNot for all arr2: " << findNot(arr2.begin(), arr2.end(), 1) << endl;
    cout << endl;

    cout << "____Arrays of edges____" << endl;
    cout << "!PredFunc0 for all arrEdges1: " << noneOf(arrEdges1.begin(), arrEdges1.end(), predFunc0_edge) << endl;
    cout << "!PredFunc0 for all arrEdges2: " << noneOf(arrEdges2.begin(), arrEdges2.end(), predFunc0_edge) << endl;
    cout << endl;

    cout << "!PredFuncMod2 for all arrEdges1: " << noneOf(arrEdges1.begin(), arrEdges1.end(), predFuncMod2_edge) << endl;
    cout << "!PredFuncMod2 for all arrEdges2: " << noneOf(arrEdges2.begin(), arrEdges2.end(), predFuncMod2_edge) << endl;
    cout << endl;

    cout << "IsSorted for all arrEdges1: " << isSorted(arrEdges1.begin(), arrEdges1.end(), predFuncSort_edge) << endl;
    cout << "IsSorted for all arrEdges2: " << isSorted(arrEdges2.begin(), arrEdges2.end(), predFuncSort_edge) << endl;
    cout << endl;

    cout << "____Arrays of complex____" << endl;
    cout << "!PredFunc0 for all arrComplexNumbers1: " << noneOf(arrComplexNumbers1.begin(), arrComplexNumbers1.end(), predFunc0) << endl;
    cout << "!PredFunc0 for all arrComplexNumbers2: " << noneOf(arrComplexNumbers2.begin(), arrComplexNumbers2.end(), predFunc0) << endl;
    cout << endl;

    cout << "!PredFuncMod2 for all arrComplexNumbers1: " << noneOf(arrComplexNumbers1.begin(), arrComplexNumbers1.end(), predFuncMod2) << endl;
    cout << "!PredFuncMod2 for all arrComplexNumbers2: " << noneOf(arrComplexNumbers2.begin(), arrComplexNumbers2.end(), predFuncMod2) << endl;
    cout << endl;

    cout << "IsSorted for all arrComplexNumbers1: " << isSorted(arrComplexNumbers1.begin(), arrComplexNumbers1.end(), predFuncSort) << endl;
    cout << "IsSorted for all arrComplexNumbers2: " << isSorted(arrComplexNumbers2.begin(), arrComplexNumbers2.end(), predFuncSort) << endl;
    cout << endl;

    return 0;
}