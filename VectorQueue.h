#pragma once

#include "QueueImplementation.h"
#include "vector.h"

template <typename ValueType>
class VectorQueue : public QueueImplementation<ValueType>, public MyVector<ValueType>
{
public:
    VectorQueue(){}
    VectorQueue(const VectorQueue& copyVector);
    void enqueue(const ValueType& value) override;
    void dequeue() override;
    ValueType& front() override;
    const ValueType& front() const override;
    bool isEmpty() const override;
    size_t size() const override;
    ~VectorQueue(){}
};

template <typename ValueType>
VectorQueue<ValueType>::VectorQueue(const VectorQueue& copy)
    :MyVector<ValueType> (copy){}

template <typename ValueType>
void VectorQueue<ValueType>::enqueue(const ValueType& value)
{
    this->pushBack(value);
}

template <typename ValueType>
void VectorQueue<ValueType>::dequeue()
{
    this->erase(0);
}

template <typename ValueType>
ValueType& VectorQueue<ValueType>::front()
{
    return (*this)[0];
}

template <typename ValueType>
const ValueType& VectorQueue<ValueType>::front() const
{
    return (*this)[0];
}

template <typename ValueType>
bool VectorQueue<ValueType>::isEmpty() const
{
    if (size() == 0)
        return true;
    else
        return false;
}

template <typename ValueType>
size_t VectorQueue<ValueType>::size() const
{
    return this->MyVector<ValueType>::size();
}


