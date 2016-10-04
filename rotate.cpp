#include "graph.h"
#include "stl_containers.h"
#include <algorithm>
#include <vector>

template <typename T> void printVector(std::vector<T> &V) {
  std::for_each(V.begin(), V.end(), [](const T &t) { std::cout << t << " "; });
}

struct RAI_TAG {};

class RAI {
private:
  operator+();

public:
  typedef RAI_TAG tag_type;
};

template <typename T> class Vec {
public:
  typedef std::forward_iterator iterator;
  iterator begin() { root; }
  iterator end() { root + N; }
};

template <typename RAI> void __rotate(RAI b, RAI e, RAI p, RAI_TAG t) {}

template <typename T> void rotate(T b, T e, T p) {
  return __rotate(b, e, p, I::tag_type);
}

void testAlgorithm(std::vector<int> &V1) {
  std::rotate(V1.begin(), V1.begin() + 4, V1.end());
}

int main(int argc, char *argv[]) {
  std::vector<int> V1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  std::cout << "\nV1:";
  printVector(V1);
  testAlgorithm(V1);
  std::cout << "\nV1:";
  printVector(V1);
  std::cout << std::endl;
  return 0;
}
