#include <iostream>

class LinkedList
{
private:
    struct Node
    {
        Node(int data, Node* next) : m_data(data), m_next(next) {}

        int m_data = 0;
        Node* m_next = nullptr;
    };

public:

    //O(1)
    void push_front(int data)
    {
        Node* node = new Node(data, nullptr);

        if (m_head == nullptr)
        {
            m_head = node;
        }
        else
        {
            node->m_next = m_head;
            m_head = node;
        }
    }

    //O(N)
    void print()
    {
        Node* current = m_head;

        while (current != nullptr)
        {
            std::cout << current->m_data;
            current = current->m_next;
        }
    }

    //O(1)
    int pop_front()
    {
        if (m_head == nullptr)
        {
            //FAIL 
            return {0};
        }

        Node* nodeToDelete = m_head;
        m_head = nodeToDelete->m_next;

        delete nodeToDelete;
    }

    //O(N)
    void push_back(int data)
    {

    }

    //O(N) -> SEARCH
    int search()
    {
        //
        return 0;
    }

private:
    Node* m_head = nullptr;
};



int main()
{
    LinkedList myList;

    myList.push_front(5);
    myList.push_front(4);
    myList.push_front(3);
    myList.push_front(2);
    myList.push_front(1);

    myList.print();
}
