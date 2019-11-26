//
// Created by ruoting on 2019/11/26.
//

#include "../include/language.h"

class Empty {

};

class HasVirtualFunc {
public:
    virtual void Func1() {}
};

class VirtualParent : public virtual Empty {

};

class VirtualParent2 : public virtual Empty {

};

class VirtualParent3 : public VirtualParent, public VirtualParent2 {

};

void Language::Test() {
    std::cout << "start language test" << std::endl;
    std::cout << "sizeof(Empty) = " << sizeof(Empty) << std::endl;
    std::cout << "sizeof(HasVirtualFunc) = " << sizeof(HasVirtualFunc) << std::endl;
    std::cout << "sizeof(void*) = " << sizeof(void *) << std::endl;
    std::cout << "sizeof(VirtualParent) = " << sizeof(VirtualParent) << std::endl;
    std::cout << "sizeof(VirtualParent3) = " << sizeof(VirtualParent3) << std::endl;
}