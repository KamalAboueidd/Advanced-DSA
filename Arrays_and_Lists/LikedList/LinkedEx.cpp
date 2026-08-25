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
    }
    void AppendAfter(int target, int value)
    {
        Node *tmp = head;
        while (tmp != nullptr && tmp->data != target)
        {
            tmp = tmp->next;
        }
        if (tmp == nullptr)
        {
            cout << "target value " << target << "Not founded !" << "\n";
            return;
        }
        Node *newNode = new Node(value);
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
    void AppendIn(int position, int value)
    {
        if (position == 1)
        {
            Node *newNode = new Node(value);
            newNode->next = head;
            head = newNode;
        }
        Node *tmp = head;
        for(int i = 1 ; i < position -1 && tmp != nullptr ; i++){
                tmp= tmp->next;
         }
         if(tmp == nullptr){
             cout << "Your position Not founded " << "\n"; 
         }
         Node* newNode = new Node(value);
         newNode->next = tmp->next;
         tmp = newNode->next;
    }
    void display()
    {
        Node *tmp = head;
        while (tmp != nullptr)
        {
            cout << tmp->data << " ->";
            tmp = tmp->next;
        }
        cout << "Null" << "\n";
    }
};

int main()
{
    LinkedList li;
    li.preAppendNode(12);
    li.preAppendNode(24);
    li.preAppendNode(36);
    li.postAppendNode(44);
    li.AppendAfter(12, 66);
    li.display();

    return 0;
}