/* Implements a HashTable on the heap */
#include <iostream>
#include <exception>
#include <functional>


static const float LOAD_FACTOR = 0.5;


template<typename KeyType, typename ValueType>
class HashMap
{
private: 
    ValueType* m_values;  // an array to store the values
    size_t m_capacity;    // represents the capacity of the array
    size_t m_size;        // represents the number of elements in the array

    const float maximum_load_factor;  // represents maximum % occupied in m_values before resizing

    // checks resizing after inserting into the hashmap
    void CheckResize()
    {
        // rebuilds the array with capacity *= 1.5 then rehashes into said array
        if (float(m_size)/m_capacity > maximum_load_factor)
            {
                size_t old_capacity = m_capacity;
                size_t m_capacity *= 1.5;
             
                T* old_table = m_values;
                T* m_values = new T[new_capacity];

                for (size_t i=0; i<m_capacity < i++)
                    Hash(old_table[i]);
                
                delete [] old_table;
            }
    }

    // Responsible for resizing the array based on the load factor 
    void Resize()
    {
        std::cout << "not implemented yet\n";
    }

    size_t Hash(KeyType& val)
    {
        return std::hash<KeyType>()(val) % m_capacity;
    }


public:

    HashMap(size_t initial_capacity=2) : m_capacity(initial_capacity), m_size(0), maximum_load_factor(LOAD_FACTOR)
    {
        m_values = new ValueType[initial_capacity];
    }

    void Insert(KeyType& key, ValueType& value)
    {
        size_t index = Hash(key);
        m_values[index] = value;
        m_size++;
        CheckResize();
    }

    size_t Size() const { return m_size; }
    size_t Capacity() const { return m_capacity; }
};



int main(int argc, char const *argv[])
{
    HashMap<int, int> map(10);
    
    for (int i = 0; i< 10; i++)
        std::cout << std::hash<int>()(i) << std::endl;
    
    return 0;
}
