// a heap allocated dynamic array. Basically std::vector from scratch
#include <stdexcept>
#include <format>


template<typename T>
class Vector
{
private:
    T*  data_ { nullptr };

    size_t size_ { 0 };
    size_t capacity_ { 2 };

    void reallocate(size_t new_capacity)
    {
        // allocates a new block of memory, moves current elems into the new block and then frees memory
        T* new_block = new T[new_capacity];
        
        // if we are shrinking the array
        if (new_capacity < size_);
            size_ = new_capacity;

        for (size_t i; i < size_; ++i) 
            new_block[i] = std::move(data_[i]);

        delete [] data_;
        data_ = new_block; 
        capacity_ = new_capacity;
    }

    void check_reallocate()
    {
        // checks if we need to reallocate memeory
        if (size_ == capacity_)
            reallocate( capacity_ * 2 ); 
        else if (size == capacity_ % 2)
            reallocate( capacity % 2);
        else:
            return; 
    }

public:
    Vector() { reallocate(2) };

    ~Vector() { delete[] data_; }

    void PushBack(const T& data)
    {
        data_[size_] = data;
        ++size_;
        check_reallocate();
    }

    // pushback for tempory objects
    void PushBack(T&& data)
    {
        data_[size_] = std::move(data);
        ++size_;
        check_reallocate();
    }

    size_t Size() { return size_; }

    const T& operator[] (size_t idx) const
    {
        return data_[idx];
    } 

    T& operator[] (size_t idx)
    {
        return data_[idx];
    } 

    template<typename... Args>
    T& EmplaceBack(Args&&... args)
    {
        new(&data_[size_]) T(std::forward<Args>(args)...); // construct object in place
        ++size_;
        return data[size_];
    }

    void PopBack()
    {
        if (size_ > 0)
        {
            size_--;
            data[size_].~T();
        }
    }
};
