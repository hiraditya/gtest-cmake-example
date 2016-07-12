#ifndef STL_CONTAINERS
#define STL_CONTAINERS

#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <deque>

template<typename T>
void use_vector() {
  std::vector<T> v;
  for (int i = 0; i< 10; ++i)
    v.push_back(i+10);

  std::cout << *std::next(v.begin(), 5);

  std::list<T> l;
  for (int i = 0; i< 10; ++i)
    l.push_back(i+10);

  std::cout << *std::next(l.begin(), 5);

  std::deque<T> dq;
  for (int i = 0; i< 10; ++i)
    dq.push_back(i+10);

  std::cout << *std::next(dq.begin(), 5);
}

class foo {
  int i;
public:
  foo(int i) : i(i) {}
  friend std::ostream& operator<<(std::ostream &os, foo&f) {
    os<< f.i;
    return os;
  }
};

void bar() {
  use_vector<foo>();
  use_vector<char>();
  use_vector<float>();
  use_vector<double>();
}

#endif // STL_CONTAINERS

