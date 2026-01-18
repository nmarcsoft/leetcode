#pragma  once

#include <functional>
#include <atomic>
#include <thread>

using namespace std;

class Foo {
private:
    atomic<int> var;

public:
    Foo() {
        var = 0;
    }

    void first(function<void()> printFirst) {
        printFirst();
        var.store(1);

        // printFirst() outputs "first". Do not change or remove this line
    }

    void second(function<void()> printSecond) {
        while (var.load() != 1) { this_thread::yield(); }

        printSecond();
        var.store(2);
        // printSecond() outputs "second". Do not change or remove this line.

    }

    void third(function<void()> printThird) {
        while (var.load() != 2) { this_thread::yield(); }

        printThird();
        // printThird() outputs "third". Do not change or remove this line.

    }
};
