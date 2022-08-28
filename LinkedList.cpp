#include<bits/stdc++.h>
using namespace std;
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))
struct Node
{
    int data;
    Node *next;
};

struct LinkedList
{
    int size = 0;
    Node *head = NULL;
    Node *q;
    
    void insert(int a[],int sizea)
    {
        for(int i=0;i<sizea;i++)
        {
            Node *p = new Node;
            p->data = a[i];
            p->next = NULL;
            size++;
            if(head == NULL)
            {
                head = p;
                q = head;
            }
            else
            {
                q->next = p;
                q = p;
            }
        }
    }

    void print()
    {
        Node *p = head;
        for(int i=0;i<size;i++)
        {
            cout<<p->data<<" ";
            p = p->next;
        }
    }

    bool add(int pos, int val)
    {
        pos--;
        if(pos<0||pos>size) return false;
        Node *p = new Node;
        size++;
        if(pos==0)
        {
            p->data=val;
            p->next=head;
            head=p;
        }
        else
        {
            Node *q = head;
            while(--pos) q=q->next;
            p->data = val;
            p->next = q->next;
            q->next = p;
        }
        return true;
    }

    bool erase(int pos)
    {
        pos--;
        if(pos<0||pos>=size) return false;
        Node *q = head;
        size--;
        if(pos==0)
        {
            head = q->next;
            delete q;
        }
        else
        {
            while(--pos) q=q->next;
            Node *p = q->next;
            q->next = p->next;
            delete p;
        }
        return true;
    }
};

int main(){
    LinkedList l1;
    int a[]={5,4,3,2,1};
    int arr_size = my_sizeof(a)/my_sizeof(a[0]);
	l1.insert(a,arr_size);
	l1.print();	
}

