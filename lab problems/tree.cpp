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

    void preOrder(Node* n){
        if (n == nullptr) return;

        cout << n->data << " ";

        preOrder(n->left);
        preOrder(n->right);
    }

    void preOrder(){
        preOrder(root);
    }
    

    void inOrder(Node *n){
        if (n == nullptr) return;

        inOrder(n->left);
        cout << n->data << " ";
        inOrder(n->right);
    }
    
    void inOrder(){
        inOrder(root);
    }
    
    void postOrder(Node *n){
        if (n == nullptr) return;
        
        postOrder(n->left);
        postOrder(n->right);
        cout << n->data << " ";
    }

    void postOrder(){
        postOrder(root);
    }

    Node* search(int data) {
        if (root == nullptr) return nullptr;

        Node* n = root;

        while(n != nullptr){
            if (n->data == data) {
                return n;
            }

            else if (n->data < data) n = n->right;
            
            else n = n->left;
        }

        return n;
    }

    Node* findMin(){
        if (root == nullptr) return nullptr;

        Node* n = root;

        while (n->left != nullptr) {
            n = n->left;
        }

        return n;

    }

    Node* findMax(){
        if (root == nullptr) return nullptr;

        Node* n = root;

        while (n->right != nullptr) {
            n = n->right;
        }

        return n;
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

    cout << x->findMax()->data;
    return 0;
}