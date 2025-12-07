#include <iostream>
using namespace std;

struct Node
{
public:
    Node *left;
    Node *right;
    int data;

    Node(int data)
    {
        this->left = nullptr;
        this->right = nullptr;
        this->data = data;
    }
};

class Tree
{
private:
    Node *root;

public:
    Tree()
    {
        root = nullptr;
    }

    Tree(int data)
    {
        root = new Node(data);
    }

    void insert(int data)
    {
        if (root == nullptr)
        {
            root = new Node(data);
            return;
        }

        Node *node = root;

        while (true)
        {

            if (node->data >= data)
            {

                if (node->left == nullptr)
                {
                    node->left = new Node(data);
                    return;
                }
                else
                {
                    node = node->left;
                    continue;
                }
            }
            else
            {

                if (node->right == nullptr)
                {
                    node->right = new Node(data);
                    return;
                }
                else
                {
                    node = node->right;
                    continue;
                }
            }
        }
    }

    void preOrder(Node *n)
    {
        if (n == nullptr)
            return;

        cout << n->data << " ";

        preOrder(n->left);
        preOrder(n->right);
    }

    void preOrder()
    {
        preOrder(root);
    }

    void inOrder(Node *n)
    {
        if (n == nullptr)
            return;

        inOrder(n->left);
        cout << n->data << " ";
        inOrder(n->right);
    }

    void inOrder()
    {
        inOrder(root);
    }

    void postOrder(Node *n)
    {
        if (n == nullptr)
            return;

        postOrder(n->left);
        postOrder(n->right);
        cout << n->data << " ";
    }

    void postOrder()
    {
        postOrder(root);
    }

    Node *search(int data)
    {
        if (root == nullptr)
            return nullptr;

        Node *n = root;

        while (n != nullptr)
        {
            if (n->data == data)
            {
                return n;
            }

            else if (n->data < data)
                n = n->right;

            else
                n = n->left;
        }

        return n;
    }

    Node *findMin()
    {
        if (root == nullptr)
            return nullptr;

        Node *n = root;

        while (n->left != nullptr)
        {
            n = n->left;
        }

        return n;
    }

    Node *findMax()
    {
        if (root == nullptr)
            return nullptr;

        Node *n = root;

        while (n->right != nullptr)
        {
            n = n->right;
        }

        return n;
    }

    void deleteVal(int val)
    {
        Node *n = root;
        Node *parent = nullptr;
        while (n != nullptr)
        {
            if (val > n->data){
                parent = n;
                n = n->right;
            }
            else if (n->data > val) {
                parent = n;
                n = n->left;
            }
            else break;
        }
        if (n == nullptr) return;
        if (n->left == nullptr && n->right == nullptr){
            if (parent != nullptr){
                if (parent->right == n) parent->right = nullptr;
                else parent->left = nullptr;
            }else {
                root = nullptr;
            }
            delete(n);
        }
        else if (n->left == nullptr && n->right != nullptr) {
            if (parent != nullptr){
                if (parent->right == n) parent->right = n->right;
                else parent->left = n->right;
            } else {
                root = n->right;
            }
            delete(n);
        }
        else if (n->left != nullptr && n->right == nullptr) {
            if (parent != nullptr){
                if (parent->right == n) parent->right = n->left;
                else parent->left = n->left;
            } else {
                root = n->left;
            }
            delete(n);
        }
        else {
            Node *replacement = n->left;
            while (replacement->right != nullptr){
                replacement = replacement->right;
            }
            int data = replacement->data;
            deleteVal(data);
            n->data = data;
        }
    }
};

int main()
{
    Tree *x = new Tree();
    x->insert(10);
    x->insert(5);
    x->insert(20);
    x->insert(1);
    x->insert(10);
    x->insert(15);
    x->insert(30);

    x->deleteVal(30);
    // x->postOrder();
    return 0;
}