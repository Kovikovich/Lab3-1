#ifndef STACK_H
#define STACK_H

class Stack {
public:
    Stack(); 
    Stack(const Stack& other); 
    Stack& operator=(const Stack& other); 
    ~Stack(); 

    void push(int elem);
    int pop();
    void multiPop(int N);
    bool isEmpty() const;
    void show() const;

private:
    int* arr;
    int size;
    int top;
};

#endif