#include "liststack.h"
#include "C:/Programming/lab_LinkedList/LinkedList.cpp"

ListStack::ListStack(const ListStack &copy) : LinkedList(copy) {}

void ListStack::push(const ValueType &value)
{
    this->pushBack(value);
}

void ListStack::pop()
{
    this->removeBack();
}

ValueType& ListStack::top()
{
    return this->LinkedList::getNode(size() - 1)->value;
}

const ValueType& ListStack::top() const
{
    return this->LinkedList::getNode(size() - 1)->value;
}

bool ListStack::isEmpty() const
{
    if (size() == 0)
        return true;
    else
        return false;
}

size_t ListStack::size() const
{
    return this->LinkedList::size();
}
