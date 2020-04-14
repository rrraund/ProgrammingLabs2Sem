#pragma once
#include <iostream>
#include <cmath>

typedef unsigned int uint;
using namespace std;


class IGeoFig
{
public:
    virtual double getSquare() = 0;
    virtual double getPerimetr() = 0;
};


class CVector2D
{
public:
    double x;
    double y;
    CVector2D();
};


class IPhysObject
{
public:
    virtual double getMass() const = 0;
    virtual CVector2D getPosition() const = 0;

    virtual bool operator==(const IPhysObject &object) const = 0;
    virtual bool operator<(const IPhysObject &object) const = 0;
};


class IPrintable
{
public:
    virtual void draw() = 0;
};


class IDialogInitiable
{
public:
    virtual void initFromDialog() = 0;
};


class BaseCObject
{
public:
    virtual const char *className() = 0;
    virtual uint getSize() = 0;
};


class BaseFigure :
        public IGeoFig, public CVector2D, public IPhysObject,
        public IPrintable, public IDialogInitiable, public BaseCObject
{
protected:
    double length_;
    double width_;
    int mass_;
    CVector2D position_;

public:
    BaseFigure();
    BaseFigure(int length, int width, int mass, CVector2D vector2D);

    double getLength();
    double getWidth();
    double getSquare();
    double getPerimetr();
    double getMass() const;
    CVector2D getPosition() const;

    void initFromDialog();

    bool operator==(const IPhysObject &object) const;
    bool operator<(const IPhysObject &object) const;

    void draw() override;

    const char *className();
    uint getSize();
};