#include <iostream>

class Vehicle {
  /* c++ ../inheritance.cpp -fdump-class-hierarchy
  The entries for virtual destructors are actually pairs of entries. The first
  destructor, called the complete object destructor, performs the destruction
  without calling delete() on the object. The second destructor, called the
  deleting destructor, calls delete() after destroying the object. Both destroy
  any virtual bases; a separate, non-virtual function, called the base object
  destructor, performs destruction of the object but not its virtual base
  subobjects, and does not call delete().

  Vtable for Vehicle
  Vehicle::_ZTV7Vehicle: 6u entries
  0     (int (*)(...))0
  8     (int (*)(...))(& _ZTI7Vehicle)
  16    (int (*)(...))Vehicle::NumTyres
  24    (int (*)(...))Vehicle::Engine
  32    (int (*)(...))Vehicle::~Vehicle
  40    (int (*)(...))Vehicle::~Vehicle

  Class Vehicle
     size=8 align=8
     base size=8 base align=8
  Vehicle (0x0x7f4278818d80) 0 nearly-empty
      vptr=((& Vehicle::_ZTV7Vehicle) + 16u)*/

public:
  /* How inheritance works using function pointer.*/
  typedef unsigned (Vehicle::*pNumTyresT)();
  pNumTyresT pNumTyres;
  Vehicle() { pNumTyres = &Vehicle::NumTyres; }

  unsigned CallNumTyres() { return (this->*pNumTyres)(); }

  virtual unsigned NumTyres() { return 0; }
  virtual unsigned Engine() { return 0; }
  virtual ~Vehicle() {}
};

// public: is-a relationship => inheritence
// protected+private: is implemented in terms of
class Car : public Vehicle {
  /* Vtable for Car
  Car::_ZTV3Car: 6u entries
  0     (int (*)(...))0
  8     (int (*)(...))(& _ZTI3Car)
  16    (int (*)(...))Car::NumTyres
  24    (int (*)(...))Car::Engine
  32    (int (*)(...))Car::~Car
  40    (int (*)(...))Car::~Car

  Class Car
     size=8 align=8
     base size=8 base align=8
  Car (0x0x7f42786722d8) 0 nearly-empty
      vptr=((& Car::_ZTV3Car) + 16u)
    Vehicle (0x0x7f4278818de0) 0 nearly-empty
        primary-for Car (0x0x7f42786722d8)*/

public:
  // http://stackoverflow.com/questions/4272909/is-it-safe-to-upcast-a-method-pointer-and-use-it-with-base-class-pointer/
  Car() { pNumTyres = static_cast<Vehicle::pNumTyresT>(&Car::NumTyres); }

  virtual unsigned NumTyres() { return 4; }
  virtual unsigned Engine() { return 1; }
};

int main() {
  std::cout << "Size of Base: " << sizeof(Vehicle) << std::endl;
  std::cout << "Size of Derived: " << sizeof(Car) << std::endl;
  // This is only for illustration purpose, writing naked new-delete
  // is not a good programming practice.
  Vehicle *V = new Car;
  // Dynamic dispatch facilitates calling of the appropriate function.
  std::cout << "Tyres: " << V->NumTyres() << std::endl;
  std::cout << "Tyres (using fptr): " << V->CallNumTyres() << std::endl;
  delete V;
  return 0;
}
