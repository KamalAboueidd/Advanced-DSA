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
class Stack
{
    
private:
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }
    void push(int value)

    {
        Node *newNode = new Node(value);

        newNode->next = top;
        top = newNode;
        cout << value << " pushed into stack" << "\n"s;
    }
    void pop()
    {
        if (top == nullptr)
        {
            cout << "Satck is underFlow ... empty";
            return;
        }
        Node *tmp = top;
        top = tmp->next;
        cout << tmp->data << " popped from stack.\n";
        delete tmp;
    }
    void peek()
    {
        if (top == nullptr)
        {
            cout << "Satck is underFlow ... empty";
            return;
        }
        cout << top->data;
    }
    bool isEmpty()
    {
        return top == nullptr;
    }
    void display()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty";
            return;
        }
        Node *tmp = top;
        while (tmp != nullptr)
        {
            cout << tmp->data << "->";
            tmp = tmp->next;
            /* code */
        }
        cout << "Null" << "\n";
    }
};

main()
{
    Stack st;
    st.push(12);
    st.push(22);
    st.push(42);
    st.display();
    st.peek();
    st.pop();
    st.display();
  cout <<  st.isEmpty();
    return 0;
}
