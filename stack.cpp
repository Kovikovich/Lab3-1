#include "stack.h"
#include <iostream>

Stack::Stack() : arr(new int[10]), size(10), top(-1) {}

Stack::Stack(const Stack& other) : arr(new int[other.size]), size(other.size), top(other.top) {
    std::copy(other.arr, other.arr + size, arr);
}

Stack& Stack::operator=(const Stack& other) {
    if (this != &other) {
        int* newArr = new int[other.size];
        std::copy(other.arr, other.arr + other.size, newArr);
        delete[] arr;
        arr = newArr;
        size = other.size;
        top = other.top;
    }
    return *this;
}

Stack::~Stack() {
    delete[] arr;
}

void Stack::push(int elem) {
    if (top == size - 1) { 
        int* temp = new int[size * 2];
        std::copy(arr, arr + size, temp);
        delete[] arr;
        arr = temp;
        size *= 2;
    }
    arr[++top] = elem;
}

int Stack::pop() {
    if (top == -1) {
        std::cerr << "Error: Your stack is empty\n";
        return -1;
    }
    return arr[top--];
}

void Stack::multiPop(int N) {
    while (N > 0 && !isEmpty()) {
        pop();
        N--;
    }
}

bool Stack::isEmpty() const {
    return top == -1;
}

void Stack::show() const {
    for (int i = 0; i <= top; i++) {
        if (i == top) {
            std::cout << arr[i];
        } else {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
}
