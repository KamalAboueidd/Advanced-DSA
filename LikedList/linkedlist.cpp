#include <iostream>
using namespace std;

struct Node
{
    /* data */
    int data;   // Real place to store the main data
    Node *next; // pointer refere to the location of the next node
};
void insertAtBegin(Node *&head, int value)
{
    Node *newNode = new Node(); // prepare place in memory for new node.
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

int main()
{
   cout << sizeof(Node);
}