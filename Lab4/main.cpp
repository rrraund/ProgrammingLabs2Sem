#include <iostream>
#include <vector>
#include <algorithm>
#include "Circle.h"
#include "Triangle.h"

using namespace std;


enum Commands
{
    ADD = 1,
    SHOW_ALL = 2,
    SUM_SQUARES = 3,
    SUM_PERIMETERS = 4,
    CENTER_MASS = 5,
    SUM_MEMORY = 6,
    SORT = 7,
    EXIT = 8
};

enum Figure
{
    CIRCLE = 1,
    TRIANGLE = 2
};


void menu()
{
    cout << "Enter 1 to add figure." << endl;
    cout << "Enter 2 to show all figures." << endl;
    cout << "Enter 3 to show sum of all squares." << endl;
    cout << "Enter 4 to show sum of all perimeters." << endl;
    cout << "Enter 5 to show center mass of all system." << endl;
    cout << "Enter 6 to show memory size of all system." << endl;
    cout << "Enter 7 to show sort figures." << endl;
    cout << "Enter 0 to exit program." << endl;
    cout << "Add command: ";
}



int main()
{
    vector<BaseFigure*> system;

    int command, figureType;
    double x, y, sumS, sumP, centerMassAllSystem, memorySizeAllSystem;
    CVector2D centerMass;

    menu();

    while(true)
    {
        cin >> command;
        cout << endl;

        switch (command)
        {
            case ADD:
            {
                cout << "Enter 1 to add circle." << endl;
                cout << "Enter 2 to add triangle." << endl;
                cout << "Add command: ";
                cin >> figureType;
                cout << endl;

                switch (figureType)
                {
                    case CIRCLE:
                        system.push_back(new Circle());
                        break;
                    case TRIANGLE:
                      system.push_back(new Triangle);
                      break;
                    default:
                        cout << "Unknown figure! Please, try again!";
                }
            }
            case SHOW_ALL:
            {
                for (auto& figure : system)
                {
                    figure->draw();
                }
            }
            case SUM_SQUARES:
            {
                sumS = 0;
                for (auto& figure : system)
                {
                    sumS += figure->getSquare();
                }
                cout << "Square system: " << sumS << endl;
                break;
            }
            case SUM_PERIMETERS:
            {
                sumP = 0;
                for (auto& figure : system)
                {
                    sumP += figure->getPerimetr();
                    cout << "Perimeter system: " << sumP << endl;
                    break;
                }
            }
            case CENTER_MASS:
            {
                centerMassAllSystem = 0;
                x = 0;
                y = 0;
                for (auto& figure : system)
                {
                    x += figure->getPosition().x * figure->getMass();
                    y += figure->getPosition().y * figure->getMass();
                    centerMassAllSystem += figure->getMass();
                }
                centerMass.x = x / centerMassAllSystem;
                centerMass.y = y / centerMassAllSystem;
                cout << "НЕ ПОНЯЛ, ЧЕ МНЕ НУЖНО ВЫВЕСТИ???" << endl;
                break;
            }
            case SUM_MEMORY:
            {
                cout << "Figures memory: ";
                for (auto& figure : system)
                {
                    memorySizeAllSystem += figure->getSize();
                }
                cout << "Memory size system: " << memorySizeAllSystem << endl;
                break;
            }
            case SORT:
            {
                sort(system.begin(), system.end(), [](BaseFigure* x, BaseFigure* y) { return *x < *y;});
                cout << "Sort: ";
                for (auto& figure : system)
                {
                    cout << figure->getMass() << " ";
                }
                cout << endl;
                break;
            }
            case EXIT:
            {
                return 0;
            }
            default:
            {
                cout << "Unknown command! Please, try again!" << endl;
                break;
            }
        }
    }
}