#pragma once
#include "StackImplementation.h"
#include "C:/Programming/vector/vector.h" 

class VectorStack : public StackImplementation, public MyVector
{
public:
    VectorStack() { std::cout << "creating vector" << std::endl; }
    VectorStack(const VectorStack& copyVector);
    void push(const ValueType &value) override;
    void pop() override;
    ValueType & top() override;
    const ValueType & top() const override;
    bool isEmpty() const override;
    size_t size() const override;

    ~VectorStack(){ /*std::cout << "remove vector" << std::endl;*/ };
};
