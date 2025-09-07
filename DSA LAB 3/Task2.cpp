#include <iostream>
using namespace std;

class node
{
public:
  int data;
  node *next;
  node(int val = 0)
  {
    data = val;
    next = NULL;
  }
};

void insertNode(node *&head, int data)
{
  node *newNode = new node(data);
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

void printNode(node *head)
{
  while (head)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

node *mergeSorted(node *a, node *b)
{
  if (!a)
    return b;
  if (!b)
    return a;

  node *result = NULL;

  if (a->data <= b->data)
  {
    result = a;
    result->next = mergeSorted(a->next, b);
  }
  else
  {
    result = b;
    result->next = mergeSorted(a, b->next);
  }
  return result;
}

int main()
{
  node *firstHead = NULL;
  insertNode(firstHead, 1);
  insertNode(firstHead, 7);
  insertNode(firstHead, 5);

  node *secondHead = NULL;
  insertNode(secondHead, 2);
  insertNode(secondHead, 4);
  insertNode(secondHead, 6);
  insertNode(secondHead, 9);

  printNode(firstHead);

  printNode(secondHead);

  node *merged = mergeSorted(firstHead, secondHead);
  cout << "Merged List: ";
  printNode(merged);

}
