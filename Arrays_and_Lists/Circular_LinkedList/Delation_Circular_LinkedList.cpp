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
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }
    void InsertHead(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        { // if li Emp
            head = newNode;
            newNode->next = head;
            return;
        }
        Node *tmp = head;
        while (tmp->next != head)
        {
            tmp = tmp->next;
        }
        newNode->next = head;
        tmp->next = newNode;
        head = newNode;
    }
    void InsertEnd(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node *tmp = head;
        while (tmp->next != head)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
        newNode->next = head;
    }
    void InsertAtPosition(int position, int value)
    {
        if (position < 1)
            return;
        if (position == 1)
        {
            InsertHead(value);
            return;
        }
        if (head == nullptr)
        {
            cout << "List is Empty so you cannot insert in this position" << "\n";
            return;
        }
        Node *tmp = head;
        for (int i = 1; i < position - 1; i++)
        {
            tmp = tmp->next;
            if (tmp == head)
            {
                cout << "Position out of Range \n";
                return;
            }
        }
        Node *newNode = new Node(value);
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
    void deleteHead()
    {
        if (head == nullptr)
        {
            cout << "List aready is empty " << "\n";
            return;
        }

        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *tmp = head;
        while (tmp->next != head)
        {
            tmp = tmp->next;
        }
        Node *delHead = head;

        tmp->next = head->next;
        head = tmp->next;
        delete delHead;
    }
    void deleteEnd()
    {
        if (head == nullptr)
        {
            cout << "List is Empty " << "\n";
            return;
        }
        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *tmp = head;
        while (tmp->next->next != head)
        {
            tmp = tmp->next;
        }
        Node *deleteNode = tmp->next;
        tmp->next = head;
        delete deleteNode;
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
            cout << "List is Already Empty" << "\n";
            return;
        }
        Node *tmp = head;
        for (int i = 1; i < position - 1; i++)
        {
            tmp = tmp->next;
            if (tmp == head)
            {
                cout << "Your Position is out of the List " << "\n";
                return;
            }
        }
        if (tmp->next == head)
        {
            cout << "Position out Of list \n";
        }
        Node *delNode = tmp->next;
        tmp->next = delNode->next;
        delete delNode;
    }
    void display()
    {
        Node *tmp = head;
        do
        {
            cout << tmp->data << "-> ";
            tmp = tmp->next;
        } while (tmp != head);
        cout << "(Back to Head)\n";
    }
};

int main()
{
    LinkedList li;
    li.InsertHead(1);
    li.InsertHead(2);
    li.InsertEnd(3);
    li.InsertAtPosition(6, 12);
    li.display();
    return 0;
}