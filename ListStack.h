#pragma once

#include "StackImplementation.h"
#include "LinkedList.h"

template <typename ValueType>
class ListStack : public StackImplementation<ValueType>, public LinkedList<ValueType>
{
public:
    ListStack() {};
    ListStack(const ListStack &copyList);
    void push(const ValueType &value) override;
    void pop() override;
    ValueType& top() override;
    const ValueType & top() const override;
    bool isEmpty() const override;
    size_t size() const override;

    ~ListStack(){};
};

template <typename ValueType>
ListStack<ValueType>::ListStack(const ListStack &copy) : LinkedList<ValueType>(copy) {}


template <typename ValueType>
void ListStack<ValueType>::push(const ValueType &value)
{
    this->pushFront(value);
}

template <typename ValueType>
void ListStack<ValueType>::pop()
{
    this->removeFront();
}

template <typename ValueType>
ValueType& ListStack<ValueType>::top()
{
    return (*this)[0];
}

template <typename ValueType>
const ValueType& ListStack<ValueType>::top() const
{
    return (*this)[0];
}

template <typename ValueType>
bool ListStack<ValueType>::isEmpty() const
{
    if (size() == 0)
        return true;
    else
        return false;
}

template <typename ValueType>
size_t ListStack<ValueType>::size() const
{
    return this->LinkedList<ValueType>::size();
}
