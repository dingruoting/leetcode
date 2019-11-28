//
// Created by ruoting on 2019/11/28.
//

#ifndef CODING_COROUTINE_JMP_H
#define CODING_COROUTINE_JMP_H

#include <setjmp.h>
#include <iostream>

namespace coroutine {
    // 用于保存恢复调用环境所需的信息
    jmp_buf buf;

    void Func1() {
        std::cout << "in Func1" << std::endl;
//      longjmp 恢复env所指的缓冲区中的程序调用环境上下文 使用后，buf的内容会被销毁
//      如果setjmp所在的函数已经调用返回了，
//      那么longjmp使用该处setjmp所填写的对应jmp_buf缓冲区将不再有效。
//      这是因为longjmp所要返回的"栈帧"(stack frame)已经不再存在了，
//      程序返回到一个不再存在的执行点，很可能覆盖或者弄坏程序栈
        longjmp(buf, 1);
        std::cout << "never happened!" << std::endl;
    }

    void Test() {
        int num = 1234;
//      setjmp 建立本地的jmp_buf缓冲区并且初始化，用于将来跳转回此处
//      如果是从setjmp直接调用返回，setjmp返回值为0。
//      如果是从longjmp恢复的程序调用环境返回，setjmp返回非零值。
        if (setjmp(buf)) {
            std::cout << "back to main process,num is " << num << std::endl;
        } else {
            Func1();
        }
    }
}
#endif //CODING_COROUTINE_JMP_H
