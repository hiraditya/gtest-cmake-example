#ifndef PROJECT1_H_
#define PROJECT1_H_

#include <iostream> // IO access

class Project1 {

public:
  Project1()
    : k(1000), i (0)
  { }

  void foo(int &i);
  void increment_k();
  int get_i();
  int get_k();
private:
  int k;
  int i;
};

int independentMethod(int &i);

#endif /* PROJECT1_H_ */