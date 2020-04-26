#include "vectorstack.h"
#include "C:/Programming/vector/vector.cpp"

VectorStack::VectorStack(const VectorStack &copy) : MyVector(copy)
{}

 void VectorStack::push(const ValueType &value)
 {
     //std::cout << this->MyVector::size() << "push " << std::endl;
     this->pushBack(value);
 }

 void VectorStack::pop()
 {
     this->popBack();
 }

 ValueType& VectorStack::top()
 {
     //std::cout << this->MyVector::size() << " top " << this->size() << std::endl;
     return operator[](this->MyVector::size() - 1);
 }

 const ValueType& VectorStack::top() const
 {
     //std::cout << this->MyVector::size() << std::endl;
     return operator[](this->MyVector::size() - 1);
 }

 bool VectorStack::isEmpty() const
 {
     if (size() == 0)
         return true;
     else
         return false;
 }

 size_t VectorStack::size() const
 {
     //std::cout << this->MyVector::size() << std::endl;
     return this->MyVector::size();

 }
