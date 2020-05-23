#pragma once

#include "QueueImplementation.h"
#include "LinkedList.h"

template <typename ValueType>
class ListQueue : public QueueImplementation<ValueType>, public LinkedList<ValueType>
{
public:
    ListQueue(){};
    ListQueue(const ListQueue& copyList);
    void enqueue(const ValueType& value) override;
    void dequeue() override;
    ValueType& front() override;
    const ValueType& front() const override;
    bool isEmpty() const override;
    size_t size() const override;
    ~ListQueue(){};
};

template <typename ValueType>
ListQueue<ValueType>::ListQueue(const ListQueue& copy)
    :LinkedList<ValueType> (copy){}

template <typename ValueType>
void ListQueue<ValueType>::enqueue(const ValueType& value)
{
    this->pushBack(value);
}

template <typename ValueType>
void ListQueue<ValueType>::dequeue()
{
    this->removeFront();
}

template <typename ValueType>
ValueType& ListQueue<ValueType>::front()
{
    return (*this)[0];
}

template <typename ValueType>
const ValueType& ListQueue<ValueType>::front() const
{
    return (*this)[0];
}

template <typename ValueType>
bool ListQueue<ValueType>::isEmpty() const
{
    if (size() == 0)
        return true;
    else
        return false;
}

template <typename ValueType>
size_t ListQueue<ValueType>::size() const
{
    return this->LinkedList<ValueType>::size();
}

