#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <string>

int main() {
    // subject example
    std::cout << "=== MutantStack ===" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }

    std::cout << "=== std::list ===" << std::endl;
    {
        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(17);
        std::cout << lst.back() << std::endl;
        lst.pop_back();
        std::cout << lst.size() << std::endl;
        lst.push_back(3);
        lst.push_back(5);
        lst.push_back(737);
        lst.push_back(0);
        std::list<int>::iterator it = lst.begin();
        std::list<int>::iterator ite = lst.end();
        ++it;
        --it;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
    }

    // const_iterator
    std::cout << "=== const_iterator ===" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(1);
        mstack.push(2);
        mstack.push(3);
        const MutantStack<int> cmstack(mstack);
        MutantStack<int>::const_iterator it = cmstack.begin();
        MutantStack<int>::const_iterator ite = cmstack.end();
        while (it != ite)
            std::cout << *it++ << std::endl;
    }

    // copy constructor and assignment operator
    std::cout << "=== copy ===" << std::endl;
    {
        MutantStack<int> a;
        a.push(10);
        a.push(20);
        MutantStack<int> b(a);
        MutantStack<int> c;
        c = a;
        std::cout << "original top: " << a.top() << std::endl;
        std::cout << "copy top:     " << b.top() << std::endl;
        std::cout << "assigned top: " << c.top() << std::endl;
    }

    // empty()
    std::cout << "=== empty ===" << std::endl;
    {
        MutantStack<int> mstack;
        std::cout << "empty: " << mstack.empty() << std::endl;
        mstack.push(42);
        std::cout << "empty: " << mstack.empty() << std::endl;
        mstack.pop();
        std::cout << "empty: " << mstack.empty() << std::endl;
    }

    // non-int type
    std::cout << "=== std::string ===" << std::endl;
    {
        MutantStack<std::string> mstack;
        mstack.push("hello");
        mstack.push("world");
        mstack.push("42");
        MutantStack<std::string>::iterator it = mstack.begin();
        while (it != mstack.end())
            std::cout << *it++ << std::endl;
    }

    return 0;
}
