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
    void preAppendNode(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    void postAppendNode(int value)
    {
        if (head == nullptr)
        {
            Node *newNode = new Node(value);
            newNode = head;
            return;
        }
        Node *tmp = head;
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        Node *newNode = new Node(value);
        tmp->next = newNode;
    }

    void deleteHead()
    {
        if (head == nullptr)
        {
            cout << "Empty List " << "\n";
            return;
        }
        Node *tmp = head;
        head = tmp->next;
        delete tmp;
    }
    void deleteLastNode()
    {
        if (head == nullptr)
        {
            cout << "Empty list" << "\n";
        }
        if (head->next == nullptr)
        {
            delete head;
        }
        Node *tmp = head;
        while (tmp->next->next != nullptr)
        {
            tmp = tmp->next;
        }
        delete tmp->next;
        tmp->next = nullptr;
    }
    void deleteNodeByValue(int target)
    {
        if (head == nullptr)
            return;

        if (head->data == target)
        {
            deleteHead();
            return;
        }
        Node *tmp = head;
        while (tmp->next != nullptr && tmp->next->data != target)
        {
            tmp = tmp->next;
        }
        if (tmp->next == nullptr)
        {
            cout << "Target Value Not Found : " << "\n";
            return;
        }
        Node *deleteNode = tmp->next;
        tmp->next = deleteNode->next;
        delete deleteNode;
    }
    void deleteNodeByPosition(int position)
    {
        if (head == nullptr || position < 1)
            return;
        if (position == 1)
        {
            deleteHead();
            return;
        }
        Node *tmp = head;
        for (int i = 1; i < position - 1 && tmp->next != nullptr; i++)
        {
            tmp = tmp->next;
        }
        if (tmp->next == nullptr)
        {
            cout << "Target Position Not founded " << "\n";
            return;
        }
        Node *deleteNode = tmp->next;
        tmp->next = deleteNode->next;
        delete deleteNode;
    }
    void display()
    {
        Node *tmp = head;
        while (tmp != nullptr)
        {
            cout << tmp->data << "-->";
            tmp = tmp->next;
        }
        cout << " Null";
    }
};

int main()
{
    LinkedList li;
    li.preAppendNode(1);
    li.preAppendNode(2);
    li.preAppendNode(3);
    li.postAppendNode(4);
    li.postAppendNode(5);
    li.deleteNodeByPosition(6);
    // li.deleteHead();
    // li.deleteLastNode();
    // li.deleteNodeByValue(4);
    li.display();
    return 0;
}