#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
using namespace std;

template <class T>
class doubly_linked_list
{
    struct Node
    {
        T value;
        Node* previous;
        Node* next;
    };

    Node* head;
    Node* tail;
    int length;

public:
    doubly_linked_list()
    {
        length = 0;
        head = tail = nullptr;
    }

    void insert_back(T item)
    {
        Node* newItem = new Node;
        newItem->value = item;
        newItem->next = nullptr;
        if (!length)
        {
            newItem->previous = nullptr;
            head = newItem;
        }
        else
        {
            tail->next = newItem;
            newItem->previous = tail;
        }
        tail = newItem;
        length++;
    }

    void insert_front(T item)
    {
        Node* newItem = new Node;
        newItem->value = item;
        newItem->previous = nullptr;
        if (!length)
        {
            newItem->next = nullptr;
            tail = newItem;
        }
        else
        {
            newItem->next = head;
        }
        head = newItem;
        length++;
    }

    void insert_in_pos(T item, const int pos)
    {
        if (pos == 0) insert_front(item);
        else if (pos == length) insert_back(item);
        else if (pos < 0 || pos > length) throw out_of_range("Position out of range");
        else
        {
            Node* newItem = new Node;
            newItem->value = item;
            Node* current = head;
            for (int i = 0; i < pos - 1; i++)
            {
                current = current->next;
            }
            newItem->next = current->next;
            newItem->previous = current;
            current->next = newItem;
            current->next->previous = newItem;
            length++;
        }
    }

    void remove_front()
    {
        if (length > 1)
        {
            const Node* current = head;
            head = head->next;
            delete current;
            length--;
        }
        else if (length == 1) head = nullptr, length--;
    }

    void remove_back()
    {
        if (length > 1)
        {
            const Node* current = tail;
            tail = tail->previous;
            delete current;
            length--;
        }
        else if (length == 1) tail = nullptr, length--;
    }

    void remove_from_pos(const int pos)
    {
        if (pos == 1) remove_front();
        else if (pos == length) remove_back();
        else if (pos < 1 || pos > length) cout << "Position is out of range\n";
        else
        {
            Node* current = head;
            Node* temp = head;
            Node* temp2 = head;
            for (int i = 1; i < pos - 1; i++)
                temp = temp->next;
            for (int i = -1; i < pos - 1; i++)
                temp2 = temp2->next;
            for (int i = 0; i < pos - 1; i++)
                current = current->next;
            temp->next = current->next;
            temp2->previous = current->previous;
            delete current;
            length--;
        }
    }

    bool is_empty() const
    {
        return !length;
    }

    int size() const
    {
        return length;
    }

    void print()
    {
        if (!length)
        {
            cout << "The list is empty.\n";
        }
        else
        {
            Node* current = head;
            int temp = length - 1;
            cout << "List: {";
            cout << current->value;
            current = current->next;
            while (temp--)
            {
                cout << ", " << current->value;
                current = current->next;
            }
            cout << "}\n";
        }
    }

    ~doubly_linked_list()
    {
        delete head;
        delete tail;
    }
};

#endif
