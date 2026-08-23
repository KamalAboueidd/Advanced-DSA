#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
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

    void preAppend(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void postAppend(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *tmp = head;
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
        newNode->prev = tmp;
    }

    void AppendAtPosition(int position, int value)
    {
        if (position < 1)
        {
            cout << "Invalid position!\n";
            return;
        }

        if (position == 1)
        {
            preAppend(value);
            return;
        }

        Node *newNode = new Node(value);
        Node *tmp = head;

        // Traverse to the node just before the target position
        for (int i = 1; i < position - 1 && tmp != nullptr; i++)
        {
            tmp = tmp->next;
        }

        // Check if position is out of bounds
        if (tmp == nullptr)
        {
            cout << "Position exceeds list length!\n";
            delete newNode; // Prevent memory leak
            return;
        }

        newNode->next = tmp->next;
        newNode->prev = tmp;

        if (tmp->next != nullptr)
        {
            tmp->next->prev = newNode;
        }

        tmp->next = newNode;
    }
    void deleteHead()
    {
        Node *tmp = head;
        head = tmp->next;
        if (tmp->next != nullptr)
        {
            head->prev = nullptr;
        }
        delete tmp;
    }
    void deleteTaill()
    {
        if (head == nullptr)
            return;
        if (head->next == nullptr)
        {
            deleteHead();
            head = nullptr;
            return;
        }
        Node *tmp = head;
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->prev->next = nullptr;
        delete tmp;
    }
    void deleteAtPosition(int position)
    {
        if (position < 1)
            return;
        if (position == 1)
        {
            deleteHead();
            return;
        }
        if (head == nullptr)
        {
            cout << "List is Empty ";
            return;
        }
        Node *tmp = head;
        for (int i = 1; i < position - 1 && tmp->next != nullptr; i++)
        {
            tmp = tmp->next;
        }
        if (tmp->next == nullptr || tmp == nullptr)
        {
            cout << "position " << position << " not found " << "\n";
        }
        Node *nodeToDelete = tmp->next;
        tmp->next = nodeToDelete->next;
        if (nodeToDelete->next != nullptr)
        {
            nodeToDelete->next->prev = tmp;
        }
        delete nodeToDelete;
    }
    void display()
    {
        Node *tmp = head;
        while (tmp != nullptr)
        {
            cout << tmp->data << " --> ";
            tmp = tmp->next;
        }
        cout << "Null\n";
    }
};

int main()
{
    LinkedList li;
    li.preAppend(1);           // List: 1 --> Null
    li.preAppend(2);           // List: 2 --> 1 --> Null
    li.postAppend(3);          // List: 2 --> 1 --> 3 --> Null
    li.AppendAtPosition(2, 5); // List: 2 --> 5 --> 1 --> 3 --> Null
    li.deleteHead();
    li.deleteTaill();
    li.preAppend(6);
    li.deleteAtPosition(2);
    li.display();

    return 0;
}