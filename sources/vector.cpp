#include <algorithm>
#include <cassert>

#include "vector.hpp"

vector_t::vector_t()
{
    size=0;
    capacity=0;
    elements_=nullptr;
}

vector_t::vector_t(vector_t const & other)
{
    size=other.size;
    capacity=other.capacity;

    elements_= new int [capacity];
    for (int i = 0; i<size; i++) {
        elements_[i]=other.elements_ [i];
    }
}

vector_t & vector_t::operator =(vector_t const & other)
{
    delete [] elements_ ;
    size = other.size;
    capacity = other.capacity;
    elements_ = new int [capacity];
    for (int i = 0; i<size; i++) {
        elements_[i]=other.elements_ [i];
    }
    return *this;
}

bool vector_t::operator ==(vector_t const & other) const
{
    if (size=other.size & capacity=other.capacity) {
        for (int i = 0; i<size; i++) {
            elements_=other.elements_;
        }
        return true;
    }
    else {
        return false;
    }
}

vector_t::~vector_t()
{
    delete [] elements_ ;
}

std::size_t vector_t::size() const
{
    return size;
}

std::size_t vector_t::capacity() const
{
    return capacity;
}

void vector_t::push_back(int value)
{
    if (size==capacity) {
        if (capacity==0) {
            size+=1;
            capacity+=1;
            elements_ = new int [capacity];
            elements_ [0] = value;
        }
        else {
            int * saveelement;
            saveelement = new int[size];
            for(std::size_t i = 0; i < size; ++i) {
                saveelement[i] = elements_[i];
            }
            delete [] elements_;
            capacity = 2 * capacity;
            elements_ = new int[capacity];
            for(std::size_t i = 0; i < size; ++i) {
                elements_[i] = saveelement[i];
            }
            delete [] saveelement;
            elements_[size] = value;
            size ++;
        }
    }
    else elements_ = value;
    size ++;
}

void vector_t::pop_back()
{
    size --;
    if(size == 0 || size * 4 == capacity) {
        int *saveelement;
        saveelement = new int[size];
        for(std::size_t i = 0; i < size; ++i) {
            saveelement[i] = elements_[i];
        }
        delete [] elements_;
        capacity = capacity / 2;
        elements = new int[capacity];
        for(std::size_t i = 0; i < size_; ++i) {
            elements_[i] = saveelement[i];
        }
        delete [] saveelement;
    }
}

int & vector_t::operator [](std::size_t index)
{
    return elements_[index];
}

int vector_t::operator [](std::size_t index) const
{
    return elements_[index];
}

bool operator !=(vector_t const & lhs, vector_t const & rhs)
{
    bool success = true;
    if (lhs == rhs) {
        success = !success;
    }

    return success;
}
