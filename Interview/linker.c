#include <stdio.h>

int globalVal = 100;
int gl;

void func(int a, int b) {
  printf("a: %p, b: %p", &a, &b);
  int aa = 100;
  int bb = 200;
  printf("aa: %p, bb: %p", &aa, &bb);
}

int main() {
  static int staticVal = 1000;
  static int sv;

  int a = 10;
  int b = 20;
  func(a, b);
  return 0;
}
