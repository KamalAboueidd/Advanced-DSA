#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int *arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    CircularQueue(int size)
    {
        capacity = size;
        arr = new int[capacity];
        front = rear = count = 0;
    }

    // 1. Destructor لمنع الـ Memory Leak
    ~CircularQueue()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    bool isFull()
    {
        return count == capacity;
    }

    // Time: O(1) | Space: O(1)
    void Enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is Full!\n";
            return;
        }
        arr[rear] = value;
        rear = (rear + 1) % capacity;
        count++;
    }

    // Time: O(1) | Space: O(1)
    int Dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!\n";
            return -1; 
        }
        int value = arr[front];
        front = (front + 1) % capacity;
        count--;
        return value;
    }

    // Time: O(n) | Space: O(1)
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!\n";
            return;
        }

        cout << "Queue elements: ";
        for (int i = 0; i < count; i++)
        {
            int index = (front + i) % capacity;
            cout << arr[index] << " ";
        }
        cout << "\n";
    }
};

int main()
{
    CircularQueue Cq(5);

    Cq.Enqueue(10);
    Cq.Enqueue(20);
    Cq.Enqueue(30);

    Cq.display(); // 10 20 30

    cout << "Removed: " << Cq.Dequeue() << "\n"; // 10
    Cq.display(); // 20 30

    return 0;
}