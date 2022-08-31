#include<bits/stdc++.h>
using namespace std;

const int M = -1e9;

void swap(int *x,int *y);

class minheap
{
    int *harr;
    int capac;
    int size;
public:
    
    minheap(int capac);
    void Minheapify(int );
    
    int pa(int i) {return (i-2)/2;}
    int left(int i) {return i*2+1;}
    int right(int i) {return i*2+2;}

    int extractmin();

    void decreasekey(int i, int new_val);

    int getmin() {return harr[0];}
    void deletekey(int i);
    void insertkey(int k);
};

minheap::minheap(int cap)
{
    capac=cap;
    size=0;
    harr = new int[cap];
}

void minheap::insertkey(int k)
{
    if(size==capac)
    {
        cout<<"overflow";
        return;
    }
    size++;
    int i=size-1;
    harr[i]=k;
    while(i!=0&&harr[pa(i)]>harr[i])
    {
        swap(&harr[i],&harr[pa(i)]);
        i=pa(i);
    }
}

void minheap::decreasekey(int i, int new_val)
{
    harr[i] = new_val;
    while(i!=0&&harr[pa(i)]>harr[i])
    {
        swap(&harr[i],&harr[pa(i)]);
        i=pa(i);
    }
}

int minheap::extractmin()
{
    if(size<=0) return M;
    if(size==1)
    {
        size--;
        return harr[0];
    }
    int root = harr[0];
    harr[0]=harr[size-1];
    size--;
    Minheapify(0);
    return root;
}

void minheap::deletekey(int i)
{
    decreasekey(i,M);
    extractmin();
}

void minheap::Minheapify(int i)
{
    int l = left(i);
    int r = right(i);
    int small = i;
    if(l<size&&harr[l]<harr[i]) small = l;
    if(r<size&&harr[r]<harr[small]) small = r;
    if(small!=i)
    {
        swap(&harr[i],&harr[small]);
        Minheapify(small);
    }
}

void swap(int *x,int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}