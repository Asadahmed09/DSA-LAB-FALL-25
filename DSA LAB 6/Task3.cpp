#include "iostream"
using namespace std;
#define SIZE 5
class queue
{
    public:
    int arr[SIZE];
    int front , rear;
    queue()
    {
        front = rear = -1;
    }
    bool isEmpty()
    {
        if(front==-1)
        {
            return 1;
        }
        return 0;
    }
    bool isFull()
    {
        if(rear==SIZE-1)
        {
            cout << "Queue full" << endl;
            return 1;
        }
        return 0;
    }
    void enqueue(int data)
    {
        if(isFull()){
            cout << "Queue overflow" << endl;
            return;
        }

        if(front==-1) front = 0;
        arr[++rear] = data;

        cout << data << " Enqueued" << endl;
    }

    void dequeue()
    {
        if(isEmpty())
        {
            cout << "Queue underflow"<< endl;
            return;
        }
        if(front==rear)
        {
            cout << arr[front] << " Dequeued" << endl;
            front = rear = -1;
            return;
        }
        else
        {
            cout << arr[front] << " Dequeued" << endl;
            front++;
        }

    }

    void display()
    {
        if(front==-1)
        {
            cout << "queue empty" << endl;
            return;
        }
        for(int i = front ; i <= rear ; i++)
        {
            cout << "data : " << arr[i] << endl;
        }
    }
};
int main()
{
    queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.display();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.display();
    q1.enqueue(4);
    q1.display();
}
