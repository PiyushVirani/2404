#include <iostream>
#include "RGB.h"
using namespace std;

RGB::RGB(int r, int g, int b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

RGB::RGB(CuColour cuColour) {
    this->r = (cuColour >> 16) & 0xFF;
    this->g = (cuColour >> 8) & 0xFF;
    this->b = cuColour & 0xFF;
}
RGB::RGB() {
    this->r = 0;
    this->g = 0;
    this->b = 0;
}


int RGB::getR() const{
    return r;
}
int RGB::getG() const{
    return g;
}
int RGB::getB() const{
    return b;
}
CuColour RGB::getColour() {
    return (static_cast<CuColour>(r) << 16) | (static_cast<CuColour>(g) << 8) | static_cast<CuColour>(b);
}

void RGB::setR(int r) {
    this->r = r;
}
void RGB::setG(int g) {
    this->g = g;
}
void RGB::setB(int b) {
    this->b = b;
}
void RGB::setColour(CuColour colour) {
    this->r = (colour >> 16) & 0xFF;
    this->g = (colour >> 8) & 0xFF;
    this->b = colour & 0xFF;
}


RGB RGB::WHITE() {
  return RGB(255, 255, 255);
}
RGB RGB::BLACK() {
    return RGB(0, 0, 0);
}
RGB RGB::RED() {
    return RGB(255, 0, 0);
}
RGB RGB::GREEN() {
    return RGB(0, 255, 0);
}
RGB RGB::BLUE() {
  return RGB(0, 0, 255);
}

