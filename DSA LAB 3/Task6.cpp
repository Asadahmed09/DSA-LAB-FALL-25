#include <iostream>
using namespace std;

class node
{
public:
  int data;
  node* next;
  node* child;
  node(int val)
  {
    data = val;
    next = child = NULL;
  }
};

void insertNode(node *&head, int val)
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

node *flatten(node *head)
{
  if (!head)
    return NULL;

  node *temp = head;
  while (temp)
  {
    if (temp->child)
    {
      node *nextNode = temp->next;
      temp->next = flatten(temp->child);
      temp->child = NULL;

      node *t = temp->next;
      while (t && t->next)
        t = t->next;

      if (nextNode)
        t->next = flatten(nextNode);
    }
    temp = temp->next;
  }
  return head;
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

int main()
{
  node *head = new node(1);
  head->next = new node(2);
  head->next->next = new node(3);
  head->next->child = new node(4);
  head->next->child->next = new node(5);

  head = flatten(head);
  node *temp = head;
  while (temp)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
}
