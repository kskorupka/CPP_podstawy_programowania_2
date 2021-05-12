#include <bitset>
#include <functional>
#include <iostream>

struct Base
{
    virtual ~Base()
    {
    }
};

struct Derived : Base
{
    virtual void name()
    {
        std::cout << "name()" << std::endl;
    }
};

int main()
{
    // 0. Solve the quiz
    // https: // www.geeksforgeeks.org/c-plus-plus-gq/exception-handling-gq/
    //done

    // 1. Handle standard exceptions
    try {
        int* myarray = new int[10000000000000L];
    }
    catch (std::bad_alloc) {
        std::cout << "Found bad allocation exception"<<std::endl;
    }

    // 2. Handle standard exceptions
    Base     b;
    try {
        Derived& f = dynamic_cast<Derived&>(b);
    }
    catch(std::bad_cast) {
        std::cout <<"Found bad cast exception"<< std::endl;
    }

    // 3. Handle standard exceptions
    try {
        std::function<int(int, int)> add = std::plus<int>();
        std::function<int(int, int)> add2;
        std::cout << add(10, 20) << '\n';
        std::cout << add2(10, 20) << '\n';
    }
    catch (std::bad_function_call) {
        std::cout << "Found bad function call exception" << std::endl;
    }
    // 4. Handle standard exceptions
    try {
        Base* base = 0;
        typeid(*base);
    }
    catch (std::bad_typeid) {
        std::cout << "Found bad typeid exception" << std::endl;
    }
    // 5. Handle standard exceptions
    try {
        std::bitset<128> x(1);
        std::cout << x.to_ulong() << std::endl;
        x.flip();
        std::cout << x.to_ulong() << std::endl;
    }
    catch (std::overflow_error) {
        std::cout << "Found overflow error exception" << std::endl;
    }

    // 6. Write a function: void division(int *num, int den)
    // write your own expection class(es) to handle two kinds of exceptions
    // throw when ptr is null or x == 0
    // provide and extra info about the exception (message, line, function name,
    // info) e.g throw myexception("msg", __FILE__, catch exceptions
}