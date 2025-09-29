#include"iostream"
using namespace std;
class stack
{
    public:
    int* arr;
    int size;
    int top = -1;
    stack(int size){
        this->size = size;
        arr = new int[size];
    }
   
    bool push(int x){
        if(top >= size-1)
        {
            cout << "Stack overflow" << endl;
            return 0;
        }
        else
        {
            arr[++top] = x;
            cout << x << " Pushed into stack" << endl;
            return true;
        }
    }
    int pop(){
        if(top < 0)
        {
            cout <<"stack is empty" << endl;
            return 0;
        }
        else
        {
            int x = arr[top--];
            cout << x << " Popped from the stack" << endl;
        }
    }
    int peek(){
        if(top < 0)
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        else{
            int x = arr[top];
            return x;
        }
    }
    bool isEmpty(){
        if(top < 0) return 1;
        else return 0;
    }

};
int main()
{
    stack s1(5);
    s1.peek();
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
}
