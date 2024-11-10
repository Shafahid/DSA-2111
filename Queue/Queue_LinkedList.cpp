#include <iostream>
using namespace std;

struct Queue
{

    struct node
    {
        node *next;
        int val;
    };
    node *head=nullptr;
    node *tail=nullptr;

    void enqueue(int x)
    {

        //Your code starts here #001
    node *a = new node;
    a->next = NULL;
    a->val = x;
    if (tail == NULL)
    {
      // Queue is empty
      head = a;
      tail = a;
    }
    else
    {
      tail->next = a;
      tail = a;
    }
        //Your code ends here #001
    }

    int dequeue(){

        //Your code starts here #002
        if (!head){
        return -1;
    }
    else if (head == tail)
    {
      // Queue contains only one element
      int x = head->val;
      head = NULL;
      tail = NULL;
      return x;
    }
    else
    {
      // Queue contains more than one element
      int x = head->val;
      node *d = head;
      head = head->next;
      delete d;
      return x;
    }

        //Your code ends here #002


    }

    Queue* sortQueue(Queue* q){
    //Your code starts here #003
    if(q->head==q->tail){
        return q;
    }
    Queue *q1 = new Queue();
    q1->head = q->head;
    Queue *q2 = new Queue();
    while(q1->head){
        q2->head = q1->head->next;
        while(q2->head){
            if(q1->head->val > q2->head->val){
                 int t = q1->head->val;
                 q1->head->val = q2->head->val;
                 q2->head->val = t;
            }
            q2->head = q2->head->next;
        }
        q1->head = q1->head->next;
    }
    return q;
    //Your code ends here #003
}

};


int main()
{
    Queue *q = new Queue();
    int n;
    cin>>n;
    int v;
    for(int i=1;i<=n;i++){
        cin>>v;
        q->enqueue(v);
    }
    while(q->head!=nullptr){
        cout<<q->dequeue()<<endl;
    }
    return 0;

}
