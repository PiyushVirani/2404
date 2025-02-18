#include "TAArray.h"
#include <iostream>

    TAArray::TAArray() {
      textAreas = new TextArea*[MAX_COMPONENTS];
      size = 0;
    }
    TAArray::~TAArray() {
      for (int i = 0; i < size; i++) {
        delete textAreas[i];
      }
    }
    bool TAArray::add(TextArea* textArea) {
      if (size >= MAX_COMPONENTS) {
        return false;
      }
      textAreas[size] = textArea;
      size++;
      return true;
    }
    bool TAArray::add(TextArea* textArea, int index) {
      if (size >= MAX_COMPONENTS || index >= MAX_COMPONENTS || index < 0) {
        return false;
      }
      for (int i = size; i > index; i--) {
        textAreas[i] = textAreas[i - 1];
      }
      textAreas[size] = textArea;
      size++;
      return true;

    }
    TextArea* TAArray::get(const std::string& id) const {
      for (int i = 0; i < size; i++) {
        if (textAreas[i]->getId()==id) {
          return textAreas[i];
        }
      }
      return nullptr;
    }
    TextArea* TAArray::get(int index) const {
      if (index >= size || index < 0) {
        return nullptr;
      }
      return textAreas[index];
    }
    TextArea* TAArray::remove(const std::string& id) {
      for (int i = 0; i < size; i++) {
        if (textAreas[i]->getId()== id) {
          TextArea* temp = textAreas[i];
          for (int j = i; j < size-1; j++) {
            textAreas[j] = textAreas[j + 1];
          }
          size--;
          return temp;
        }
      }
      return nullptr;
    }
    TextArea* TAArray::remove(int index) {
      if (index < 0 || index >= size) {
        return nullptr;
      }
      TextArea* temp = textAreas[index];
      for (int i = index; i < size - 1; i++) {
        textAreas[i] = textAreas[i + 1];
      }
      size--;
      return temp;
    }

    int TAArray::getSize() const {
      return size;
    }

    void TAArray::print() const {
      std::cout << "TAArray contains " << size << " TextAreas:\n";
      for (int i = 0; i < size; i++) {
        if (textAreas[i])
          textAreas[i]->print();
      }
    }
    TextArea* TAArray::remove(int index) {
      if (index < 0 || index >= size) {
        return nullptr;
      }

      TextArea* temp = textAreas[index];
      for (int i = index; i < size - 1; i++) {
        textAreas[i] = textAreas[i + 1];
      }
      size--;
      return temp;
    }







