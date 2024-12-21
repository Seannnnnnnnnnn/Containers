/* Implements a Linked List like std::list */
#include <iostream>
#include <memory>
#include <iterator> 



template<typename T>
class List
{
private: 

    struct Node
    {
        T val_;
        std::unique_ptr<Node> next_;
        Node(T val) : val_(val), next_(nullptr) {}
        
        template<typename U>
        Node(U&& val) : val_(std::forward<U>(val)), next_(nullptr) {}
    };

    std::unique_ptr<Node> head_;
    Node* tail_;
    size_t size_;

public:

    struct Iterator
    {
        Iterator(Node* node) : m_ptr(node) {}
        Node operator *() return { *Node; }

    private:
        Node* m_ptr; 
    };


    List() : head_(nullptr), tail_(nullptr), size_(0) {}

    ~List() = default;
    
    size_t Size() const { return size_; }

    template<typename U>
    void Add(U&& val)
    {
        auto node = std::make_unique<Node>(std::forward<U>(val));
        if (tail_)
            {
                tail_->next_ = std::move(node);
                tail_ = tail_->next_.get();
            }
        else
            {
                head_ = std::move(node);
                tail_ = head_.get();
            }
        size_++;
    }

    Iterator begin() { return Iterator(head_); }
    Iterator end() { return nullptr; }

};



int main()
{
    List<int> myList;
    myList.Add(5);
    myList.Add(6);
    std::cout << myList.Size() << std::endl;
}