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

    T front()
    {
        return head->value;
    }

    T back()
    {
        return tail->value;
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

    void insert_in_pos(T item, int pos)
    {
        if (pos == 0) insert_front(item);
        else if (pos == length) insert_back(item);
        while (pos < 0 || pos > length)
        {
            cout << "Please insert at index within [0 - " << length - 1 << "]: ";
            cin >> pos;
        }
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

    int count(T element)
    {
        int counter = 0;
        Node* current = head;
        for (int i = 0; i < length; i++)
        {
            if (current->value == element) counter++;
            current = current->next;
        }
        return counter;
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

    int is_exist(T element)
    {
        Node* current = head;
        for (int i = 0; i < length; i++)
        {
            if (current->value == element)
            {
                return i;
            }
            current = current->next;
        }
        return -1;
    }

    pair<T, int> max_element()
    {
        int max = INT_MIN, index = 0;
        Node* current = head;
        for (int i = 0; i < length; i++)
        {
            if (current->value > max) max = current->value, index = i;
            current = current->next;
        }
        return make_pair(max, index);
    }

    pair<T, int> min_element()
    {
        int min = INT_MAX, index = 0;
        Node* current = head;
        for (int i = 0; i < length; i++)
        {
            if (current->value < min) min = current->value, index = i;
            current = current->next;
        }
        return make_pair(min, index);
    }

    void modify_at_pos(const int pos, T item)
    {
        Node* current = head;
        for (int i = 0; i < pos; i++)
        {
            current = current->next;
        }
        current->value = item;
    }

    void clear()
    {
        head = tail = nullptr, length = 0;
    }

    int size() const
    {
        return length;
    }

    friend ostream& operator<<(ostream& print, doubly_linked_list<T>& list)
    {
        if (!list.size())
        {
            print << "The list is empty.\n";
        }
        else
        {
            Node* current = list.head;
            int temp = list.size() - 1;
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

    T& operator[](const int pos)
    {
        Node* current = head;
        try
        {
            if (pos < 0 || pos >= length)
            {
                throw "Error! Index is out of range.";
            }
            for (int i = 0; i < pos; i++)
            {
                current = current->next;
            }
        }
        catch (const char* e)
        {
            cout << e;
        }
        return current->value;
    }

    ~doubly_linked_list()
    {
        delete head;
        delete tail;
    }
};

#endif
