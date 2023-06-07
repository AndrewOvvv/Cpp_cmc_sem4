#include <cmath>
#include <iostream>
#include <ostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <memory>


namespace numbers 
{
class complex_stack {
private:
    size_t sz{};
    std::unique_ptr<complex[]> st;

    complex_stack(const complex_stack &old_stack, complex new_element) : 
        sz(old_stack.sz + 1),
        st(std::make_unique<complex[]>(sz))
    {
        std::copy(old_stack.st.get(), old_stack.st.get() + old_stack.sz, st.get());
        st[sz - 1] = new_element;
    }

    complex_stack(const complex_stack &old_stack, size_t sz_) :
        sz(sz_),
        st(std::make_unique<complex[]>(sz))
    {
        std::copy(old_stack.st.get(), old_stack.st.get() + sz_, st.get());
    }

public:
    complex_stack() : 
        sz(0), 
        st(std::make_unique<complex[]>(0))
    {}

    complex_stack(const complex_stack &old_stack) :
        sz(old_stack.sz),
        st(std::make_unique<complex[]>(sz))
    {    
        std::copy(old_stack.st.get(), old_stack.st.get() + sz, st.get());
    }

    complex_stack(complex_stack &&old_stack) :
        sz(old_stack.sz),
        st(std::move(old_stack.st))
    {
        old_stack.sz = 0;
    }


    size_t size() const {
        return sz;
    }

    complex_stack& operator= (const complex_stack &old_stack) {
        sz = old_stack.sz;
        st = std::make_unique<complex[]>(sz);
        std::copy(old_stack.st.get(), old_stack.st.get() + sz, st.get());
        return *this;
    }

    complex_stack& operator= (complex_stack &&old_stack) {
        sz = old_stack.sz;
        old_stack.sz = 0;
        st = std::move(old_stack.st);
        return *this;
    }

    complex operator[] (size_t index) const {
        return st[index];
    }

    complex_stack operator<< (complex new_element) const {
        return complex_stack(*this, new_element);
    }

    complex operator+ () const {
        return st[sz - 1];
    }

    complex_stack operator~ () const {
        return complex_stack(*this, sz - 1);
    }
};
}
