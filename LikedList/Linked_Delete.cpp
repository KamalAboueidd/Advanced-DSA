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
    void preAppend(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    void deleteHead()
    {
        if (head == nullptr)
        {
            cout << "empty list" << "\n";
            return;
        }
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
    void deleteEnd()
    {
        if (head == nullptr)
        {
            cout << "List Aleardy Empty " << "\n";
            return;
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
    void deleteByValue(int targetValue)
    {
        if (head == nullptr)
            return;
        if (head->data = targetValue) // one node
        {
            deleteHead();
            return;
        }
        Node *tmp = head;
        while (tmp != nullptr && tmp->next->data != targetValue)
        {
            tmp = tmp->next;
        }
        if (tmp->next == nullptr)
        {
            cout << "value " << targetValue << " Not Founded ";
        }
        Node *nodeDelete = tmp->next;
        tmp->next = nodeDelete->next;
        delete nodeDelete;
    }
    void deleteByPostion(int position)
    {
         if(head == nullptr || position < 1)return;
         if(position == 1)
         {
             deleteHead();
             return;
         }
            Node* tmp = head;
            for(int i = 1 ; i < position - 1 && tmp->next != nullptr;i++)
            {
                 tmp = tmp->next;
            }
            if(tmp == nullptr)
            {
                 cout << "......." << position ;
            }
             Node* nodeDelete = tmp->next;
             tmp->next = nodeDelete->next;
             delete nodeDelete ;
    }
    void display()
    {
        Node *tmp = head;
        while (tmp != nullptr)
        {
            cout << tmp->data << "=>";
            tmp = tmp->next;
        }
        cout << "Null" << "\n";
    }
};
int main()
{

    LinkedList li;
    li.preAppend(12);
    li.preAppend(22);
    li.preAppend(25);
    // li.deleteByValue(24);
    li.deleteByPostion(2);
    // li.deleteHead();
    // li.deleteEnd();

    li.display();

    return 0;
}
