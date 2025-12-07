#include <iostream>

using namespace std;

class LKQueue
{
private:
    struct Node
    {
        int data;
        Node *next;

        Node(int d, Node *n = nullptr)
        {
            data = d;
            next = n;
        }
    };

    Node *head;
    Node *tail;

public:
    LKQueue()
    {
        head = nullptr;
        tail = nullptr;
    }

    void enqueue(int data)
    {
        if (tail == nullptr)
            tail = head = new Node(data);
        else
        {
            Node *n = new Node(data);
            tail->next = n;
            tail = n;
        }
    }

    int dequeue()
    {
        if (head == nullptr)
            return NULL;
        else if (head == tail)
        {
            int data = head->data;
            delete (head);
            head = tail = nullptr;
            return data;
        }
        else
        {
            int data = head->data;
            Node *n = head;
            head = n->next;
            delete (n);
            return data;
        }
    }

    void print()
    {
        if (head == nullptr)
            return;
        Node *n = head;
        do
        {
            cout << n->data << " -> ";
            n = n->next;
        } while (n != nullptr);
        cout << endl;
    }
};

int main()
{
    LKQueue *q = new LKQueue();

    q->enqueue(1);
    q->dequeue();

    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->print();
    q->dequeue();
    q->dequeue();
    q->dequeue();
    q->enqueue(4);
    q->enqueue(1);
    q->print();
}