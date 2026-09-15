#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
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
            cout << current->data << "---" << "\n";
            current = current->next;
        }
        cout << "Null" << "\n";
    }
};

int main()
{
      LinkedList li ;
      li.Enqueue(22);
      li.Enqueue(33);
       li.display();
    return 0;
}