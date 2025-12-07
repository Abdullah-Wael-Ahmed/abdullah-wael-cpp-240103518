#include <iostream>
using namespace std;

class LKStack
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

public:

    LKStack()
    {
        head = nullptr;
    }
    void push(int data)
    {
        if (head == nullptr)
            head = new Node(data);
        else
        {
            Node *n = new Node(data, head);
            head = n;
        }
    }

    int pop()
    {
        if (head == nullptr)
            return NULL;
        else
        {
            Node *n = head;
            head = head->next;
            int data = n->data;
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
            cout << " <- " << n->data;
            n = n->next;
        } while (n != nullptr);
        cout << endl;
    }
};

int main()
{

    LKStack *s = new LKStack();

    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);

    s->print();

    s->pop();
    s->pop();

    s->print();

    return 0;
}