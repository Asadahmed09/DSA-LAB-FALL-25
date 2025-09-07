#include "iostream"
using namespace std;
class node
{
public:
  int data;
  node *next;
  node(int val)
  {
    data = val;
    next = NULL;
  }
};
void insertNode(node* &head, int val)
{
  node *newNode = new node(val);
  if (head == NULL)
  {
    head = newNode;
    newNode->next = head;
    return;
  }

  node* temp = head;
  while (temp->next != head)
  {
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->next = head;
}

void printList(node *head)
{
  node* temp = head;
  do
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  while (temp != head);
  cout << endl;
}

int deleteKthElement(node* &head, int k)
{
  node *prev = head;

  while (prev->next != head)
  {
    prev = prev->next;
  }
  while (prev != prev->next)
  {
    for (int i = 1; i < k; i++)
    {
      prev = prev->next;
    }

    node *toDelete = prev->next;
    cout << "eliminated : " << toDelete->data << endl;
    prev->next = toDelete->next;

    if (toDelete == head)
    {
      head = head->next;
    }

    delete toDelete;
  }
  return prev->data;
}

int main()
{
  node *head = NULL;
  insertNode(head, 10);
  insertNode(head, 20);
  insertNode(head, 30);
  insertNode(head, 40);
  insertNode(head, 50);
  insertNode(head, 60);
  insertNode(head, 70);
  printList(head);
  deleteKthElement(head,3);
  printList(head);
}
