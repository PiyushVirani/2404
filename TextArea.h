#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <iostream>
#include <string>
#include <X11/Xlib.h>
#include <iomanip>
#include "defs.h"
#include "RGB.h"

using namespace std;

class TextArea {
private:
    Rectangle dimensions;
    string text;
    string id;
    RGB fill, border;

public:
    // constructors
    TextArea(int x, int y, int width, int height, const string& id, const string& label, const RGB& fill = RGB::WHITE(), const RGB& border= RGB::BLACK());
    TextArea(const Rectangle& dimensions, const string& id, const string& label, const RGB& fill = RGB::WHITE(), const RGB& border= RGB::BLACK());
    TextArea();
    TextArea(const TextArea& other);


    // getters
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    string getText();
    string getId();

    // setters
    void setX(int x);
    void setY(int y);
    void setWidth(int width);
    void setHeight(int height);
    void setText(const string& text);
    void setFill(const RGB& fill);
    void setBorder(const RGB& border);

    void draw(Display *display, Window win, GC gc, int x, int y);
    bool overlaps(const TextArea& ta) const;
    void print() const;
};
#endif

