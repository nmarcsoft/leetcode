#include <functional>
#include <iostream>
#include <thread>
#include "Solution.hpp"

using namespace std;

void printFirst()
{
    std::cout << "first" << std::endl;
}

void printSecond()
{
    std::cout << "second" << std::endl;
}

void printThird()
{
    std::cout << "third" << std::endl;
}

int main(int argc, char * argv[])
{

    Foo foo;

    std::function<void()> function_one = printFirst;
    std::function<void()> function_second = printSecond;
    std::function<void()> function_third = printThird;

    thread t1(printFirst);
    thread t3(printThird);
    thread t2(printSecond);

    t1.join();
    t3.join();
    t2.join();

    return 0;
}
