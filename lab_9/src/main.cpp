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
class Exception {
    const char* msg;
    int line;
    const char* fun_name;
    const char* file_name;
public:
    Exception() {};
    Exception(const char* _msg, int _line, const char* _fun_name, const char* _file_name) {
        msg = _msg;
        line = _line;
        fun_name = _fun_name;
        file_name = _file_name;
    }
    virtual ~Exception() = default;
    virtual void what()const=0;
    const char* get_msg() const { return msg; }
    int get_line() const { return line; }
    const char* get_fun_name() const { return fun_name; }
    const char* get_file_name()const { return file_name; }
    void set_msg(const char* s) { msg = s; }
    void set_line(int l) { line = l; }
    void set_fun_name(const char* f) { fun_name = f; }
    void set_file_name(const char* f) { file_name = f; }
};
class Division_by_zero : public Exception {
public:
    Division_by_zero() { this->set_msg("Division by zero"); };
    Division_by_zero(int _line, const char* _fun_name, const char* _file_name){
        this->set_msg("Division by zero");
        this->set_line(_line);
        this->set_fun_name(_fun_name);
        this->set_file_name(_file_name);
    }
    ~Division_by_zero() {};
    void what() const override {
        std::cout << "Program found an exception\n";
        std::cout << "What: "<<this->get_msg()<<std::endl;
        std::cout << "Which line: " << this->get_line() << std::endl;
        std::cout << "What function: " << this->get_fun_name() << std::endl;
        std::cout << "In file: " << this->get_file_name() << std::endl;
    }
};
class Null_ptr : public Exception {
public:
    Null_ptr() { this->set_msg("Null pointer"); };
    Null_ptr(int _line, const char* _fun_name, const char* _file_name){
        this->set_msg("Null pointer");
        this->set_line(_line);
        this->set_fun_name(_fun_name);
        this->set_file_name(_file_name);
    }
    ~Null_ptr() {};
    void what() const override {
        std::cout << "Program found an exception\n";
        std::cout << "What: " << this->get_msg() << std::endl;
        std::cout << "Which line: " << this->get_line() << std::endl;
        std::cout << "What function: " << this->get_fun_name() << std::endl;
        std::cout << "In file: " << this->get_file_name() << std::endl;
    }
};
float division(int* num, int den) {
    if (den == 0) throw Division_by_zero(__LINE__, __func__, __FILE__);
    if (num == 0) throw Null_ptr(__LINE__, __func__, __FILE__);
    int result = 0;
    result = (*num) / den;
    return result;
}
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
    //done

    // 2. Handle standard exceptions
    Base     b;
    try {
        Derived& f = dynamic_cast<Derived&>(b);
    }
    catch(std::bad_cast) {
        std::cout <<"Found bad cast exception"<< std::endl;
    }
    //done

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
    //done

    // 4. Handle standard exceptions
    try {
        Base* base = 0;
        typeid(*base);
    }
    catch (std::bad_typeid) {
        std::cout << "Found bad typeid exception" << std::endl;
    }
    //done

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
    //done

    // 6. Write a function: float division(int *num, int den)
    // write your own expection class(es) to handle two kinds of exceptions
    // throw when ptr is null or x == 0
    // provide and extra info about the exception (message, line, function name,
    // info) e.g throw myexception("msg", __FILE__, catch exceptions
    int a = 10, x = 0, d = 5, result;
    int* c = &a, *e = 0;
    try {
        result = division(c, x);
        std::cout << "Result: " << result << std::endl;
    }
    catch (Division_by_zero z) { z.what(); }
    catch (Null_ptr z) { z.what(); }
    std::cout<<std::endl;
    try {
        result = division(e, d);
        std::cout << "Result: " << result << std::endl;
    }
    catch (Division_by_zero z) { z.what(); }
    catch (Null_ptr z) { z.what(); }
    std::cout << std::endl;
    try {
        result = division(c, d);
        std::cout << "Result: " << result << std::endl;
    }
    catch (Division_by_zero z) { z.what(); }
    catch (Null_ptr z) { z.what(); }
    return 0;
}