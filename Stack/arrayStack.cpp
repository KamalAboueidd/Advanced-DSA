#include <iostream>
using namespace std;
#define MAX 100

class ArrayStack
{
private:
    int arr[MAX];
    int topIndex;

public:
    ArrayStack()
    {
        topIndex = -1; // by def stack is empty ...
    }

    void push(int value)
    {
        if (topIndex >= MAX - 1)
        {
            cout << "Stack is fully " << "\n";
            return;
        }
        topIndex++;
        arr[topIndex] = value;
    }
    void pop()
    {
        if (topIndex < 0)
        {
            cout << "Stack Underflow! (Stack is empty)\n";
            return;
        }
        cout << arr[topIndex] << " popped from array stack.\n";
        topIndex--;
    }
    void peek()
    {
        if (topIndex < 0)
        {
            cout << "Stack is empty!\n";
            return;
        }
        cout << arr[topIndex] << "\n";
    }
    bool isEmpty()
    {
        return topIndex < 0;
    }
    void dispaly()
    {
        if (topIndex < 0)
        {
            cout << "Stack is empty";
            return;
        }

        for (int i = topIndex; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << "END \n";
    }
};
int main()
{

    ArrayStack st;
    st.push(12);
    st.peek();
    st.push(24);
    st.peek();
    st.dispaly();
    cout << st.isEmpty() << "\n";
    st.pop();
    st.dispaly();
    return 0;
}