#include <iostream>
#include "listqueue.h"
#include "vectorqueue.h"
#include "QueueImplementation.h"

#pragma once

enum QueueContainer
{
    Vector = 0,
    List,
};

template <typename ValueType>
class Queue
{
public:
    Queue(QueueContainer container = QueueContainer::List);
    Queue(const ValueType *valueArray, const size_t arraySize,
          QueueContainer container = QueueContainer::List);
    explicit Queue(const Queue& copyQueue);
    Queue& operator=(const Queue& copyQueue);

    ~Queue();

    void enqueue(const ValueType& value);
    void dequeue();
    ValueType& front();
    const ValueType& front() const;
    bool isEmpty();
    size_t size();
private:
    QueueImplementation<ValueType>* _pimpl = nullptr;
    QueueContainer _containerType;
};

template <typename ValueType>
Queue<ValueType>::Queue(QueueContainer container)
    : _containerType(container)
{
    switch (container)
    {
    case QueueContainer::List: {
        _pimpl = new ListQueue<ValueType>();
        break;
    }
    case QueueContainer::Vector: {
        _pimpl = new VectorQueue<ValueType>();
        break;
    }
    default:
        throw std::runtime_error("Неизвестный тип контейнера");
    }
  //  std::cout << this->size() << " size " << std::endl;
}

template <typename ValueType>
Queue<ValueType>::Queue(const ValueType* valueArray, const size_t arraySize, QueueContainer container)
    : _containerType(container)
{
    switch (container)
    {
    case QueueContainer::List: {
        _pimpl = new ListQueue<ValueType>();
        break;
    }
    case QueueContainer::Vector: {
        _pimpl = new VectorQueue<ValueType>();
        break;
    }
    default:
        throw std::runtime_error("Неизвестный тип контейнера");
    }
    for (size_t i = 0; i < arraySize; i++)
    {
        this->enqueue(valueArray[i]);
    }
}

template <typename ValueType>
Queue<ValueType>::Queue(const Queue& copyStack)
{
    _containerType = copyStack._containerType;
    switch (_containerType)
    {
    case QueueContainer::List: {
        _pimpl = new ListQueue<ValueType>(*(static_cast<ListQueue<ValueType>*>(copyStack._pimpl)));	// конкретизируйте под ваши конструкторы, если надо
        break;
    }
    case QueueContainer::Vector: {
        _pimpl = new VectorQueue<ValueType>(*(static_cast<VectorQueue<ValueType>*>(copyStack._pimpl)));	// конкретизируйте под ваши конструкторы, если надо
        break;
    }
    default:
        throw std::runtime_error("Неизвестный тип контейнера");
    }
}

template <typename ValueType>
Queue<ValueType>& Queue<ValueType>::operator=(const Queue& copyStack)
{
    if (this == &copyStack)
        return *this;
    _containerType = copyStack._containerType;
    delete _pimpl;
    switch (_containerType)
    {
    case QueueContainer::List: {
        _pimpl = new ListQueue<ValueType>(*(static_cast<ListQueue<ValueType>*>(copyStack._pimpl)));	// конкретизируйте под ваши конструкторы, если надо
        break;
    }
    case QueueContainer::Vector: {
        _pimpl = new VectorQueue<ValueType>(*(static_cast<VectorQueue<ValueType>*>(copyStack._pimpl)));	// конкретизируйте под ваши конструкторы, если надо
        break;
    }
    default:
        throw std::runtime_error("Неизвестный тип контейнера");
    }
    return *this;
}

//template <typename ValueType>
//Queue<ValueType>::Queue(Stack&& moveStack) noexcept
//{
//    _containerType = moveStack._containerType;
//    delete _pimpl;
//    _pimpl = moveStack._pimpl;

//    moveStack._pimpl = nullptr;
//}

//template <typename ValueType>
//Stack<ValueType>& Stack<ValueType>::operator=(Stack &&moveStack) noexcept
//{
//    if (this == &moveStack)
//    {
//        return *this;
//    }
//    delete _pimpl;
//    _containerType = moveStack._containerType;
//    _pimpl = moveStack._pimpl;

//    moveStack._pimpl = nullptr;

//    return *this;
//}

template <typename ValueType>
Queue<ValueType>::~Queue()
{
    delete _pimpl;		// композиция!
}

template <typename ValueType>
void Queue<ValueType>::enqueue(const ValueType& value)
{
    _pimpl->enqueue(value);
}

template <typename ValueType>
void Queue<ValueType>::dequeue()
{
    _pimpl->dequeue();
}

template <typename ValueType>
ValueType& Queue<ValueType>::front()
{
    return _pimpl->front();
}

template <typename ValueType>
const ValueType& Queue<ValueType>::front() const
{
    return _pimpl->front();
}

template <typename ValueType>
bool Queue<ValueType>::isEmpty()
{
    return _pimpl->isEmpty();
}

template <typename ValueType>
size_t Queue<ValueType>::size()
{
    return _pimpl->size();
}




