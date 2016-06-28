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
  // Dump the graphviz representation for visualization.
  B.Dump();

  std::vector<Node*> BFSTraversal;
  B.BFS(B.GetRoot(), BFSTraversal);
  std::cout << "\nBFS output:" << BFSTraversal;

  std::vector<Node*> DFSTraversal;
  B.DFS(B.GetRoot(), DFSTraversal);
  std::cout << "\nDFS output:" << DFSTraversal;

  return 0;
}
// inexact algorithm
