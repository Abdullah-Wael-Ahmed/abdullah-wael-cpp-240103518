#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    void append(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    int pop() {
        if (head == nullptr) return -1;

        if (head->next == head) {
            int val = head->data;
            delete head;
            head = nullptr;
            return val;
        }

        Node* temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }

        Node* toDelete = temp->next;
        int val = toDelete->data;
        
        temp->next = head;
        delete toDelete;
        
        return val;
    }

    void deleteAt(int pos) {
        if (head == nullptr || pos < 0) return;

        if (pos == 0) {
            if (head->next == head) {
                delete head;
                head = nullptr;
                return;
            }
            
            Node* tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }

            Node* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
            return;
        }

        Node* temp = head;
        Node* prevNode = nullptr;

        for (int i = 0; i < pos; i++) {
            prevNode = temp;
            temp = temp->next;
            
            if (temp == head) {
                cout << "Position out of bounds" << endl;
                return;
            }
        }

        prevNode->next = temp->next;
        delete temp;
    }

    void print() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        
        cout << "(back to head)" << endl;
    }
};

int main() {
    CircularLinkedList* cl = new CircularLinkedList();

    cl->append(10);
    cl->append(20);
    cl->append(30);
    cl->append(40);

    cout << "original: ";
    cl->print();

    cl->pop();
    cout << "after popping: ";
    cl->print();

    cl->deleteAt(0);
    cout << "delete" << endl;
    cl->print();

    return 0;
}