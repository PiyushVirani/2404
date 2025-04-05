#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <iostream>
#include <string>
#include <X11/Xlib.h>
#include "RGB.h"
#include "defs.h"
using namespace std;

class TextArea {
private:
    Rectangle rect;
    string text, id;
    RGB fill, border;

public:
    // constructors
    TextArea(int x, int y, int width, int height, string id, string label, RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());
    TextArea(const Rectangle& rect, string id, string label, RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());
    TextArea(const TextArea& textArea);

    //destructor
    ~TextArea();

    // getters
    int getWidth();
    int getHeight();
    string getId() const;
    string getText() const;

    // setters
    void setWidth(int width);
    void setHeight(int height);
    void setId(string id);
    void setText(const string& text);

    void draw(Display *display, Window win, GC gc, int x, int y);
    bool overlaps(TextArea& ta);
    void print() const;
};
#endif
