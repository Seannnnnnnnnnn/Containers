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
        Iterator(Node* node) : current_(node) {}
        T& operator*() { return current_->val_; }
        T* operator->() { return &(current_->val_); }
        
        Iterator operator ++ () 
            {
                if (current_)
                    current_ = current_->next_.get(); 
                return *this;
            }
        
        
        Iterator operator ++ (int)
            {
                auto tmp = this;
                if (current_)
                    current_ = current_->next_.get();
                return *tmp;
            }

        bool operator == (const Iterator& other) const { return current_ == other.current_; }
        bool operator != (const Iterator& other) const { return current_ != other.current_; }
        
    private:
        Node* current_; 
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

    void Reverse() // TODO: debug this boy
    { 
       Node* prev = head_.get(); 
       Node* curr = head_.get()->next_;
       while (curr) {
            Node* next = curr.get()->next_;
            curr->next_ = std::move(prev);
            prev = std::move(curr); 
            curr = std::move(next); 
       }
    }

    Iterator begin() { return Iterator(head_.get()); }
    Iterator end() { return nullptr; }

    Iterator Find(const T& val)
    {
        Iterator curr = begin(); 
        while (curr != end())
        {
            if (*curr == val)
                return curr;
            ++curr;
        }
        return end(); 
    }
};



int main()
{
    List<int> myList;
    for (int i = 1; i <= 10; ++i)
        myList.Add(i);
    
    for (auto elem : myList)
        std::cout << elem << " ";
    
    std::cout << "\nReversing:\n";
    myList.Reverse();

    for (auto elem : myList)
        std::cout << elem << " ";

}