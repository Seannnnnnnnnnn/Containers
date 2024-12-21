/* Implements std::vector from scratch; that is, a heap-allocated dynamically sized array */
#include <exception>
#include <iostream>


template<typename T>
class Vector
{
private:
    T* m_Data;
    size_t m_Capacity; 
    size_t m_Size;

private:
    void _Resize(size_t new_capacity) {
        // responsible for resizing m_Data
        m_Capacity = new_capacity;
        
        T* new_m_Data = new T[m_Capacity];
        for (size_t i=0; i<m_Size; i++) 
            new_m_Data[i] = std::move(m_Data[i]);
        
        delete[] m_Data;  // free the memory currently at m_Data
        m_Data = new_m_Data;
    }

public:
    Vector(size_t capacity=2) {
        if (capacity < 0)
            throw std::logic_error("Capacity must be greater than 0")
        m_Capacity = capacity;
        m_Size = 0;
        m_Data = new T[m_Capacity];
    }

    ~Vector() {
        delete [] m_Data;
    }

    void PushBack(T element) {
        if (m_Size == m_Capacity) 
            _Resize(m_Capacity*2);
        m_Data[m_Size] = element;
        m_Size++;
    }

    T& PopBack() {
        if (m_Size == 0)
            throw std::out_of_range("PopBack called on empty vector");
        m_Size--;
        return  m_Data[m_Size];
    }

    size_t Size() const { return m_Size; }

    void Print() const {
        for (size_t i=0; i<m_Size; i++)
            std::cout<< m_Data[i] << "\n";
    }

    T& operator[] (size_t index) {
        std::cout << "non const return" << std::endl;
        return m_Data[index];
    }

    const T& operator[] (size_t index) const {
        std::cout << "const return" << std::endl;
        return m_Data[index];
    }
};



int main() {
    Vector<int> vec(7);
    vec.PushBack(1);
    vec.PushBack(2);
    vec.PushBack(3);
    vec.PushBack(4);
    std::cout << vec[2] << std::endl;
    const int elem = vec[2];
}