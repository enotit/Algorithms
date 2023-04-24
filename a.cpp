#include <iostream>
using namespace std;

template<class T>
class TNode {
public:
    T data;
    TNode<T>* next;

    TNode(T d) : data(d), next(nullptr) {}
};

template<class T>
class CircularLinkedList {
private:
    TNode<T>* tail;

public:
    CircularLinkedList() : tail(nullptr) {}

    void insert(T data) {
        TNode<T>* node = new TNode<T>(data);
        if (tail == nullptr) {
            tail = node;
            tail->next = tail;
        } else {
            node->next = tail->next;
            tail->next = node;
            tail = node;
        }
    }

    void remove() {
        if (tail == nullptr) {
            cout << "Список пуст." << endl;
            return;
        }
        TNode<T>* head = tail->next;
        if (head == tail) {
            delete head;
            tail = nullptr;
        } else {
            tail->next = head->next;
            delete head;
        }
    }

    void print() {
        if (tail == nullptr) {
            cout << "Список пуст." << endl;
            return;
        }
        TNode<T>* current = tail->next;
        while (current != tail) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << current->data << endl;
    }
};

int main() {
    CircularLinkedList<int> list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.print();

    list.remove();
    list.print();

    list.remove();
    list.print();

    list.remove();
    list.print();

    return 0;
}
