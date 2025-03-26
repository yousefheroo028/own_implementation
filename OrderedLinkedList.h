#pragma once

#include <iostream>

using namespace std;

template <typename T>
class OrderLinkedList {
private:
	struct Node {
		T value;
		Node* next;
		Node(T value) : value(value), next(nullptr) {}
	};
	Node* head;
	int size;
public:
	OrderLinkedList() : head(nullptr), size(0) {}

	~OrderLinkedList() {
		delete head;
	}

	void insert(T value) {
		Node* newNode = new Node(value);
		if (!size) {
			head = newNode;
			newNode->next = nullptr;
		}
		else if (head->value > value) {
			newNode->next = head;
			head = newNode;
		}
		else {
			Node* trailcurrent = head;
			Node* current = trailcurrent->next;
			while (current != nullptr && current->value < value) {
				trailcurrent = current;
				current = current->next;
			}
			trailcurrent->next = newNode;
			newNode->next = current;
		}
		size++;
	}

	void remove(T value) {
		if (!size) {
			cout << "List is empty" << endl;
			return;
		}
		else {
			Node* trailcurrent = head;
			Node* current = trailcurrent->next;
			if (head->value == value) {
				head = current;
				delete trailcurrent;
				size--;
				return;
			}
			while (current != nullptr && current->value != value) {
				trailcurrent = current;
				current = current->next;
			}
			if (current == nullptr) {
				cout << "Value not found" << endl;
				return;
			}
			trailcurrent->next = current->next;
			delete current;
		}
		size--;
	}

	int getSize() {
		return size;
	}

	int search(T value) {
		Node* current = head;
		int index = 0;
		while (current != nullptr) {
			if (current->value == value) {
				return index;
			}
			current = current->next;
			index++;
		}
		return -1;
	}

	void print() {
		Node* current = head;
		while (current != nullptr) {
			cout << current->value << " ";
			current = current->next;
		}
		cout << endl;
	}
};
