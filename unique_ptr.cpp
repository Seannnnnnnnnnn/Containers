/* Implements a Unique Pointer from scratch */


template<typename T>
class unique_ptr
{
private: 
    T* m_ptr;

public:
    unique_ptr(T* raw_ptr) : ptr(m_ptr) {}

    ~unique_ptr() = default;

    unique_ptr(unique_ptr rhs) : delete;

    T* get() const { return m_ptr; }

    void swap(T* other_ptr) { }
};