#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;
struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data=d;
        next=NULL;
    }
};

struct Queue
{
    Node *front, *last;
    int size = 0;
    Queue()
    {
        front=last=NULL;
    }

    bool enque(int x)
    {
        Node *tmp = new Node(x);
        size++;
        if(last==NULL)
        {
            front=last=tmp;
            return false;
        }
        last->next=tmp;
        last=tmp;
        return true;
    }
    
    int deque()
    {
        if(front==NULL) return M;
        size--;
        Node *tmp = front;
        int val = front->data;
        front = front -> next;
        if(front==NULL) last=NULL;
        delete(tmp);
        return val;
    }

    bool is_empty()
    {
        if(size==0) return true;
        return false;
    }
    
    int peek()
    {
        if(size==0) return M;
        return front->data;
    }
};
int main()
{
  
    Queue q;
    q.enque(10);
    q.enque(20);
    int a = q.deque();
    cout<<a<<endl;
    q.deque();
    q.enque(30);
    q.enque(40);
    q.enque(50);
    int b = q.deque();
    cout<<b<<endl;
    cout << "Queue Front : " << (q.front)->data << endl;
    cout << "Queue Last : " << (q.last)->data;
}