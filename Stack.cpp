#include<bits/stdc++.h>
using namespace std;
#define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))
const int M=1e9+7;
struct Node
{
    int data;
    Node *next;
};

struct Stack
{
    Node *head = NULL;
    Node *q;
    int size = 0;

    void insert(int a[],int sizea)
    {
        for(int i=0;i<sizea;i++)
        {
            Node *p = new Node;
            p->data = a[i];
            p->next = NULL;
            size++;
            if(head==NULL)
            {
                head=p;
                q=head;
            }
            else
            {
                q->next=p;
                q=p;
            }
        }
    }

    void insert()
    {
        Node *p = head;
        for(int i=0;i<size;i++)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
    }

    bool add(int pos,int val)
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
            q=head;
            while(--pos) q=q->next;
            p->data=val;
            p->next=q->next;
            q->next=p;
        }
        return true;
    }
    bool erase(int pos)
    {
        pos--;
        if(pos<0||pos>=size) return false;
        q=head;
        size--;
        if(pos==0)
        {
            head=q->next;
            delete q;
        }
        else
        {
            while(--pos) q=q->next;
            Node *p = q->next;
            q->next=p->next;
            delete p;
        }
        return true;
    }

    bool replace(int pos,int val)
    {
        pos--;
        if(pos<0||pos>=size) return false;
        q = head;
        while(--pos) q=q->next;
        q->data=val;
        return true;
    }

    void push(int val)
    {
        // add(1,val);
        Node *p = new Node;
        size++;
        p->data = val;
        p->next = head;
        head = p;
    }

    int pop()
    {
        // erase(1);
        if(size==0) return M;
        q = head;
        size--;
        head = q->next;
        int val=q->data;
        delete q;
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
        return head->data;
    }
};

int main()
{
    string s;
    cin>>s;
    Stack s1;
    for(int i=0;i<s.length();i++)
    {
    	if(s[i]=='(') s1.push(1);
    	if(s[i]==')')
    	{
    		if(s1.is_empty())
    		{
    			cout<<"bo ngoac ko hop le";
    			return 0;
    		}
    		s1.pop();
    	}
    }
    if(!s1.is_empty()) cout<<"bo ngoac ko hop le";
    else cout<<"bo ngoac hop le";
    return 0;
}