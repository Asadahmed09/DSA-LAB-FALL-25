#include "iostream"
using namespace std;
struct node{
    int data;
    struct node* link;
};
node* top = NULL;
 void push(int data)
 {
    node* temp = new node();
    if(!temp)
    {
        cout << "Heap Overflow " << endl;
        return ;
    }
    temp->data = data;
    temp->link = top;
    top = temp;

    cout << data << " Pushed into the stack" << endl;
 }
 
 void pop()
 {
    if(!top)
    {
        cout << " Stack is empty";
        return;
    }
    node *temp = top;
    top = top->link;
    delete temp;
 }

 void display()
 {
    node* temp = top;
    while(temp!=NULL)
    {
        cout << temp->data << endl;
        temp = temp->link;
    }
 }

 int main()
 {
    node* stack= new node();
    push(10);
    push(20);
    push(30);
    display();
 }
