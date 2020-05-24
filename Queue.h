#include <iostream>
#include "listqueue.h"
#include "vectorqueue.h"
#include "doublelistqueue.h"
#include "QueueImplementation.h"

#pragma once

enum QueueContainer
{
    Vector = 0,
    SingleList,
    DoubleList,
};

//class QueueImplementation;

template <typename ValueType>
class Queue
{
public:
    Queue(QueueContainer container = QueueContainer::DoubleList);
    Queue(const ValueType *valueArray, const size_t arraySize,
          QueueContainer container = QueueContainer::DoubleList);
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
    case QueueContainer::SingleList: {
        _pimpl = new ListQueue<ValueType>();
        break;
    }
    case QueueContainer::Vector: {
        _pimpl = new VectorQueue<ValueType>();
        break;
    }
    case QueueContainer::DoubleList: {
        _pimpl = new DoubleListQueue<ValueType>();
        break;
    }
    default:
        throw std::runtime_error("Неизвестный тип контейнера!");
    }
  //  std::cout << this->size() << " size " << std::endl;
}

template <typename ValueType>
Queue<ValueType>::Queue(const ValueType* valueArray, const size_t arraySize, QueueContainer container)
    : _containerType(container)
{
    switch (container)
    {
    case QueueContainer::SingleList: {
        _pimpl = new ListQueue<ValueType>();
        break;
    }
    case QueueContainer::Vector: {
        _pimpl = new VectorQueue<ValueType>();
        break;
    }
    case QueueContainer::DoubleList: {
        _pimpl = new DoubleListQueue<ValueType>();
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
Queue<ValueType>::Queue(const Queue& copyQueue)
{
    _containerType = copyQueue._containerType;
    switch (_containerType)
    {
    case QueueContainer::SingleList: {
        _pimpl = new ListQueue<ValueType>(*(static_cast<ListQueue<ValueType>*>(copyQueue._pimpl)));	// конкретизируйте под ваши конструкторы, если надо
        break;
    }
    case QueueContainer::Vector: {
        _pimpl = new VectorQueue<ValueType>(*(static_cast<VectorQueue<ValueType>*>(copyQueue._pimpl)));	// конкретизируйте под ваши конструкторы, если надо
        break;
    }
    case QueueContainer::DoubleList: {
        _pimpl = new DoubleListQueue<ValueType>(*(static_cast<DoubleListQueue<ValueType>*>(copyQueue._pimpl)));
        break;
    }
    default:
        throw std::runtime_error("Неизвестный тип контейнера");
    }
}

template <typename ValueType>
Queue<ValueType>& Queue<ValueType>::operator=(const Queue& copyQueue)
{
    if (this == &copyQueue)
        return *this;
    _containerType = copyQueue._containerType;
    delete _pimpl;
    switch (_containerType)
    {
    case QueueContainer::SingleList: {
        _pimpl = new ListQueue<ValueType>(*(static_cast<ListQueue<ValueType>*>(copyQueue._pimpl)));	// конкретизируйте под ваши конструкторы, если надо
        break;
    }
    case QueueContainer::Vector: {
        _pimpl = new VectorQueue<ValueType>(*(static_cast<VectorQueue<ValueType>*>(copyQueue._pimpl)));	// конкретизируйте под ваши конструкторы, если надо
        break;
    }
    case QueueContainer::DoubleList: {
        _pimpl = new DoubleListQueue<ValueType>(*(static_cast<DoubleListQueue<ValueType>*>(copyQueue._pimpl)));
        break;
    }
    default:
        throw std::runtime_error("Неизвестный тип контейнера");
    }
    return *this;
}

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




