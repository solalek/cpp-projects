#include <iostream>
using namespace std;

template<typename T>
class List {
private:
	template<typename T1>
	class Node {
	public:
		Node * pNext;
		T1 data;
		Node (T1 data = T1(), Node * pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T> * head;
public:
	List();
    void push_back(T data);
    void pop_back();
    void push_front(T data);
    void pop_front();
    void insert(int index, T data);
    void printAll();
    void removeAt(int index);
    int GetSize() { return Size; };
    T & operator[] (const int index);
};

template<typename T>
List<T>::List() {
    Size = 0;
    head = nullptr;
}

template<typename T>
void List<T>::push_back(T data) {
    if (head == nullptr) {
        head = new Node<T>(data);
    } else {
        Node<T> *current = this->head;
        while(current->pNext != nullptr) {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
        Size++;
    }
}

template<typename T>
void List<T>::pop_back() {
    Node<T> *current = this->head;
    for (int i = 0; i < Size - 1; i++) {
        current = current->pNext;
    }
    delete current->pNext;
    current->pNext = nullptr;
}

template<typename T>
void List<T>::push_front(T data) {
    head = new Node(data, head);
    Size++;
}

template<typename T>
void List<T>::insert(int index, T data) {
    if (index == 0) {
        push_front(data);
    } else {
        Node<T> *current = this->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->pNext;
        }
        Node<T> *newNode = new Node(data, current->pNext);
        current->pNext = newNode;
    }
}

template<typename T>
void List<T>::printAll() {
    Node<T> *current = this->head;
    while (current != nullptr) {
        std::cout << current->data << std::endl;
        current = current->pNext;
    }
}

template<typename T>
T & List<T>::operator[] (const int index) {
    int counter = 0;
    Node<T> *current = this->head;
    try {
        if (index < 0 or index > this->Size) {
            throw -1;
        }
        while(current != nullptr) {
            if (counter == index) {
                return current->data;
            }
            current = current->pNext;
            counter++;
        }
    } catch (const int ex) {
        std::cout << "Error" << std::endl;
        exit(-1);
    }
}

int main() {
    List<int> lst;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_front(2);
    lst.insert(2, 22);
    lst.printAll();
    return 0;
}





