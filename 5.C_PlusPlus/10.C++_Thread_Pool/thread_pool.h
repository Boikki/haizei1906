/*************************************************************************
	> File Name: thread_pool.h
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: Fri May  6 16:26:58 2022
 ************************************************************************/

#ifndef _THREAD_POOL_H
#define _THREAD_POOL_H
#include <iostream>
#include <algorithm>

namespace haizei {
class Task {
public :
    template<typename Func_T, typename ...ARGS>
    Task(Func_T f, ARGS ...args) {
        func = std::bind(f, std::forward<ARGS>(args)...);
    }
    void run() { func(); }

private :
    std::function<void()> func;
};
}
#endif
