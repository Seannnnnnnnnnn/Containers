/* Implements a Min-Heap */
#include <vector>


template<typename T>
class MinHeap
{
private: 
    std::vector<T> m_vector;
    size_t m_capacity;

public:

    MinHeap(size_t capcity=2) { m_vector = std::vector()}

    size_t Size() { return m_vector.size(); }


};