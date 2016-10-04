#ifndef PROJECT1_H_
#define PROJECT1_H_

#include <iostream> // IO access

class Project1 {

public:
  Project1(int i1=10000)
    : k(1000), i (i1)
  { }

/*  ~Project1()
  { delete[] p; p = NULL; std::cout << "deleting Project1 with i = " << i << "\n"; }
*/
  void foo(int &i);
  void increment_k();
  int get_i();
  int get_k();
private:
  int k;
  int i;
  std::vector<int> p;
};

int independentMethod(int &i);

#endif /* PROJECT1_H_ */