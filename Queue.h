#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

template <class T>
class Queue
{
    struct Node
    {
        T data;
        Node* next;
    };

    Node* front;
    Node* rear;
    int size;

public:
    Queue()
    {
        front = rear = NULL;
        size = 0;
    }

    void enqueue(T element)
    {
        Node* newNode = new Node;
        newNode->data = element;
        if (!size)
        {
            newNode->next = NULL;
            rear = newNode;
        }
        else
        {
            newNode->next = front;
        }
        front = newNode;
        size++;
    }

    void dequeue()
    {
        if (size)
        {
            const Node* temp = front;
            front = front->next;
            delete temp;
            size--;
        }
        else cout << "Queue is empty.\n";
    }

    int get_size() const
    {
        return size;
    }

    bool is_empty() const
    {
        return !size;
    }

    T get_front() const
    {
        return front->data;
    }

    T get_rear() const
    {
        return rear->data;
    }

    friend ostream& operator<<(ostream& print, Queue<T>& queue)
    {
        if (queue.size)
        {
            print << "Elements: {";
            Node* temp = queue.front;
            cout << temp->data;
            temp = temp->next;
            while (temp != nullptr)
            {
                cout << ", " << temp->data;
                temp = temp->next;
            }
            cout << "}\n";
        }
        else print << "Queue is empty.\n";
        return print;
    }

    ~Queue()
    {
        Node* temp = front;
        while (temp != nullptr)
        {
            delete temp;
            temp = temp->next;
        }
    }
};
#endif
