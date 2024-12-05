// implements a statically sized, stack-allocated array
#include <stdexcept>
#include <format>


template<typename T, size_t S>
class Array{

private:
    T data_[S];

    void _verify(size_t idx) // verifies idx is valid
    {
        if (idx < 0 || idx >= S)
            throw std::out_of_range(std::format("Array index {} out of bounds", idx));
    }


public:

    const size_t Size() const { return S; }

    T& operator[](size_t idx) 
    { 
        _verify(idx);
        return data_[idx]; 
    }
    
};