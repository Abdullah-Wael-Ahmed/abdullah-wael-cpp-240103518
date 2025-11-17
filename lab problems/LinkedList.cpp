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
        if (head == NULL){
            Node *newNode = new Node(x, NULL);
            head = newNode;
        } else {
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
            Node *currrent;
            while (currrent->next != NULL)
            {
                currrent = currrent->next;
            }
            currrent->next = newNode;
        }
    }
};

int main()
{

    return 0;
}