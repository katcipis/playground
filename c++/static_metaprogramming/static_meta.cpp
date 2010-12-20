#include <iostream>


template <class Derived>
class Base
{

public:
    void method()
    {
        static_cast<Derived*>(this)->method();
    }

};
 
class DerivedA : public Base<DerivedA>
{

public:
     void method() {
         std::cout << "method implementation of DerivedA" << std::endl;         
     }

};


class DerivedB : public Base<DerivedB>
{

public:
     void method() {
         std::cout << "method implementation of DerivedB" << std::endl;
     }

};


int main()
{
    Base<DerivedA> * pBaseA = new DerivedA();
    Base<DerivedB> * pBaseB = new DerivedB();

    pBaseA->method();
    pBaseB->method();

    delete pBaseA;
    delete pBaseB;
    return 0;
}
