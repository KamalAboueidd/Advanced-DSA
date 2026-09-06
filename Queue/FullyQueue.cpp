#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};
class LinkedQueue
{
private:
    Node *front;
    Node *rear;

public:
    LinkedQueue()
    {
        front = nullptr;
        rear = nullptr;
    }
    void Enqueu(int value)
    {
        Node *newNode = new Node(value);
        if (front == nullptr)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueud" << value << endl;
    }
    void Dequeue()
    {
        if (front == nullptr)
        {
            cout << "Queue Already Empty" << "\n";
        }
        Node *tmp = front;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        delete tmp;
    }
    int peek()
    {
        if (front == nullptr)
        {
            cout << "Queque is Empty" << "\n";
            return -1;
        }
        return front->data;
    }
    bool isEmpty()
    {
        return front == nullptr;
    }
    void display()
    {
        if (front == nullptr)
        {
            cout << "Queue is Empty" << "\n";
            return;
        }
        Node *current = front;
        while (current != nullptr)
        {
            cout << current->data << "--" << "\n";
            current = current->next;
        }
        cout << "Null" << "\n";
    }
};

int main()
{

    return 0;
}