#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <iostream>

class Node {
  int Data;
  int Id;
  Node *Left;
  Node *Right;

public:
  Node (int D, int I)
    : Data(D), Id(I), Left(NULL), Right(NULL)
  {}

  Node *GetLeft() {
    return Left;
  }

  Node *GetRight() {
    return Right;
  }

  const Node *GetLeft() const {
    return Left;
  }

  const Node *GetRight() const {
    return Right;
  }

  int GetData() const {
    return Data;
  }

  int GetId() const {
    return Id;
  }

  void SetLeft(Node *N) {
    Left = N;
  }

  void SetRight(Node *N) {
    Right = N;
  }

  void SetData(int d) {
    Data = d;
  }

  void SetId(int d) {
    Id = d;
  }

  void Dump(std::ostream &os) const;
  void DumpGV() const;
};


class BinaryTree {
  Node *Root;
  static int Counter;
  typedef std::list<Node> TreeT;
  TreeT Tree;

public:

  BinaryTree()
    : Root (NULL)
  { }

  BinaryTree(Node *r)
    : Root (r) {
    assert(Tree.empty());
    Node N(*r);
    Tree.push_back(N);
    Root = &Tree.back();
    Root->SetLeft(NULL);
    Root->SetRight(NULL);
    Root->SetId(0);    
  }

  const Node *GetRoot() const { return Root; }

  typedef TreeT::iterator iterator;
  typedef TreeT::const_iterator const_iterator;

  iterator begin() { return Tree.begin(); }
  iterator end() { return Tree.end(); }

  const_iterator begin() const { return Tree.begin(); }
  const_iterator end() const { return Tree.end(); }

  // Breadth First Traversal of the tree.
  void BFS(const Node *N, std::vector<const Node *>& V) const;

  // Depth First Traversal of the tree.
  void DFS(const Node *N, std::vector<const Node *>& V) const;

  bool InsertLeft(Node *R, int N);

  bool InsertRight(Node *R, int N);

  bool Insert(Node *Root, int N);

  bool Insert(int N);

  void BuildBinaryTree(std::vector<int> &V);

  void Dump() const;
};

inline std::ostream& operator<<(std::ostream &os, const Node* N) {
  N->Dump(os);
  return os;
}

inline std::ostream& operator<<(std::ostream &os, std::vector<const Node*> &V) {
  for (unsigned i = 0; i < V.size(); ++i)
    os << V[i];
  return os;
}

#endif // GRAPH_H
