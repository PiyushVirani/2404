#include <iostream>
#include "TextArea.h"
using namespace std;

TextArea::TextArea(int x, int y, int width, int height, string id, string text, RGB fill, RGB border) {
  this->rect.x = x;
  this->rect.y = y;
  this->rect.width = width;
  this->rect.height = height;
  this->id = id;
  this->text = text;
  this->fill = fill;
  this->border = border;
}
TextArea::TextArea(const Rectangle& rect, string id, string text, RGB fill, RGB border) {
  this->rect = rect;
  this->id = id;
  this->text = text;
  this->fill = fill;
  this->border = border;
}
TextArea::TextArea(const TextArea& textArea) {
  this->id = textArea.id;
  this->rect = textArea.rect;
  this->text = textArea.text;
  this->border = textArea.border;
  this->fill = textArea.fill;

}
TextArea::~TextArea() {}

int TextArea::getWidth() {
  return rect.width;
}
int TextArea::getHeight() {
  return rect.height;
}
string TextArea::getId() const {
  return id;
}
string TextArea::getText() const {
  return text;
}
void TextArea::setWidth(int width) {
  this->rect.width = width;
}
void TextArea::setHeight(int height) {
  this->rect.height = height;
}
void TextArea::setText(const string& text) {
  this->text = text;
}

void TextArea::draw(Display *display, Window win, GC gc, int xgap, int ygap) {

    int xPadding = 6;
    int yPadding = 4;
    int charXSpace = 6;
    int charYSpace = 16;
    int currentY = charYSpace + ygap - yPadding;
    int allXSpace = rect.width - 2 * (1 + xPadding);
    int lettersPerLine = allXSpace/charXSpace;

    XSetForeground(display, gc, fill.getColour());
    XFillRectangle(display, win, gc, xgap, ygap, rect.width, rect.height);
    XSetForeground(display, gc, border.getColour());
    XDrawRectangle(display, win, gc, xgap, ygap, rect.width, rect.height);
    XSetForeground(display, gc, 0);

    size_t firstPos = 0;
    while (currentY <= ygap + rect.height && firstPos < text.size()) {
      size_t lastPos = firstPos + lettersPerLine;
      if (lastPos < text.size()) {
        size_t spaceIndex = text.rfind(' ', lastPos);
        if (spaceIndex != string::npos && spaceIndex >= firstPos) {
          lastPos = spaceIndex;
        }
      } else {
        lastPos = text.size();
      }
      string currentLine = text.substr(firstPos, lastPos-firstPos);
      XDrawString(display, win, gc, xgap + xPadding, currentY, currentLine.c_str(), currentLine.size());
      currentY += charYSpace;
      firstPos = lastPos;
      while (firstPos < text.size() && text[firstPos] == ' ') {
        firstPos++;
      }
    }
}

bool TextArea::overlaps(TextArea& b) {
  return rect.overlaps(b.rect);
}

void TextArea::print() const {
  cout << "TextArea id: " << id << endl;
  cout << "Preferred location: " << rect.x << ", " << rect.y << endl;
  cout << "Size: " << rect.width << ", " << rect.height << endl;
  cout << "Text: " << text << endl;
}



