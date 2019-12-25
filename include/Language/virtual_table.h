//
// Created by ruoting on 2019/11/28.
//

#ifndef CODING_VIRTUAL_TABLE_H
#define CODING_VIRTUAL_TABLE_H

#include <iostream>

namespace virtual_table {
class Empty {
};

class Parent {
 public:
  virtual void Func() {}
};

class Base2 {
  virtual void Func2() {}
};
class Kid1 : public Parent {

};
class Kid : public Parent, public Base2 {
  virtual void SelfFunc() {}
};

void Test() {
  std::cout << "sizeof(Empty) = " << sizeof(Empty) << std::endl;
  Parent base;
  std::cout << "sizeof(Base) = " << sizeof(Parent) << std::endl;
  std::cout << "sizeof(void*) = " << sizeof(void *) << std::endl;
  Kid obj;
  Kid1 kid1,kid2;
  std::cout << "sizeof(Kid) = " << sizeof(Kid) << std::endl;
};
}
#endif //CODING_VIRTUAL_TABLE_H
