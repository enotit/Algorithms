#include <iostream>
#include <time.h>
#include <string>
#include <sstream>

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

    void clear(){
        while (tail != nullptr) {
            remove();
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
    std::string getAddresses() {
        std::stringstream ss;
        if (tail != nullptr) {
            TNode<T>* current = tail->next;
            do {
                ss << &(current->data) << " ";
                current = current->next;
            } while (current != tail->next);
        }
        return ss.str();
    }
};
double take_now()
{
    clock_t start = clock();
    double seconds = (double)(start);
    return seconds;
}

int main() {
    CircularLinkedList<int> list;
    for (int i = 1; i <= 5; i++) {
        list.insert(i);
    }
    std::cout << "Адреса элементов после добавления: " << list.getAddresses() << std::endl; // 0x1c9ef3716d0 0x1c9ef371710 0x1c9ef371750 0x1c9ef371790 0x1c9ef3717d0 

    for (int i = 1; i <= 2; i++) {
        list.remove();
    }
    std::cout << "Адреса элементов после удаления: " << list.getAddresses() << std::endl; // 0x1c9ef371750 0x1c9ef371790 0x1c9ef3717d0

    return 0;

}
