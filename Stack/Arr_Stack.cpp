#include <iostream>
using namespace std;
#define MAX 100
class stack
{
    int topIndex;
    int arr[MAX]; // fixed length 100

public:
    stack()
    {
        topIndex = -1;
    }
    void push(int value)
    {
        if (topIndex >= MAX - 1)
        {
            cout << "Stack is Full";
            return;
        }
        topIndex++;
        arr[topIndex] = value;
    }

    void pop()
    {
        if (topIndex < 0)
        {
            cout << "Stack is empty" << "\n";
            return;
        }
        cout << arr[topIndex];
        topIndex--;
    }

    void peek()
    {
        if (topIndex < 0)
        {
            cout << "sTACK IS Empty";
            return;
        }
        cout << arr[topIndex];
    }
    bool isEmpty()
    {
        return topIndex == -1;
    }
    void display()
    {
        if (topIndex < 0)
        {
            cout << "Stack is empty" << "\n";
            return;
        }
        for (int i = topIndex; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << "END";
    }
};
int main()
{

    stack st;
    st.push(12);
    st.display();
    // cout << st.isEmpty() << "\n";
    return 0;
}