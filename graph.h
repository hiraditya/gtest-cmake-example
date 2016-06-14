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

  int GetData() {
    return Data;
  }

  int GetId() {
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

  void Dump(std::ostream &os);
  void DumpGV();
};


class BinaryTree {
  Node *Root;
  static int Counter;
  std::list<Node> Tree;
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

  Node *GetRoot() { return Root; }

  void BFS(Node *N, std::vector<Node *>& V);

  bool InsertLeft(Node *R, int N);

  bool InsertRight(Node *R, int N);

  bool Insert(Node *Root, int N);

  bool Insert(int N);

  void BuildBinaryTree(std::vector<int> &V);

  void Dump();
};

inline std::ostream& operator<<(std::ostream &os, Node* N) {
  N->Dump(os);
  return os;
}

inline std::ostream& operator<<(std::ostream &os, std::vector<Node*> &V) {
  for (unsigned i = 0; i < V.size(); ++i)
    os << V[i];
  return os;
}

#endif // GRAPH_H

