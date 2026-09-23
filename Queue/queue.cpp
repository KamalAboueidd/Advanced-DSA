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

class LinkedList
{
private:
    Node *front;
    Node *rear;

public:
    LinkedList()
    {
        front = nullptr;
        rear = nullptr;
    }
    void Enqueue(int value)
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
        cout << "Enqueud " << value << "\n";
    }
    void Dequeu()
    {
        if (front == nullptr)
        {
            cout << "Queue is Empty " << "/n";
            return;
        }
        Node *tmp = front;
        front = tmp->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        delete tmp;
    }
    int Peek()
    {
        if (front != nullptr)
        {
            return front->data;
        }
        else
        {
            return -1;
        }
    }
    bool isEmpty()
    {
        return front == nullptr;
    }
    void display()
    {
        if (front == nullptr)
        {
            cout << "Queue is Empty \n";
            return;
        }
        Node *current = front;
        while (current != nullptr)
        {
            cout << current->data << "---";
            current = current->next;
        }
        cout << "Null" << "\n";
    }
};

int main()
{
    LinkedList li;
    li.Enqueue(22);
    li.Enqueue(44);
    li.Enqueue(33);
    li.Dequeu();
    cout << li.isEmpty() << "\n";
    cout << li.Peek() << "\n";
    li.display();
    return 0;
}