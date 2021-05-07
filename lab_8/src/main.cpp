#include <vector>
#include <iostream>

struct B {
    int m = 0;
    void hello() const {
        std::cout << "Hello world, this is B!\n";
    }
};
struct D : B {
    void hello() const {
        std::cout << "Hello world, this is D!\n";
    }
};

enum class E { ONE = 1, TWO, THREE };

struct Base {
    virtual ~Base() {}
};

struct Derived : Base {
    virtual void name() {}
};

using namespace std;

class type
{
private:
    int att;
public:
    type(int t) :att(t) {}

    // A const function that changes atribute with the help of const_cast
    void fun() const
    {
        // att = 5;
    }

    int getAtt() { return att; }
};

int fun(int* ptr)
{
    *ptr = *ptr + 10;
    return (*ptr);
}

int main()
{
    // 1.1: initializing conversion - convert float 3.14 to int n and print n
    // int n = ;
    // std::cout << "n = " << n << '\n';
    int n = static_cast <int> (3.14);
    cout << n << '\n';

    // 1.2 initializing conversion - init 10 element vector using implicit conversion sequence and pring vector v size
    // std::vector<int> v = ;
    // std::cout << "v.size() = " << v.size() << '\n';
    std::vector<int> v = static_cast<vector<int>>(10);
    std::cout << "v.size() = " << v.size() << '\n';
    // 2.1: static downcast - upcast via implicit conversion and call hello()
    D d;
    //static_cast<B>(d).hello();
    // B& br = ;
    B& br = static_cast<B&>(d);
    br.hello();
    // 2.2 downcast br to D and call hello()
    // D& another_d = ;
    // another_d.hello();
    D& another_d = static_cast<D&>(br);
    another_d.hello();
    // 3: lvalue to xvalue - convert vector v from 1 to rvalue reference and print vector v size
    // std::vector<int> v2 = ;
    // std::cout << "after move, v.size() = " << v.size() << '\n';
    vector<int>v2 = static_cast<vector<int>&&>(v);
    cout << "after move, v.size() = " << v.size() << '\n';
    
    // 4: discarded-value expression - use static_cast in this context
    // e.g. 2 * 2;
    static_cast<void>(2 * 2);
    // 5. inverse of implicit conversion - perform inverse conversion of nv using static_cast
    // void* nv = &n; // implicit inversion
    // int* ni = ;
    // std::cout << "*ni = " << *ni << '\n';
    void* nv = &n;
    int* ni = static_cast<int*>(nv);
    std::cout << "*ni = " << *ni << '\n';
    // 6. array-to-pointer followed by upcast
    D a[10];
    // B* dp = ;
    B* dp = static_cast<B*>(a);
    a[0].hello();
    //dp->hello();
    dp++;
    dp->hello();
    // 7. scoped enum to int or float
    E e = E::ONE;
    // int one = ;
    // std::cout << one << '\n';
    int one = static_cast<int>(e);
    cout << one << '\n';
    // 8. void* to any type - voidp to p
    void* voidp = &e;
    // std::vector<int>* p = ;
    vector<int>* p = static_cast<vector<int>*>(voidp);
    // D d; // the most derived object
    // A& a = d; // upcast, dynamic_cast may be used, but unnecessary
    // D& new_d = dynamic_cast<D&>(a); // downcast
    // B& new_b = dynamic_cast<B&>(a); // sidecast

    Base* b1 = new Base;
    // 9. Perform safe call of d->name() - convert b1 to d
    // Derived* d = ;
    // check pointer
    // d->name(); // safe to call
    //Derived* d1 = dynamic_cast<Derived*>(&(*b1));
    //d1->name();
    // 10. Perform safe call of d->name() - convert b2 to d
    Base* b2 = new Derived;
    // Derived* d = ;
    // check pointer
    // d->name(); // safe to call
    Derived* d2 = dynamic_cast<Derived*>(b2);
    d2->name();
    //d2->name();
    delete b1;
    delete b2;
    // 11. Modify att in t
    type t(3);
    //for(type i: t)
    cout << "Old att: " << t.getAtt() << endl;
    // t.fun();
    cout << "New att: " << t.getAtt() << endl;

    // 12. Fix an error, uncomment fun(ptr)
    int val = 10;
    const int* ptr = &val;
    // fun(ptr);
    cout << val;

}