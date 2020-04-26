#pragma once

#include "StackImplementation.h"

#include "C:/Programming/lab_LinkedList/LinkedList.h"

class ListStack : public StackImplementation, public LinkedList
{
public:
    ListStack() { std::cout << "creating list" << std::endl;};
    ListStack(const ListStack &copyList);
    void push(const ValueType &value) override;
    void pop() override;
    ValueType& top() override;
    const ValueType & top() const override;
    bool isEmpty() const override;
    size_t size() const override;

    ~ListStack(){ /*std::cout << "remove list" << std::endl; */};
};

