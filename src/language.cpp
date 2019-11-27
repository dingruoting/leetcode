//
// Created by ruoting on 2019/11/26.
//

#include "../include/language.h"

class Empty {
};

class Base {
public:
    virtual void Func() {
    }

    void Func2(int num_in) {
        num = num_in;
    }

    static void G_Func() { g_num = 10; }

    int num = 4;
    static long g_num;
};

class Kid1 : public Base {
};

class Kid2 : public Base {
public:
    void Func() override {
    }
};

void Language::Test() {
    std::cout << "sizeof(Empty) = " << sizeof(Empty) << std::endl;
    Base base;
    Kid1 kid1;
    Kid2 kid2;
    base.Func2(0x12345);
    std::cout << "sizeof(int) = " << sizeof(int) << std::endl;
    std::cout << "sizeof(long) = " << sizeof(long) << std::endl;
    std::cout << "sizeof(Base) = " << sizeof(Base) << std::endl;
    std::cout << "sizeof(void*) = " << sizeof(void *) << std::endl;
}