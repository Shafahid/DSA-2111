#include<iostream>
using namespace std;
struct Stack
{
  struct node
  {
    node *next;
    int val;
  };

  node *head = nullptr;
  node *tail = nullptr;

  void push(int x)
  {
    node *a = new node();
    a->next = nullptr;
    a->val = x;
    if (!head)
    {
      head = a;
      tail = a;
    }
    else
    {
      a->next = head;
      head = a;
    }
  }

  void pop()
  {
    if (head==nullptr)
    {
      cout << "Stack empty\n";
    }
    else if (head == tail)
    {
      // Stack has only one element
      int x = head->val;
      head = nullptr;
      tail = nullptr;
      free(head);
    }
    else
    {
      node *d = head;
      head = d->next;
      int x = d->val;
      free(d);
    }
  }

  int peek()
  {
    if (head==nullptr)
    {
      cout << "Stack empty\n";
      return -1;
    }
    else
    {
      return head->val;
    }
  }
};

int main()
{
  Stack *st = new Stack();
  st->push(5);
  st->push(6);
  st->push(7);
  st->pop();
  cout<<st->peek();
  return 0;
}
