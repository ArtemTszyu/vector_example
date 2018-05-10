#include <iostream>

template <typename T>
class vector_t
{
private:
    T* elements_;
    std::size_t size_;
    std::size_t capacity_;

public:
    vector_t()
    {
        size_ = 0;
        capacity_ = 0;
        elements_ = nullptr;
    }
    vector_t(vector_t<T> const& other)
    {
        size_ = other.size_;
        capacity_ = other.capacity_;

        elements_ = new T[capacity_];
        for (int i = 0; i < size_; i++)
        {
            elements_[i] = other.elements_[i];
        }
    }

    vector_t& operator=(vector_t<T> const& other)
    {
        if (this == &other)
        {
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

    ~vector_t()
    {
        delete[] elements_;
    }


    std::size_t size() const
    {
        return size_;
    }

    std::size_t capacity() const
    {
        return capacity_;
    }

    void push_back(T value)
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
    void pop_back()
    {
        if (size_ != 0)
        {
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

    int& operator[](std::size_t index)
    {
        return elements_[index];
    }
    int operator[](std::size_t index) const
    {
        return elements_[index];
    }


    bool operator==(vector_t<T> const& other) const
    {
        bool success = false;
        if (size_ == other.size_ && capacity_ == other.capacity_)
        {
            for (std::size_t i = 0; i < size_; i++)
            {
                if (elements_[i] == other.elements_[i])
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


    T& at(std::size_t index)
    {
        if (index >= size_)
        {
            throw std::out_of_range("Out of range");
        }
        return (*this)[index];
    }
};

template <typename T>
bool operator!=(vector_t<T> const& lhs, vector_t<T> const& rhs)
{
    bool success = true;
    if (lhs == rhs)
    {
        success = !success;
    }

    return success;
}
