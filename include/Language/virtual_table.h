//
// Created by ruoting on 2019/11/28.
//

#ifndef CODING_VIRTUAL_TABLE_H
#define CODING_VIRTUAL_TABLE_H

#include <iostream>

namespace virtual_table {
    class Empty {
    };

    class Base {
    public:
        virtual void Func() {}
    };

    class Base2 {
        virtual void Func2() {}
    };

    class Kid : public Base, public Base2 {
        virtual void SelfFunc() {}
    };

    void Test() {
        std::cout << "sizeof(Empty) = " << sizeof(Empty) << std::endl;
        Base base;
        std::cout << "sizeof(Base) = " << sizeof(Base) << std::endl;
        std::cout << "sizeof(void*) = " << sizeof(void *) << std::endl;
        Kid obj;
        std::cout << "sizeof(Kid) = " << sizeof(Kid) << std::endl;
    };
}
#endif //CODING_VIRTUAL_TABLE_H
