#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = nullptr;
    }

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};
class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = nullptr;
    }

    void Append_end(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    void append_Begin(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    void insertAfter(int TargetValue, int newValue)
    {
        Node *tmp = head;
        while (tmp != nullptr && tmp->data != TargetValue)
        {
            tmp = tmp->next;
        }
        if (tmp == nullptr)
        {
            cout << "Target value " << TargetValue << " Not Founded " << "\n";
            return;
        }
        Node *newNode = new Node(newValue);
        newNode->next = tmp->next;
        tmp->next = newNode;
    }




    void insertAtPosition(int position, int newValue)
    {
        if (position == 1)
        {
            Node *newNode = new Node(newValue);
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* tmp = head;
        for(int i = 1 ; i < position -1 && tmp!= nullptr;i++){
             tmp = tmp->next;
        }
        if(tmp == nullptr){
            cout << "Position " << position << " Not Founde " << "\n";
            return;
        }
        Node* newNode = new Node(newValue);
        newNode->next = tmp->next;
        tmp->next = newNode;
    }

    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL";
    }
};

int main()
{
    LinkedList list;

    list.Append_end(10);
    list.Append_end(20);
    list.Append_end(30);
    list.append_Begin(40);
    list.insertAfter(40, 77);
    list.display();

    return 0;
}
