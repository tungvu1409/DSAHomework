#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

struct List {
    Node* head;
    int size;

    List() {
        head = nullptr;
        size = 0;
    }

    void insertLast(int x) {
        Node* newNode = new Node(x);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    int deleteLast() {
        if (head == nullptr) return -1;

        if (head->next == nullptr) { 
            int val = head->data;
            delete head;
            head = nullptr;
            size--;
            return val;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        int val = temp->next->data;
        delete temp->next;
        temp->next = nullptr;
        size--;
        return val;
    }

    int getAt(int k) {
        if (k < 0 || k >= size) return -1;
        Node* temp = head;
        for (int i = 0; i < k; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    ~List() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};


struct Stack {
    List list;

    Stack() {} 

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
        if (isEmpty()) return -1;
        return list.getAt(list.size - 1);
    }
};


int main() {
    Stack st;

    st.push(5);
    st.push(10);
    st.push(20);
    cout << st.size() << endl;    
    cout << st.top() << endl;   
    cout << st.pop() << endl;      
    cout << st.top() << endl;     
    cout << (st.isEmpty() ? "Yes" : "No") << endl; 
}
