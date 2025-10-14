#include <iostream>
using namespace std;

struct List {
    int* a;
    int size;
    int size_max;

    List(int size_max = 100) {
        this->size_max = size_max;
        size = 0;
        a = new int[size_max];
    }

    void insertLast(int x) {
        if (size == size_max) return;
        a[size++] = x;
    }

    int deleteFirst() {
        if (size == 0) return -1;
        int first = a[0];
        for (int i = 0; i < size - 1; i++) {
            a[i] = a[i + 1];
        }
        size--;
        return first;
    }

    int getAt(int k) {
        if (k < 0 || k >= size) return -1;
        return a[k];
    }

    ~List() {
        delete[] a;
    }
};

struct Queue {
    List list;

    Queue(int maxSize = 100) : list(maxSize) {}

    bool isEmpty() {
        return list.size == 0;
    }

    void enqueue(int item) {  
        list.insertLast(item);
    }

    int dequeue() {  
        return list.deleteFirst();
    }

    int front() {  
        if (isEmpty()) return -1;
        return list.getAt(0);
    }

    int size() {
        return list.size;
    }
};

int main() {
    Queue q(10);

    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(20);

    cout << q.size() << endl;    
    cout << q.front() << endl;    
    cout << q.dequeue() << endl;   
    cout << q.front() << endl;     
    cout << (q.isEmpty() ? "Yes" : "No") << endl;  

    return 0;
}

