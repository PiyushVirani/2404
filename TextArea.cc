#include <iostream>
#include "defs.h"
#include "TextArea.h"
using namespace std;


TextArea::TextArea(int x, int y, int width, int height, const string& id, const string& label, const RGB& fill, const RGB& border) {
  dimensions.x = x;
  dimensions.y = y;
  dimensions.width = width;
  dimensions.height = height;
  this->id = id;
  this->text = label;
  this->fill = fill;
  this->border = border;
}
TextArea::TextArea(const Rectangle& dimensions, const string& id, const string& label, const RGB& fill, const RGB& border) {
  this->dimensions = dimensions;
  this->id = id;
  this->text = label;
  this->fill = fill;
  this->border = border;
}
TextArea::TextArea() {
  dimensions.x = 10;
  dimensions.y = 5;
  dimensions.width = 10;
  dimensions.height = 5;
  this->id = "DEFAULT";
  this->text = "Hello";
  this->fill = RGB::WHITE();
  this->border = RGB::BLACK();
}
TextArea::TextArea(const TextArea& other) {
  dimensions = other.dimensions;
  id = other.id;
  text = "DUPLICATE";
  fill = other.fill;
  border = other.border;

}

int TextArea::getX() {
  return this->dimensions.x;
}
int TextArea::getY() {
  return this->dimensions.y;
}
int TextArea::getWidth() {
  return this->dimensions.width;
}
int TextArea::getHeight() {
  return this->dimensions.height;
}
string TextArea::getText() {
  return this->text;
}
string TextArea::getId() {
  return this->id;
}

void TextArea::setX(int x) {
  this->dimensions.x = x;
}
void TextArea::setY(int y) {
  this->dimensions.y = y;
}
void TextArea::setWidth(int width) {
  this->dimensions.width = width;
}
void TextArea::setHeight(int height) {
  this->dimensions.height = height;
}
void TextArea::setText(const string& text) {
  this->text = text;
}
void TextArea::setFill(const RGB& fill) {
  this->fill = fill;
}
void TextArea::setBorder(const RGB& border) {
  this->border = border;
}
void TextArea::draw(Display *display, Window win, GC gc, int x, int y) {
}

bool TextArea::overlaps(const TextArea& ta) const{
  return dimensions.overlaps(ta.dimensions);
}
void TextArea::print() const{
  cout << "TextArea id: "<< id <<endl;
  cout << "Preferred location: " <<dimensions.x<<", "<<dimensions.y<<endl;
  cout << "Size: "<<dimensions.width<<", "<<dimensions.height<<endl;
  cout << "TextArea text: "<<text<<endl;
}
