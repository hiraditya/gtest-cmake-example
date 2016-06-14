
/*Types of errors:
1. Lexical error. (itn i)
2. Syntactic error. (type mismatch etc)
3. Semantic errors.
4. Logical error.*/

/*
bool (*cmpp)(int i, int j);

bool cmp(int i, int j) {
  return i >= j;
}

bool cmp2(int i, int j) {
  return i >= j;
}

void sort1() {
  std::vector<int> v;
  cmpp = cmp;
  std::sort(v.begin(), v.end(), cmp);
}*/


#include "project1.h"

void Project1::foo(int &i, int *j, int k) {
	i = 1;
  *j = 101;
  k = 1000;
}

void Project1::bar()
{
  int i = 10;
  int j = 100;
  int k = 1000;
  int *l = &i;
  int &m = i;
  int *a = &m;
  *a = 10;
  std::cout << "\ni=" << i << "\tm=" <<  m;
  foo (m, &j, k);
  std::cout << "\ni=" << i;
  std::cout << "\nj=" << j;
  std::cout << "\nk=" << k;
}

void Project1::increment_k() {
  k = k + 1;
}

int Project1::get_k()
{
  return k;
}

int Project1::get_i()
{
  return i;
}

int independentMethod(int &i) {
  i = 0;
  return i+ 100;
}

int BinaryTree::Counter = 0;
