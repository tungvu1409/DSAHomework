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

    bool isEmpty() {
        return head == nullptr;
    }

    void insertLast(int x) {
        Node* newNode = new Node(x);
        if (isEmpty()) {
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

    int removeFirst() {
        if (isEmpty()) {
            cout << "Danh sach rong!\n";
            return -1;
        }
        Node* temp = head;
        int val = temp->data;
        head = head->next;
        delete temp;
        size--;
        return val;
    }

    int getFirst() {
        if (isEmpty()) {
            cout << "Danh sach rong!\n";
            return -1;
        }
        return head->data;
    }


    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~List() {
        while (!isEmpty()) removeFirst();
    }
};

struct Queue {
    List list; 

    bool isEmpty() {
        return list.isEmpty();
    }

    void enqueue(int x) {
        list.insertLast(x);
    }

    int dequeue() {
        return list.removeFirst();
    }

    int front() {
        return list.getFirst();
    }
    
    void display() {
        list.display();
    }

    int size() {
        return list.size;
    }
};

int main() {
    Queue q;

    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);

    cout << "Queue hien tai: ";
    q.display();

    cout << "Front: " << q.front() << endl;

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Queue sau khi dequeue: ";
    q.display();

    cout << "Size: " << q.size() << endl;
    cout << (q.isEmpty() ? "Empty" : "Not empty") << endl;

    return 0;
}


