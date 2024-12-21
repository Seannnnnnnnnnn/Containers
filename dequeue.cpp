/* Implements a Double Ended Queue (DEQ). Using a linked list as the underlying structure */
#include <iostream>
#include <memory>


template<typename T>
class DEQ
{
    struct Node
    {
        T& data_;
        Node* next_;

        Node(const T& data){
            data_ = data;
            next_ = nullptr;
        }

        ~Node() {   
            delete next_;
        }
    };

private:
    Node* front_;
    Node* back_;
    size_t size_; 

public:
    DEQ() {
        front_ = nullptr;
        back_ = nullptr;
        size_ = 0;
    }
    ~DEQ() {}  // TODO: think about how to delete out a Deque, will need to free every node in the LL

    void AppendLeft(const T& data)  // append data to the front of the queue
    {
        Node* front = std::unique_ptr(Node(data));
        front->next_ = front_;
        front_ = front;
        size_++;
    }

    void AppendRight(const T& data)
    {
        Node* back = std::unique_ptr(Node(data));
        back_->next_ = back;
        back_ = back;
        size_++;
    }

    void Print()
    {
        Node* curr = front_;
        while (curr)
        {
            std::cout << curr->data_ << " -> ";
            curr = curr->next_;
        }
    } 
};


int main()
{
    DEQ<int> deq;
    deq.AppendRight(1);
    deq.AppendRight(2);
    deq.AppendRight(3);

    deq.Print();
}