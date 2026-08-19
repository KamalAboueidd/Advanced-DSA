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
    void prePend(int value)
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
    void display()
    {
        Node *tmp = head;
        while (tmp != nullptr)
        {
            cout << tmp->data << "--> ";
            tmp = tmp->next;
        }
        cout << " Null \n";
    }
};

int main()
{
    LinkedList li;
    li.prePend(1);
    li.prePend(2);
    li.postAppend(3);
    li.display();
    return 0;
}
