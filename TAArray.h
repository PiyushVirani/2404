#ifndef TAARRAY_H
#define TAARRAY_H

#include "TextArea.h"
#include "defs.h"

class TAArray {
  public:
    TAArray();
    ~TAArray();
    bool add(TextArea* textArea);
    bool add(TextArea* textArea, int index);
    TextArea* get(const std::string& id) const;
    TextArea* get(int index) const;
    TextArea* remove(const std::string& id);
    TextArea* remove(int index);
    int getSize() const;
    void print() const;

  private:
    TextArea** textAreas;
    int size;
};
#endif
