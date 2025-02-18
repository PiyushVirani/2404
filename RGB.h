#ifndef RGB_H
#define RGB_H

#include <iostream>
#include "defs.h"
using namespace std;

class RGB {
private:
    int r,g,b;
public:
    RGB(int r, int g, int b);
    RGB (CuColour colour);
    RGB ();


    int getR()const;
    int getG()const;
    int getB()const;
    CuColour getColour();

    void setR(int r);
    void setG(int g);
    void setB(int b);
    void setColour(CuColour colour);

    static RGB WHITE();
    static RGB BLACK();
    static RGB RED();
    static RGB GREEN();
    static RGB BLUE();
};
#endif

