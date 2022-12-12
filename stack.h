#pragma once

#include <cstring>
#include <utility>

#define DEFAULT_SIZE 4

template<class T>
class Stack {
private:
    T* m_array = nullptr;
    unsigned int m_size = DEFAULT_SIZE;
    unsigned int m_top = 0;

    static void copyArray(T*, const T*, const unsigned int&);
    void autoAlloc();
    void autoDealloc();
public:
    Stack();

    Stack(const Stack&);
    Stack(Stack&&);
    Stack& operator=(const Stack&);
    Stack& operator=(Stack&&);

    void push(const T&);
    void pop();
    const T& getTop() const;
    bool isEmpty() const;
    const unsigned int& getSize() const;

    virtual ~Stack();
};
#include "stack.tpp"
