#include "project1.h"

void Project1::foo(int &i) {
	i = 1;
}


int independentMethod(int &i) {
	i = 0;
  return i+ 100;
}