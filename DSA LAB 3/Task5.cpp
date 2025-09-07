#include <iostream>
using namespace std;

class node
{
public:
  int data;
  node *next;
  node* prev;
  node(int val)
  {
    data = val;
    next = NULL;
    prev = NULL;
  }
};

void insertNode(node* &head, int val)
{
  node *newNode = new node(val);
  if (head == NULL)
  {
    head = newNode;
    return;
  }
  node *temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newNode;
}

void printList(node *head)
{
  while (head != NULL)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

void convertToDoubleList(node* &head)
{
  node* temp = head;
  node* next = NULL;
  node* DummyPrev = NULL;
  while(temp != NULL)
  {
    temp->prev = DummyPrev;
    next = temp->next;
    DummyPrev = temp;
    temp = temp->next;
  }
}

void convertToCircularList(node* &head)
{
  node* temp = head;
  while(temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = head;
}

void PrintingDouble(node* head)
{
  cout << "Printing the Double List using Prev Pointer to differentiate : " << endl;
  while(head->next != NULL)
  {
    head = head->next;
  }
  while(head != NULL)
  {
    cout << " Data : " << head->data << " ";
    head = head->prev;
  }
  cout << endl;
}

void printingCircular(node *head)
{
  cout << "Printing the Circular List : " << endl;

  node *temp = head;
  do
  {
    cout << temp->data << " ";
    temp = temp->next;
  } while (temp != head);
  cout << endl;
}

int main()
{
  node *head = NULL;

  for (int i = 1; i <= 8; i++)
  {
    insertNode(head, i);
  }
  printList(head);
  convertToDoubleList(head);
  PrintingDouble(head);
  convertToCircularList(head);
  printingCircular(head);
}
