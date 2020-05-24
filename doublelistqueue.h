#pragma once

#include "QueueImplementation.h"
#include "List.h"

template <typename ValueType>
class DoubleListQueue : public QueueImplementation<ValueType>, public List<ValueType>
{
public:
    DoubleListQueue(){}
    DoubleListQueue(const DoubleListQueue& copyList);
    void enqueue(const ValueType& value) override;
    void dequeue() override;
    ValueType& front() override;
    const ValueType& front() const override;
    bool isEmpty() const override;
    size_t size() const override;
    ~DoubleListQueue(){}
};

template <typename ValueType>
DoubleListQueue<ValueType>::DoubleListQueue(const DoubleListQueue& copy)
    :List<ValueType> (copy){}

template <typename ValueType>
void DoubleListQueue<ValueType>::enqueue(const ValueType& value)
{
    this->pushBack(value);
}

template <typename ValueType>
void DoubleListQueue<ValueType>::dequeue()
{
    this->removeFront();
}

template <typename ValueType>
ValueType& DoubleListQueue<ValueType>::front()
{
    return (*this)[0];
}

template <typename ValueType>
const ValueType& DoubleListQueue<ValueType>::front() const
{
    return (*this)[0];
}

template <typename ValueType>
bool DoubleListQueue<ValueType>::isEmpty() const
{
    if (size() == 0)
        return true;
    else
        return false;
}

template <typename ValueType>
size_t DoubleListQueue<ValueType>::size() const
{
    return this->List<ValueType>::size();
}

