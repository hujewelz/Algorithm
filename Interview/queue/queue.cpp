#include "queue.hpp"
#include <iostream>
template <class T>
void Queue<T>::enqueue(T const ele) {
  left.push_back(ele);
} 

template <class T>
T Queue<T>::dequeue() {
  if (right.empty()) {
    int size = left.size();
    for(int i = size - 1; i >= 0; i--)
    {
      right.push_back(left[i]);
    }
    left.clear();
  }
  T back = right.back();
  right.pop_back();
  return back;
}

int main() {
  Queue<int> queue;
  queue.enqueue(1);
  queue.enqueue(2);
  std::cout << queue.dequeue();
  std::cout << queue.dequeue();
  
}