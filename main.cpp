#include <iostream>
#include "project1.h"

using namespace std;

void foo(Project1 *p) {

}

int main() {
	cout << "do stuff" << endl;
	int x = 4;
	cout << x << endl;
	independentMethod(x);
  //   0xAAAAAA     k
  //   0xAAAAAA+4   i 

	Project1 p;
        cout << "\nValue of i = " << p.get_i() << '\n';
        cout << "\nValue of k = " << p.get_k() << '\n';
	//p.foo(x);
	foo(&p);
  p.bar();
  p.increment_k();
}

