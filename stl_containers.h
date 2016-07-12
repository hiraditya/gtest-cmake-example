#ifndef STL_CONTAINERS
#define STL_CONTAINERS

#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <deque>
#include <iterator>
#include <algorithm>

bool iseven(int n) {
  return n%2 == 0;
}

template<typename T>
void learn_algorithms() {
  std::vector<T> v;
  for (int i = 0; i< 10; ++i)
    v.push_back(i+10);

  std::vector<T> v2(v.size());

  std::copy(v.begin(), v.end(), v2.begin());

  std::cout << "Copying all elements to std::cout" << std::endl;
  std::copy(v2.begin(), v2.end(), std::ostream_iterator<T>(std::cout, "\n"));

  std::cout << "Copying all odd elements to std::cout" << std::endl;
  std::copy_if(v2.begin(), v2.end(), std::ostream_iterator<T>(std::cout, "\n"),
               [](int n){ return n%2 != 0; });

  std::cout << "Copying all even elements to std::cout" << std::endl;
  std::copy_if(v2.begin(), v2.end(), std::ostream_iterator<T>(std::cout, "\n"),
               iseven);
}

template<typename T>
void learn_containers() {
  std::vector<T> v;
  for (int i = 0; i< 10; ++i)
    v.push_back(i+10);

  std::cout << *std::next(v.begin(), 5) << std::endl;

  std::list<T> l;
  for (int i = 0; i< 10; ++i)
    l.push_back(i+10);

  std::cout << *std::next(l.begin(), 5) << std::endl;

  std::deque<T> dq;
  for (int i = 0; i< 10; ++i)
    dq.push_back(i+10);

  std::cout << *std::next(dq.begin(), 5) << std::endl;
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

void stl_container_algo() {
  learn_containers<foo>();
  learn_containers<char>();
  learn_containers<float>();
  learn_containers<int>();
  learn_algorithms<int>();
}

#endif // STL_CONTAINERS

