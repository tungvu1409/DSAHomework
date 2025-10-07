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
        if (size == size_max) {
            return;
        }
        a[size] = x;
        size++;
    }

    int deleteLast() {
        if (size == 0) {
            return -1;
        }
        return a[--size];
    }

    int getAt(int k) {
        if (k < 0 || k >= size) {
            return -1;
        }
        return a[k];
    }

    ~List() {
        delete[] a;
    }
};


struct Stack {
    List list;  

    Stack(int maxSize = 100) : list(maxSize) {}

    bool isEmpty() {
        return list.size == 0;
    }

    void push(int item) {
        list.insertLast(item);
    }

    int pop() {
        return list.deleteLast();
    }

    int size() {
        return list.size;
    }

    int top() {
        if (isEmpty()) {
            return -1;
        }
        return list.getAt(list.size - 1);
    }
};

int main() {
    Stack st(10);

    st.push(5);
    st.push(10);
    st.push(20);

    cout<< st.size() << endl;    
    cout<< st.top() << endl;       
    cout << st.pop() << endl;     
    cout << st.top() << endl; 
    cout << (st.isEmpty() ? "Yes" : "No") << endl;
}


