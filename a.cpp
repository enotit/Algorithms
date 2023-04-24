#include <iostream>
#include <time.h>

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
};
double take_now()
{
    clock_t start = clock();
    double seconds = (double)(start);
    return seconds;
}

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
    list.clear();
    long counts[5] = {100000, 200000, 300000, 400000, 500000};
    for (long i = 0; i < 5; i++)
    {
        long count = counts[i];
        double start = take_now();
        for (int k = 0; k < count; k++)
        {
            list.insert(rand());
        }
        double finish = take_now();
        double diff = (finish - start);
        cout << "Вставка: " << count << " " << diff << endl;

        start = take_now();
        list.clear();
        finish = take_now();
        diff = (finish - start);
        cout << "Удаление: " << count << " " << diff << endl;
    }

    return 0;
}
