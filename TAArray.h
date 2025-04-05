#ifndef TAARRAY_H
#define TAARRAY_H

#include <iostream>
#include "TextArea.h"
#include "defs.h"
using namespace std;

class TAArray {
  public:
    // constructor
    TAArray();
    // destructor
    ~TAArray();
    bool add(TextArea* textArea);
    bool add(TextArea* textArea, int index);
    TextArea* get(const string& id) const;
    TextArea* get(int index) const;
    TextArea* remove(const string& id);
    TextArea* remove(int index);
    int getSize() const;
    void print();

  // member variables
  private:
    TextArea** textAreas;
    int size;
};
#endif
