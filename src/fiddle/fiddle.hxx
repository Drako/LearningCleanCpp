#pragma once

#ifndef FIDDLE_HXX
#define FIDDLE_HXX

int add(int a, int b);


struct Runnable {
    virtual ~Runnable() = default;

    virtual void run() = 0;
};

#endif // FIDDLE_HXX
