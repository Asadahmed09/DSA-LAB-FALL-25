#include <iostream>
using namespace std;

class node
{
public:
  int data;
  node* next;
  node(int val)
  {
    data = val;
    next = NULL;
  }
};

node* reverseInGroups(node* head, int k)
{
  if (head == NULL)
    return NULL;

  node *prev = NULL;
  node *curr = head;
  node *next = NULL;
  int count = 0;

  while (curr != NULL && count < k)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    count++;
  }

  if (next != NULL)
  {
    head->next = reverseInGroups(next, k);
  }

  return prev;
}

void insertNode(node *&head, int val)
{
  node* newNode = new node(val);
  if (head == NULL)
  {
    head = newNode;
    return;
  }
  node* temp = head;
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

int main()
{
  node* head = NULL;

  for (int i = 1; i <= 8; i++)
  {
    insertNode(head, i);
  }
  cout << "Original List: ";
  printList(head);
  int k = 3;
  head = reverseInGroups(head, k);

  cout << "reversed in groups of " << k << ": ";
  printList(head);
}
