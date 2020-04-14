#pragma once
#include "BaseFigure.h"


class Circle : public BaseFigure
{
private:
    CVector2D center;
    double radius = 0;
    double mass = 0;
    const char *name = "Circle";

public:
    Circle();
    ~Circle();

    double getSquare();
    double getPerimetr();
    double getMass() const;

    CVector2D getPosition() const;

    void draw();
    void initFromDialog();
};