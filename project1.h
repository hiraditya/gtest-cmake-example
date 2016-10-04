#ifndef PROJECT1_H_
#define PROJECT1_H_

#include <iostream> // IO access
#include <vector>

class Project1 {

public:
  Project1(int i1=10000)
    : k(1000), i (i1), p(new int[10])
  { }

  ~Project1()
  { delete[] p; p = NULL; std::cout << "deleting Project1 with i = " << i << "\n"; }

  void foo(int &i);
  void increment_k();
  int get_i();
  int get_k();
private:
  int k;
  int i;
  int *p;
  std::vector<int> p_as_vec;
};

int independentMethod(int &i);

#endif /* PROJECT1_H_ */
