#include <iostream>

using namespace std;

template <class Item>
class MaxHeap {
private:
  Item *data;
  int count;

  void shiftUP(int k) {
    while(k > 1 && data[k] > data[k/2]){
      swap(data[k], data[k/2]);
      k /= 2;
    }
  }

  void shiftDown(int k) {
    while(2*k <= count){
      int j = 2 * k;
      if (2*k + 1 <= count && data[2*k] < data[2*k + 1]) 
        j = 2 * k + 1;
      
      swap(data[j], data[k]);
      k = j;
    }
    
  }

public:
  MaxHeap(int capacity) {
    data = new Item(capacity + 1);
    count = 0;
  }

  ~MaxHeap() {
    delete [] data;
  }

  void insert(const Item item) {
    data[count+1] = item;
    count++;

    shiftUP(count);
  }

  Item top() {
    Item res = data[1];
    data[1] = data[count];
    count--;

    shiftDown(1);
    return res;
  }

  bool isEmpty() { return count == 0; }

  int size() { return count; }

  void print() {
    for(int i = 1; i <= count; i++)
    {
      cout << data[i] << ", ";
    }
    cout << endl;
  }
};


int main() {
  MaxHeap<int> heap = MaxHeap<int>(100); 
  for(int i = 0; i < 20; i++)
  {
    heap.insert(random() % 100);
  }
  
  cout << heap.top() << endl;
  cout << heap.size() << endl;

  heap.print();
  
  return 0;
}