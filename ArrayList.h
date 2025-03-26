#pragma once
template <class T>
class Array {
protected:
	T* arr;
	int size;
	int maxSize;
public:
	Array() : size(0), maxSize(0), arr(nullptr) {}

	Array(int size) : size(size), maxSize(size) {
		arr = new T[size];
		assert(arr != nullptr);
		memset(arr, 0, size * sizeof(T));
	}

	Array(const Array& other) : size(other.size), maxSize(other.maxSize) {
		arr = new T[other.maxSize];
		for (int i = 0; i < size; i++) {
			arr[i] = other.arr[i];
		}
	}

	bool isEmpty() const {
		return !size;
	}

	bool isFull() const {
		return size == maxSize;
	}

	int listSize() const {
		return size;
	}

	int maxListSize()const {
		return maxSize;
	}

	void print()const {
		cout << "List: {";
		cout << arr[0];
		for (int i = 1; i < size; i++) {
			cout << ", " << arr[i];
		}
		cout << '}' << endl;
	}

	bool isItemAtEqual(int location, const T& item)const {
		return arr[location] == item;
	}

	bool insertAt(int location, const T& item) {
		if (location < 0 || location > maxSize) {
			cout << "Position is out of range." << endl;
			return false;
		}
		else if (isFull()) {
			if (maxSize) maxSize *= 2;
			else maxSize = 1;
			T* temp = new T[maxSize];
			for (int i = 0, j = 0; i <= size; i++) {
				if (i != location) temp[i] = arr[j++];
				else temp[i] = item;
			}
			arr = temp;
			size++;
			return true;
		}
	}

	void insertEnd(const T& item) {
		if (isFull()) {
			if (maxSize) maxSize *= 2;
			else maxSize = 1;
			T* temp = new T[maxSize];
			for (int i = 0; i < size; i++) {
				temp[i] = arr[i];
			}
			temp[size] = item;
			arr = temp;
			size++;
		}
		else {
			arr[size++] = item;
		}
	}

	bool removeAt(int location) {
		if (location < 0 || location >= size) {
			cout << "Position is out of range." << endl;
			return false;
		}
		else {
			T* temp = new T[size - 1];
			for (int i = 0, j = 0; i < size; i++) {
				if (i != location) temp[j++] = arr[i];
			}
			arr = temp;
			size--;
			return true;
		}
	}

	T retreiveAt(int location) const {
		if (location < 0 || location >= size) {
			cout << "Position is out of range." << endl;
			return -1;
		}
		else return arr[location];
	}

	void replaceAt(int location, const T& item) {
		if (location < 0 || location >= size) {
			cout << "Position is out of range." << endl;
			return;
		}
		else arr[location] = item;
	}

	void clearList() {
		size = 0;
	}

	void shrinkToFit() {
		maxSize = size;
	}

	void deleteList() {
		delete[] arr;
		size = 0;
		maxSize = 0;
	}

	int seqSearch(const T& item) const {
		for (int i = 0; i < size; i++) {
			if (arr[i] == item) return i;
		}
		return -1;
	}

	bool remove(const T& item) {
		int location = seqSearch(item);
		if (location >= 0 && location < size) {
			removeAt(location);
			return true;
		}
		else {
			cout << "Item not found." << endl;
			return false;
		}
	}

	static friend ostream& operator<<(ostream& os, const Array& arr) {
		os << "List: {";
		os << arr.arr[0];
		for (int i = 1; i < arr.size; i++) {
			os << ", " << arr.arr[i];
		}
		os << '}';
		return os;
	}

	Array<T>& operator=(const Array<T>& other) {
		if (this != &other) {
			delete[] arr;
			this->size = other.size;
			this->maxSize = other.maxSize;
			this->arr = new T[maxSize];
			for (int i = 0; i < this->size; i++) {
				this->arr[i] = other.arr[i];
			}
		}
		return *this;
	}

	~Array() {
		delete[] arr;
	}
};
