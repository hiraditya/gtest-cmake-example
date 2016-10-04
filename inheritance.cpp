#include<iostream>

class Vehicle {

public:  
  virtual unsigned NumTyres() { return 0; }
  virtual ~Vehicle() {}
};

// public: is-a relationship => inheritence
// protected+private: is implemented in terms of 
class Car : public Vehicle {
public:
  virtual unsigned NumTyres() { return 4 ; }
};

int main() {
  std::cout << "Size of Base: " << sizeof(Vehicle) << std::endl;
  std::cout << "Size of Derived: " << sizeof(Car) << std::endl;
  Vehicle *V = new Car;
  std::cout << "Tyres: " << V->NumTyres()  << std::endl;
  delete V;
  return 0;
}
