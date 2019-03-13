#include <vector>

template <class T>
class Queue {
private:
  std::vector<T> left;
  std::vector<T> right;
public:
  void enqueue(T const);
  T dequeue();
  bool empty() const { return left.empty() && right.empty();}
};