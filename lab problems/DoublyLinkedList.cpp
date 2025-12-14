#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList()
    {
        head = nullptr;
    }

    void append(int value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    int pop()
    {
        if (head == nullptr)
            return NULL;
        Node *n = head;
        while (n->next != nullptr)
        {
            n = n->next;
        }
        n->prev->next = nullptr;
        int temp = n->data;
        delete (n);
        return temp;
    }

    void deleteAt(int pos)
    {

        if (head == nullptr || pos < 0)
        {
            cout << "Invalid position or empty list." << endl;
            return;
        }

        Node *temp = head;

        if (pos == 0)
        {
            head = temp->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }

        for (int i = 0; temp != nullptr && i < pos; i++)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "out of bound" << endl;
            return;
        }

        temp->prev->next = temp->next;

        if (temp->next != nullptr)
        {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    void print()
    {

        Node *n = head;

        while (n != nullptr)
        {
            cout << n->data << " <-> ";
            n = n->next;
        }

        cout << endl;
    }
};

int main()
{

    DoublyLinkedList *dl = new DoublyLinkedList();

    dl->append(1);
    dl->append(2);
    dl->append(3);
    dl->append(4);
    dl->pop();
    dl->append(5);

    dl->print();
}