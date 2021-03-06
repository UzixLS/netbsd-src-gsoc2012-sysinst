// { dg-do assemble  }
// Error: Internal Compiler Error in GCC 2.7.2 and EGCS 1998/05/28 snapshot.

#include <iostream>

class some_base
        {
public:
        class base_func_args;
        virtual void func(base_func_args &) = 0; // { dg-error "" } referenced below
        };

class some_base::base_func_args
        {
public:
        int i;
        };

class some_derived : public some_base
        {  // { dg-error "" } note
public:
        class derived_func_args;
        void func(derived_func_args &);
        };


class derived_func_args : public some_base::base_func_args
        {
public:
        float f;
        };

class some_derived::func(derived_func_args &a)  // { dg-error "" } illegal member syntax
        {
        std::cout << a.i << ' ' << a.f << std::endl;
        }

int
main()
        {
	some_derived d;                     // { dg-error "" } abstract class
        some_derived::derived_func_args dfa; // { dg-error "" } incomplete class
        some_base *b = &d;

        dfa.i = 10;
        dfa.f = 20;
        b->func(dfs);                       // { dg-error "" } dfs not declared
        return 0;
        }
