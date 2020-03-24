#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    double x, y, side, angle;
    cin >> x >> y >> side >> angle;
    Square s1(x, y, side, angle);

    cin >> x >> y >> side >> angle;
    Square s2(x, y, side, angle);

    s1.printSquare();
    s2.printSquare();

    if (s1 == s2)
    {
        cout << "s1 = s2" << endl;
    }
    else if (s1 > s2)
    {
        cout << "s1 > s2" << endl;
    }
    else if (s1 < s2)
    {
        cout << "s1 < s2" << endl;
    }

    double k;
    cin >> k;
    Square newSquare1 = s1 * k;
    newSquare1.printSquare();

    pair <double, double> v;
    cin >> v.first >> v.second;
    Square newSquare2 = s2 + v;
    newSquare2.printSquare();



    int array[100]; int size;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    Array a1(array, size);

    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    Array a2(array, size);

    a1.printArray();
    a2.printArray();

    if (a1 == a2)
    {
        cout << "a1 = a2" << endl;
    }
    else if (a1 > a2)
    {
        cout << "a1 > a2" << endl;
    }
    else if (a1 < a2)
    {
        cout << "a1 < a2" << endl;
    }

    Array a3 = a1 + a2;
    Array a4 = a1.operator+(a2);
    
    a3.printArray();
    a4.printArray();
    
    return 0;

/*
Входные данные:
0 0 2 0
1 1 4 45
2.5
1.2 2

..........
5
1 2 3 4 5
3
31 32 33

*/
}
