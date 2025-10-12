#include <stdio.h>
#include "iostream"
int q[100];
int f = -1;
int r = -1;
int cap = 5;

int isFull()
{
    return ((r + 1) % cap) == f;
}

int isEmpty()
{
    return f == -1;
}

void enq(int x)
{
    if (isFull())
    {
        printf("Overflow\n");
        return;
    }
    if (isEmpty())
    {
        f = 0;
        r = 0;
        q[r] = x;
        return;
    }
    r = (r + 1) % cap;
    q[r] = x;
}

int deq()
{
    if (isEmpty())
    {
        printf("Underflow\n");
        return -1;
    }
    int v = q[f];
    if (f == r)
    {
        f = -1;
        r = -1;
    }
    else
    {
        f = (f + 1) % cap;
    }
    return v;
}

void disp()
{
    if (isEmpty())
    {
        printf("Queue empty\n");
        return;
    }
    int i = f;
    while (1)
    {
        printf("%d ", q[i]);
        if (i == r) break;
        i = (i + 1) % cap;
    }
    printf("\n");
}

int main()
{
    enq(10);
    enq(20);
    enq(30);
    enq(40);
    enq(50);
    disp();
    enq(60);
    printf("%d removed\n", deq());
    printf("%d removed\n", deq());
    disp();
    enq(60);
    enq(70);
    disp();
    enq(80);
}
