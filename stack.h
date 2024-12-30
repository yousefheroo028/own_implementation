#ifndef STACK_H
#define STACK_H

using namespace std;

template <class T>
class Stack
{
    struct Node
    {
        T value;
        Node* next;
    };

    int length;
    Node* tail;

public:
    Stack(): length(0), tail(nullptr)
    {
    }

    void push(T item)
    {
        Node* newNode = new Node;
        newNode->value = item;
        newNode->next = tail;
        tail = newNode;
        length++;
    }

    T top()
    {
        return tail->value;
    }

    void pop()
    {
        if (tail == nullptr)
        {
            cout << "The Stack is empty.\n";
            return;
        }
        const Node* temp = tail;
        tail = tail->next;
        delete temp;
        length--;
    }

    int size() const
    {
        return length;
    }

    void clear()
    {
        delete tail;
        length = 0;
    }

    friend ostream& operator<<(ostream& print, const Stack& stack)
    {
        if (!stack.size())
        {
            print << "The Stack is empty.\n";
        }
        else
        {
            Node* current = stack.tail;
            int temp = stack.size() - 1;
            print << "List: {";
            print << current->value;
            current = current->next;
            while (temp--)
            {
                print << ", " << current->value;
                current = current->next;
            }
            print << "}";
        }
        return print;
    }

    ~Stack()
    {
        delete tail;
    }
};

#endif
