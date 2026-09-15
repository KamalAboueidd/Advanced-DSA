#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};
class LinkedListQueue
{
private:
    Node *front;
    Node *rear;

public:
    LinkedListQueue()
    {
        front = nullptr;
        rear = nullptr;
    }
    void enqueue(int value)
    {
        Node *newNode = new Node(value);
        if (rear == nullptr)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << value << endl;
    }
    void dequeue()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node *temp = front;
        cout << temp->data << " dequeued from queue" << endl;
        front = front->next;
        if (front == nullptr) // if the Queue have only on node
        {
            rear = nullptr;
        }
        delete temp;
    }
    int peek()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        cout << "Front element is: " << front->data << endl;
        return front->data;
    }
    bool isEmpty()
    {
        return (front == nullptr);
    }
    void display()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements are: ";
        Node *current = front;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "End of queue" << endl;
    }
};

int main()
{
    LinkedListQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display(); // 10 -> 20 -> 30 -> NULL

    cout << "Front element is: " << q.peek() << "\n"; // 10

    // q.dequeue();
    q.display();

    return 0;
}