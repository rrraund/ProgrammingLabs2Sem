#pragma once
#include "BaseFigure.h"


class Triangle : public BaseFigure
{
private:
    CVector2D A;
    CVector2D B;
    CVector2D C;
    double mass = 0;
    const char *name = "Triangle";

public:
    Triangle();
    ~Triangle();

    double getSquare();
    double getPerimetr();
    double getMass() const;

    CVector2D getPosition() const;

    void draw();
    void initFromDialog();
};