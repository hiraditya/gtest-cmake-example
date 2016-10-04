#include <iostream>
#include "project1.h"

using namespace std;

void foo(Project1 *p) {

}

int main() {
	cout << "do stuff" << endl;
	int x = 4;
  cout << "\nValue of x = " << x << '\n';
	independentMethod(x);
  //   0xAAAAAA     k
  //   0xAAAAAA+4   i

  Project1 p(0);
  cout << "\nValue of i = " << p.get_i() << '\n';
  cout << "\nValue of k = " << p.get_k() << '\n';
  p.foo(x);
  cout << "\nValue of x = " << x << '\n';
  foo(&p);
  p.increment_k();
  std::cout << "Last statement\n";


  int *p = (int* ) malloc (sizeof(int) *10);
  int *q = (int* ) malloc (sizeof(int) *10);
  if (p) {
    // dakjhfakdshf
  } else {
    return -1;
  }
  if (q) {
    // dakjhfakdshf
  } else {
    free(p);
    return -2; // error report
  }
  free(p);
  free(q);
}

