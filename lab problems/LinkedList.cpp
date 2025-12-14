#include <iostream>
using namespace std;

class LinkedList
{
    struct Node
    {
        int data;
        Node *next = nullptr;

        Node(int d, Node *n)
        {
            data = d;
            next = n;
        }
    };

public:
    Node *head;

    LinkedList()
    {
        head = nullptr;
    }

    void addFromFront(int x)
    {
        if (head == nullptr)
        {
            Node *newNode = new Node(x, nullptr);
            head = newNode;
        }
        else
        {
            Node *newNode = new Node(x, head);
            head = newNode;
        }
    }

    void addFromBack(int x)
    {
        Node *newNode = new Node(x, nullptr);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *currrent = head;
            while (currrent->next != nullptr)
            {
                currrent = currrent->next;
            }
            currrent->next = newNode;
        }
    }

    void insert(int x, int pos)
    {
        Node *newNode = new Node(x, nullptr);
        Node *p = head;
        for (int i = 1; i < pos && p->next != nullptr; i++)
        {
            p = p->next;
        }
        newNode->next = p->next;
        p->next = newNode;
    }

    void insertBeforeVal(int x, int val)
    {
        Node *newNode = new Node(x, nullptr);
        if (head->data == val)
        {
            newNode->next = head->next;
            head = newNode;
        }
        else
        {
            Node *p = head;
            while (p->next != nullptr)
            {
                if (p->next->data == val)
                {
                    newNode->next = p->next;
                    p->next = newNode;
                    break;
                }
                else
                {
                    p = p->next;
                }
            }
        }
    }

    void deleteNode(int pos) { // one function that deletes from front, back and middle
        if (head == nullptr){
            cout << "Out of bounds";
            return;
        }
        Node* cursor = head;
        Node* prev = nullptr;
        if (pos == 0){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        for (int i = 0 ; i <= pos && cursor->next != nullptr ; i++){
            if (pos == i){
                prev->next = cursor->next;
                delete cursor;
                return;
            } else {
                prev = cursor;
                cursor = cursor->next;
            }
        }
        cout << "Out of bounds";
    }

    void concatinate(LinkedList *ls){
        if (head == nullptr){
            head = ls->head;
            return;
        }
        else {
            Node *tail = head;
            while(tail->next != nullptr){
                tail = tail->next;
            }
            tail->next = ls->head;
        }
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;  // original next
            current->next = prev;  // set the node nex to prev 
            prev = current; // preserve this node for next iteration
            current = next; // set the node to the next
        }

        head = prev; // set the head to be the tail
    }
};

int main()
{

    return 0;
}