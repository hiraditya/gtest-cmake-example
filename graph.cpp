/**
 * Basic graph implementation
*/

#include "graph.h"

#include <iostream>
#include <queue>
#include <set>
#include <vector>

void Node::Dump(std::ostream &os) {
  os << "\nNodeId: " << GetId()
     << ", Data: " << GetData();
}

void Node::DumpGV() {
  if (GetLeft()) {
    std::cout << "\nnode" << GetId();    
    std::cout <<  ":left -> node" << GetLeft()->GetId();
  }
  if (GetRight()) {
    std::cout << "\nnode" << GetId();    
    std::cout <<  ":right -> node" << GetRight()->GetId();
  }
}

void BinaryTree::BFS(Node *N, std::vector<Node *> &V) {
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

bool BinaryTree::InsertLeft(Node *R, int N) {
  Node T(N, Counter++);
  Tree.push_back(T);
  R->SetLeft(&Tree.back());
  std::cout << "\n" << Tree.back().GetId() << "->" << R->GetId();
  return true;
}

bool BinaryTree::InsertRight(Node *R, int N) {
  Node T(N, Counter++);
  Tree.push_back(T);
  R->SetRight(&Tree.back());
  std::cout << "\n" << R->GetId() << "->" << Tree.back().GetId();
  return true;
}

bool BinaryTree::Insert(Node *Root, int N) {
  if (Root->GetData() < N) {
    Node *R = Root->GetRight();
    if (R)
      return Insert(R, N);
    else
      return InsertRight(Root, N);
  } else {
    Node *L = Root->GetLeft();
    if (L)
      return Insert(L, N);
    else
      return InsertLeft(Root, N);
  }
}

bool BinaryTree::Insert(int N) {
  if (!Root) {
    Node T(N, Counter++);
    Tree.push_back(T);
    Root = &Tree.back();
    return true;
  }
  return Insert (Root, N);
}

void BinaryTree::BuildBinaryTree(std::vector<int> &V) {
  for (unsigned i = 0; i < V.size(); ++i)
    Insert(V[i]);
}

void BinaryTree::Dump() {
  std::vector<Node *> V;
  BFS(Root, V);
  std::cout << "\ndigraph g {\nnode[shape=record]";
  for (unsigned i = 0; i < V.size(); ++i)
    std::cout << "\nnode"
              << V[i]->GetId() << "[label=\""
              <<"{"
              << V[i]->GetData()
              << "|{<left>|<right>}}\"]";

  std::cout << "\n\n";
  for (unsigned i = 0; i < V.size(); ++i)
    V[i]->DumpGV();
  std::cout << "\n}\n";
}

int BinaryTree::Counter = 0;
