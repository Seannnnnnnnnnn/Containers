// implements a statically sized, stack-allocated array
#pragma once

#include <stdexcept>
#include <format>


template<typename Array>
class ArrayIterator
{
public:
    using ValueType      = typename Array::ValueType;
    using PointerType    = ValueType*;
    using ReferenceType  = ValueType&;

    ArrayIterator(PointerType ptr) { m_Ptr(ptr); }; 

    ArrayIterator& operator++()
    {
        m_Ptr++;
        return *this;
    }

    ArrayIterator& operator++(int)  // post-fix operator
    {
        ArrayIterator& temp = *this;
        ++(*this);
        return temp;
    }

    ArrayIterator& operator--()
    {
        m_Ptr--;
        return *this;
    }

    ArrayIterator& operator--(int)  // post-fix operator
    {
        ArrayIterator& temp = *this;
        --(*this);
        return temp;
    }


    bool operator==(const ArrayIterator& other) const 
    {
        return m_Ptr == other.m_Ptr;
    }

    bool operator!=(const ArrayIterator& other) const
    {
        return !(*this == other);
    }

    PointerType operator->()
    {
        return m_Ptr;
    }

    ReferenceType operator*()
    {
        return *m_Ptr;
    }

private:
    PointerType m_Ptr;
};


template<typename T, size_t S>
class Array
{
private:
    T data_[S];

    // verifies that index is valid
    void _verify(size_t idx)
    {
        if (idx < 0 || idx >= S)
            throw std::out_of_range(std::format("Array index {} out of bounds", idx));
    }

public: 
    using ValueType = T; 
    using Iterator = ArrayIterator<Array<T, S>>;

public:
    const size_t Size() const { return S; }

    T& operator[](size_t idx) 
    { 
        _verify(idx);
        return data_[idx]; 
    }
    
    Iterator begin()
    {
        return Iterator(data_);
    }


    Iterator end()
    {
        return Iterator(data_ + S); 
    }
};