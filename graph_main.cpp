#include"graph.h"
#include <vector>

int main() {
  int V1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int V2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  
  BinaryTree B;
  for (int i = 0; i < 10; ++i) {
    B.Insert(V1[i]);
    B.Insert(V2[10 -i -1]);
  }
  B.Dump();  
  return 0;
}
