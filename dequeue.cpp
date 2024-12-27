/* Implements a Double Ended Queue (DEQ or Dequeue) */


template<typename T>
class DEQ
{
private: 

    struct Node
    {
        T& m_val; 
        Node* m_next;

        Node (T& val) : m_val(val), m_next(nullptr) {} 
    };

    size_t m_size; 
    Node* m_head; 
    Node* m_tail;

public:
    DEQ () : m_size(0), m_head(nullptr), m_tail(nullptr) {}
    
    ~DEQ()
    {
        Node* current = head_;
        while (current)
            {
                Node* tmp = current->m_next;
                delete current;
                current = tmp;
            }
    }

    struct Iterator
    {
        private:
            Node* current;
        
        public:
            using 
    };

    // Pushes value to end of the queue
    void PushRight(const T& val)
    {
        Node* node = new Node(val);
        if (m_tail)
            {
                m_tail->m_next = node; 
                m_tail = node;
            }
        else 
            {
                m_tail = m_head = node;
            }
        m_size++;
    }

    // insert at the front of the queue
    void PushLeft(const T& val)
        {
            Node* node = new Node(val);
            if (m_head)
                {
                    node->m_next = m_head;
                    m_head = node;
                }
            else 
                {
                    m_tail = m_head = node;
                }
            size++;
        }

    size_t Size() const { return m_size; }
};