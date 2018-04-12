#include <algorithm>
#include <cassert>

#include "vector.hpp"

vector_t::vector_t()
{
	size=0;
	capacity=0;
	elements=nullptr;
}

vector_t::vector_t(vector_t const & other)
{
	this.size=other.size;
	this.capacity=other.capacity;
	
	elements= new int [capacity];
	for (int i = 0; i<size; i++){
		elements[i]=other.elements [i];
	}
}

vector_t & vector_t::operator =(vector_t const & other)
{
	delete [elements];
	this.size=other.size;
	this.capacity=other.capacity;
	elements= new int [capacity];
	for (int i = 0; i<size; i++){
		elements[i]=other.elements [i];
	}
	return *this;
}

bool vector_t::operator ==(vector_t const & other) const
{
	if (size=other.size & capacity=other.capacity){
	for (int i = 0; i<size; i++){
	elements=other.elements;
	}
	return true;
}
	else {
		return false;
	}
}

vector_t::~vector_t()
{
	delete elements [];
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
	if (size==capacity){
		if (capacity==0){
			size+=1;
			capacity+=1;
			elements = new int [capacity];
			elements [0] = value;
		}
		else{
			int * saveelement;
			saveelement = new int[size];
                for(std::size_t i = 0; i < size; ++i) {
                    saveelement[i] = elements[i];
                }
                delete [] elements;
                capacity = 2 * capacity;
                elements = new int[capacity];
                for(std::size_t i = 0; i < size; ++i) {
                    elements[i] = saveelement[i];
                }
                delete [] mas;
                elements[size] = value;
                size ++;
            }
    }
	else elements = value;
	size ++;
}

void vector_t::pop_back()
{
    size --;
    if(size_ == 0 || size_ * 4 == capacity_) {
        int *saveelement;
        saveelement = new int[size];
        for(std::size_t i = 0; i < size; ++i) {
            saveelement[i] = elements[i];
        }
        delete [] elements;
        capacity = capacity / 2;
        elements = new int[capacity];
        for(std::size_t i = 0; i < size_; ++i) {
            elements[i] = saveelement[i];
        }
        delete [] saveelement;
    }        
}

int & vector_t::operator [](std::size_t index)
{
	return elements[index];
}

int vector_t::operator [](std::size_t index) const
{
	return elements[index];
}

bool operator !=(vector_t const & lhs, vector_t const & rhs)
{
	bool success = true;
	if (lhs == rhs) {
		success = !success;
	}
	
	return success;
}
