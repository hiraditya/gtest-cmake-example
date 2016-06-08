#ifndef PROJECT1_H_
#define PROJECT1_H_

#include <iostream>
#include <queue>
#include <set>
#include <vector>

class Project1 {

public:
  Project1()
  {
     k = 1000;
     i = 0;
  }

  void foo(int &i, int *j, int k);
  void foo(int i) {  }
  void bar();
  void increment_k();
  int get_i();
  int get_k();
private:
  int k;
  int i;
};

int independentMethod(int &i);


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

  void Dump() {
    std::cout << "\nNodeId: " << GetId() << "Data: " << GetData();
  }

};

class BinaryTree {
  Node *Root;
  static int Counter;
  std::vector<Node> Tree;
public:

  BinaryTree()
    : Root (NULL)
  { }

  BinaryTree(Node *r)
    : Root (r) {
    Root->SetLeft(NULL);
    Root->SetRight(NULL);
    Root->SetId(0);
  }

  void BFS(Node *N, std::vector<Node *>& V) {
    std::queue<Node *> WL;
    std::set<Node *> Visited;
    WL.push(N);
    while (!WL.empty()) {
      Node *T = WL.front();
      WL.pop();
      Visited.insert(T);
      V.push_back(T);
      if (T->GetLeft() && !Visited.count(T->GetLeft()))
        WL.push(T->GetLeft());
      if (T->GetRight() && !Visited.count(T->GetRight()))
        WL.push(T->GetRight());
    }
  }

  bool InsertLeft(Node *R, int N) {
    Node T(N, Counter++);
    Tree.push_back(T);
    R->SetLeft(&Tree.back());
    return true;
  }

  bool InsertRight(Node *R, int N) {
    Node T(N, Counter++);
    Tree.push_back(T);
    R->SetRight(&Tree.back());
    return true;
  }

  bool Insert(Node *Root, int N) {
    if (Root->GetData() < N) {
      Node *R = Root->GetRight();
      if (R)
        return Insert(R, N);
      else
        return InsertRight(R, N);
    } else {
      Node *L = Root->GetLeft();
      if (L)
        return Insert(L, N);
      else
        return InsertLeft(L, N);
    }
  }

  bool Insert(int N) {
    if (!Root) {
      Node T(N, Counter++);
      Tree.push_back(T);
      return true;
    }
    return Insert (Root, N);
  }

  void BuildBinaryTree(std::vector<int> &V) {
    for (unsigned i = 0; i < V.size(); ++i)
      Insert(V[i]);
  }

  void Dump() {
    std::vector<Node *> V;
    BFS(Root, V);
    for (unsigned i = 0; i < V.size(); ++i)
      V[i]->Dump();
  }
};

#endif /* PROJECT1_H_ */
