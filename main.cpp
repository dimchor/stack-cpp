#include <iostream>

#include "stack.h"

int main(void) {
    Stack<unsigned int> stack;

    for (unsigned int i = 0; i < 20; i++) {
        stack.push(i);
        std::cout << "Item: " << stack.getTop() << " Size: " << stack.getSize() << '\n';
    }

    for (unsigned int i = 0; i < 10; i++) {
        std::cout << "Item: " << stack.getTop() << " Size: " << stack.getSize() << '\n';
        stack.pop();
    }

    for (unsigned int i = 0; i < 30; i++) {
        stack.push(i);
        std::cout << "Item: " << stack.getTop() << " Size: " << stack.getSize() << '\n';
    }

    while (!stack.isEmpty()) {
        stack.pop();
    }
    
    std::cout << stack.getSize() << '\n';

    return 0;
}
