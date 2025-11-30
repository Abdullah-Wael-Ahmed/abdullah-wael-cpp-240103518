#include <iostream>
using namespace std;

class LinkedList
{
    struct Node
    {
        int data;
        Node *next = NULL;

        Node(int data, Node *next)
        {
            data = data;
            next = next;
        }
    };

public:
    Node *head;

    LinkedList()
    {
        head = NULL;
    }

    void addFromFront(int x)
    {
        if (head == NULL)
        {
            Node *newNode = new Node(x, NULL);
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
        Node *newNode = new Node(x, NULL);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *currrent = head;
            while (currrent->next != NULL)
            {
                currrent = currrent->next;
            }
            currrent->next = newNode;
        }
    }

    void insert(int x, int pos)
    {
        Node *newNode = new Node(x, NULL);
        Node *p = head;
        for (int i = 1; i < pos && p->next != NULL; i++)
        {
            p = p->next;
        }
        newNode->next = p->next;
        p->next = newNode;
    }

    void insertBeforeVal(int x, int val)
    {
        Node *newNode = new Node(x, NULL);
        if (head->data == val)
        {
            newNode->next = head->next;
            head = newNode;
        }
        else
        {
            Node *p = head;
            while (p->next != NULL)
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
        if (head == NULL){
            cout << "Out of bounds";
            return;
        }
        Node* cursor = head;
        Node* prev = NULL;
        if (pos == 0){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        for (int i = 0 ; i <= pos && cursor->next != NULL ; i++){
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
};

int main()
{

    return 0;
}