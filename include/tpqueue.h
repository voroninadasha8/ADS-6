// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>
template<typename T, int size>
class TPQueue {

  private:
      T* arr;
      int first, last, count;
    
  public:
      TPQueue() : first(0), last(0), count(0) {
        arr = new T[size];
      }
      ~TPQueue() {
        delete[] arr;
      }
      bool isEmpty() const {
        return count == 0;
      }
      bool isFull() const {
        return size == count;
      }
      void push(const T& value) {
        if (isFull()) {
          throw std::string("Full!");
        } else {
          int end = last;
          for (int i = last; i > first; i--) {
            if (arr[i - 1].prior < value.prior) {
              end = i - 1;
              arr[i % size] = arr[i - 1];
            }
          }
          arr[end % size] = value;
          count++;
          last++;
        }
      }
      const T& pop() {
        if (isEmpty()) {
          throw std::string("Empty!");
        }
        count--;
        return arr[first++ % size];
      }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
