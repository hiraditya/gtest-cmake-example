
/*Types of errors:
1. Lexical error. (int i)
2. Syntactic error. (type mismatch etc)
3. Semantic errors. (using uninitialized variables, adding string to a number, unintended type conversion)
4. Logical error.*/

#include "project1.h"

void Project1::foo(int &i) {
	i = 1;
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
