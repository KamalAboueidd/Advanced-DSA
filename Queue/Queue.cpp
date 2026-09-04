#include <iostream>
using namespace std;
#define MAX 100

class ArrayQueue
{
private:
    int arr[MAX];
    int front;
    int rear;

public:
    ArrayQueue()
    {
        front = -1;
        rear = -1;
    }
    void enqueue(int value)
    {
        if (rear - 1 == MAX)
        {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        arr[rear] = value;
        cout << "Enqueued: " << value << endl;
    };
    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << arr[front] << " dequeued from queue" << endl;
        front++;
        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
    int peek()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        cout << "Front element is: " << arr[front] << endl;
        return arr[front];
    };
    bool isEmpty()
    {

        return (front == -1 || front > rear);
    }
     void display(){
          if(front == -1 || front > rear){
            cout << "Queue is empty" << endl;
            return;
          }
            cout << "Queue elements are: ";
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << "End of queue" << endl;
     }
    };
    int main()
    {
ArrayQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display(); 

    cout << "Front element is: " << q.peek() << "\n"; // 10

    q.dequeue();
    q.display(); // 20 <- 30 <- END

    return 0;
    }