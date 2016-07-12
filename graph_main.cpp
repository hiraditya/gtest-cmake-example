#include"graph.h"
#include <vector>
#include <algorithm>
#include "stl_containers.h"

/*

[](){}

[](){ return true; }

[]()-> int { return 10; }

*/

void testAlgorithm(const BinaryTree &B, int i) {
  BinaryTree::const_iterator it;
  it = std::find_if(B.begin(), B.end(),
                    [i](const Node& N){ return (N.GetData() == i);});

  if (it != B.end())
    std::cout << "\nFound an element of value " << i;
  else
    std::cout << "\nDid not find an element of value " << i;

  unsigned c = std::count_if(B.begin(), B.end(),
                             [i](const Node& N){ return (N.GetData() == i);});

  std::cout << "\n#of elements found: " << c << std::endl;

  bool any = std::any_of(B.begin(), B.end(),
                         [i](const Node& N){ return (N.GetData() == i);});

  if (any)
    std::cout << "\nat least one elem equals: " << i << std::endl;

  bool none = std::none_of(B.begin(), B.end(),
                           [i](const Node& N){ return (N.GetData() < 0);});

  if (none)
    std::cout << "\nnone of elems are negative " << std::endl;
}

int main(int argc, char *argv[]) {
  int V1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int V2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  BinaryTree B;
  for (int i = 0; i < 10; ++i) {
    B.Insert(V1[i]);
    B.Insert(V2[10 -i -1]);
  }
  /*/ Dump the graphviz representation for visualization.
  B.Dump();

  std::vector<const Node*> BFSTraversal;
  B.BFS(B.GetRoot(), BFSTraversal);
  std::cout << "\nBFS output:" << BFSTraversal;

  std::vector<const Node*> DFSTraversal;
  B.DFS(B.GetRoot(), DFSTraversal);
  std::cout << "\nDFS output:" << DFSTraversal;*/
  //testAlgorithm(B, std::atoi(argv[1]));
  stl_container_algo();
  return 0;
}
// inexact algorithm
