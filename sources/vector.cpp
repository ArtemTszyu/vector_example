
#include <algorithm>
#include <cassert>

#include "vector.hpp"
template <typename T>
vector_t <T> ::vector_t()
{
    size_ = 0;
    capacity_ = 0;
    elements_ = nullptr;
}

template <typename T>
vector_t <T> ::vector_t(vector_t const& other)
{
    size_ = other.size_;
    capacity_ = other.capacity_;

    elements_ = new T[capacity_];
    for (int i = 0; i < size_; i++)
    {
        elements_[i] = other.elements_[i];
    }
}

template <typename T>
vector_t <T> & vector_t<T>::operator=(vector_t const& other)
{    
    if ( this == &other ){
        return *this;
    }
    delete[] elements_;    
    size_ = other.size_;
    capacity_ = other.capacity_;
    elements_ = new T[capacity_];
    for (int i = 0; i < size_; i++)
    {
        elements_[i] = other.elements_[i];
    }
    return *this;
}

template <typename T>
bool vector_t <T> ::operator==(vector_t const& other) const
{
   bool success = false;
   if (size_ == other.size_ && capacity_ == other.capacity_)
   {
       for (std::size_t i = 0; i < size_; i++)
       {
           if (elements_ [i] == other.elements_ [i])
           {
               success = true;
           }
           else 
           {
               success = false;
               return success;
           }
       }   
   }
   return success; 
}

template <typename T>
vector_t <T> ::~vector_t()
{
    delete[] elements_;
}

template <typename T>
std::size_t vector_t<T>::size() const
{
    return size_;
}

template <typename T>
std::size_t vector_t<T>::capacity() const
{
    return capacity_;
}

template <typename T>
void vector_t<T>::push_back(int value)
{
    if (size_ == capacity_)
    {
        if (capacity_ == 0)
        {
            size_ = 1;
            capacity_ = 1;
            elements_ = new T[capacity_];
            elements_[0] = value;
        }
        else
        {
            T* saveelement;
            saveelement = new T[size_];
            for (std::size_t i = 0; i < size_; ++i)
            {
                saveelement[i] = elements_[i];
            }
            delete[] elements_;
            capacity_ = 2 * capacity_;
            elements_ = new T[capacity_];
            for (std::size_t i = 0; i < size_; ++i)
            {
                elements_[i] = saveelement[i];
            }
            delete[] saveelement;
            elements_[size_] = value;
            size_++;
        }
    }
    else
    {
        elements_[size_] = value;
        size_++;
    }
}

template <typename T>
void vector_t <T> ::pop_back()
{
    if (size_ != 0){
    size_--;
    if (size_ * 4 == capacity_)
    {
        T* saveelement;
        saveelement = new T[size_];
        for (std::size_t i = 0; i < size_; ++i)
        {
            saveelement[i] = elements_[i];
        }
        delete[] elements_;
        capacity_ = capacity_ / 2;
        elements_ = new T[capacity_];
        for (std::size_t i = 0; i < size_; ++i)
        {
            elements_[i] = saveelement[i];
        }
       
        delete[] saveelement;
    }
    }
}

template <typename T>
int& vector_t<T>::operator[](std::size_t index)
{
    return elements_[index];
}

template <typename T>
int vector_t<T>::operator[](std::size_t index) const
{
    return elements_[index];
}

bool operator!=(vector_t const& lhs, vector_t const& rhs)
{
    bool success = true;
    if (lhs == rhs)
    {
        success = !success;
    }

    return success;
}
