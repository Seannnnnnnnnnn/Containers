/* Implements a Min-Heap */
#include <iostream>
#include <vector>
#include <utility>


template<typename T>
class MinHeap
{
private: 
    std::vector<T> m_vector;

    // Called following an insertion.
    void BubbleUp(size_t idx)
        {
            size_t curr_idx = idx, parent_idx = Parent(idx);
            while (m_vector[curr_idx] < m_vector[parent_idx]) {
                std::swap(m_vector[curr_idx], m_vector[parent_idx]);
                curr_idx = parent_idx;
                parent_idx = Parent(curr_idx);
            }
        }
    
    // called following an extract min
    void BubbleDown()
        {
            size_t curr_idx = 0;
            T curr_elem = m_vector[curr_idx];
            while (curr_elem > m_vector[Left(curr_idx)] || curr_elem > m_vector[Right(curr_idx)])
                {
                    T min_child, left_child = m_vector[Left(curr_idx)], right_child = m_vector[Right(curr_idx)];
                    if (left_child < right_child) {
                        std::swap(m_vector[curr_idx], m_vector[Left(curr_idx)]);
                        curr_idx = Left(curr_idx);
                    } else {
                        std::swap(m_vector[curr_idx], m_vector[Right(curr_idx)]);
                        curr_idx = Right(curr_idx);
                    }
                }
        }
    
    size_t inline Left(size_t idx) const
        {
            size_t left = 2*idx + 1;
            if (left <= m_vector.size())
                return left;
            return idx;
        }

    size_t inline Right(size_t idx) const
        {
            size_t right = 2*idx + 2;
            if (right <= m_vector.size())
                return right;
            return idx;
        }

    size_t inline Parent(size_t idx) const
        {
            if (idx == 0)
                return 0;
            return (idx-1) / 2;
        }

public:

    MinHeap() : m_vector(std::vector<T>()) {}

    size_t Size() const { return m_vector.size(); }

    T& PeekMin()
        { 
            if (m_vector.empty())
                throw std::runtime_error("Heap is empty.");
            return m_vector[0];
        }
    
    T ExtractMin()
        {
            if (m_vector.empty())
                throw std::runtime_error("Heap is empty.");
            
            T min = m_vector[0];
            std::swap(m_vector[0], m_vector[m_vector.size()-1]);
            m_vector.pop_back();

            // now perform a bubble_down
            if (! m_vector.empty())
                BubbleDown();
            return min;
        }
    
    void Insert(const T& value)
        {
            m_vector.push_back(value);
            BubbleUp(m_vector.size() - 1);
        }
};


int main(int argc, char** argv)
{
    MinHeap<int> heap;
    heap.Insert(1);
    heap.Insert(3);
    heap.Insert(5);
    heap.Insert(-5);
    heap.Insert(-15);
    std::cout << heap.PeekMin() << std::endl;  // -15
    heap.ExtractMin();
    std::cout << heap.PeekMin() << std::endl;  // -5
    std::cout << heap.Size() << std::endl;     // 4
}
