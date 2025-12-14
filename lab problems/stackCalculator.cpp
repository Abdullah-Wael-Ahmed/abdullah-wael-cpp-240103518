#include <iostream>
#include <string>
#include <cctype>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{
private:
    Node *topNode;

public:
    Stack()
    {
        topNode = nullptr;
    }

    bool isEmpty()
    {
        return (topNode == nullptr);
    }

    void push(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = topNode;
        topNode = newNode;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow: Cannot pop from empty stack." << endl;
            exit(1);
        }
        int poppedValue = topNode->data;
        Node *temp = topNode;
        topNode = topNode->next;
        delete temp;
        return poppedValue;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty: Cannot peek." << endl;
            exit(1);
        }
        return topNode->data;
    }
};

int getPrecedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string infixToPostfix(string expression)
{
    Stack s;
    string postfix = "";

    for (int i = 0; i < expression.length(); i++)
    {
        char c = expression[i];

        if (c == ' ')
            continue;

        if (isdigit(c))
        {
            postfix += c;
            postfix += ' ';
        }
        else if (c == '(')
        {
            s.push(c);
        }

        else if (c == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                postfix += (char)s.peek();
                postfix += ' ';
                s.pop();
            }

            if (!s.isEmpty() && s.peek() == '(')
            {
                s.pop();
            }
            else
            {
                return "Mismatched parentheses";
            }
        }
        else if (isOperator(c))
        {
            while (!s.isEmpty() && s.peek() != '(' &&
                   getPrecedence(s.peek()) >= getPrecedence(c))
            {
                postfix += (char)s.peek();
                postfix += ' ';
                s.pop();
            }
            s.push(c);
        }
        else
        {
            return "Invalid character encountered";
        }
    }

    while (!s.isEmpty())
    {
        if (s.peek() == '(')
            return "Mismatched parentheses";
        postfix += (char)s.peek();
        postfix += ' ';
        s.pop();
    }

    return postfix;
}

int evaluatePostfix(string expression)
{
    Stack s;

    for (int i = 0; i < expression.length(); i++)
    {
        char c = expression[i];

        if (c == ' ')
            continue;

        if (isdigit(c))
        {
            s.push(c - '0');
        }
        else if (isOperator(c))
        {
            if (s.isEmpty())
            {
                cout << "Invalid Postfix Expression (not enough operands)" << endl;
                exit(1);
            }
            int val2 = s.pop();

            if (s.isEmpty())
            {
                cout << "Invalid Postfix Expression (not enough operands)" << endl;
                exit(1);
            }
            int val1 = s.pop();

            switch (c)
            {
            case '+':
                s.push(val1 + val2);
                break;
            case '-':
                s.push(val1 - val2);
                break;
            case '*':
                s.push(val1 * val2);
                break;
            case '/':
                if (val2 == 0)
                {
                    cout << "Division by Zero" << endl;
                    exit(1);
                }
                s.push(val1 / val2);
                break;
            }
        }
    }

    int result = s.pop();

    if (!s.isEmpty())
    {
        cout << "Invalid Expression (extra operands)" << endl;
        exit(1);
    }

    return result;
}


int main()
{
    string infix;
    cout << "Enter an infix expression (single digits): ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);

    if (postfix.find("Error") != string::npos)
    {
        cout << postfix << endl;
        return 1;
    }

    int result = evaluatePostfix(postfix);

    cout << "Postfix: " << postfix << endl;
    cout << "Result: " << result << endl;

    return 0;
}