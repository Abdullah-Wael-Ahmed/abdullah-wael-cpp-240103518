#include <iostream>
using namespace std;

class Queue
{

public:
    int capacity;
    int counter;
    int head;
    int tail;
    int *arr;

    Queue(int capacity)
    {
        this->capacity = capacity;
        this->counter = 0;
        this->tail = 0; // points at the first empty space to be added in;
        this->head = 0; // if the array is not empty then it points at the first element to be removed
        this->arr = new int[capacity];
    }

    bool isFull()
    {
        if (counter == capacity)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isEmpty()
    {
        if (counter == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int elm)
    {
        if (isFull())
        {
            cout << "Overflow";
        }
        else
        {
            arr[tail] = elm;
            if (tail == capacity - 1) tail = 0;
            else tail++;
            counter++;
        }
    }

    int dequeue(){
        if (isEmpty()){
            cout << "Underflow";
            return -1;
        }
        else if (head == capacity - 1){
            int temp = arr[head];
            head = 0;
            counter--;
            return temp;
        }
        else {
            counter--;
            return arr[head++];
        }
    }
};

int main()
{

    Queue arr(3);

    arr.enqueue(1);
    arr.enqueue(2);
    arr.enqueue(3);
    cout << arr.dequeue() << endl;
    cout << arr.dequeue() << endl;
    cout << arr.dequeue() << endl;
    arr.enqueue(4);
    arr.enqueue(5);
    arr.enqueue(6);
    cout << arr.dequeue() << endl;
    cout << arr.dequeue() << endl;
    cout << arr.dequeue() << endl;
    // cout << arr.head << endl << arr.tail << endl;
    return 0;
}