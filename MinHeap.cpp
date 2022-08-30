#include<bits/stdc++.h>
using namespace std;
int M = 1e9+7;
void swap(int *x, int *y);

class MinHeap
{
    int *harr;
    int capac;
    int size;
public:
    
    MinHeap(int capac);
    void MinHeapify(int );
    
    int pa(int i) {return (i-2)/2;}
    int left(int i) {return (2*i)+1;}
    int right(int i) {return (2*i)+2;}

    int extractMin();

    void decreaseKey(int i, int new_val);
    int getMin() {return harr[0];}
    void deleteKey(int i);
    void insertKey(int k);
};

MinHeap::MinHeap(int cap)
{
    size=0;
    capac=cap;
    harr = new int[cap];
}

void MinHeap::insertKey(int k)
{
    if(size==capac)
    {
        cout<<"\nOverflow\n";
        return;
    }
    size++;
    int i=size-1;
    harr[i]=k;

    while (i!=0 && harr[pa(i)]>harr[i])
    {
        swap(&harr[i],&harr[pa(i)]);
        i=pa(i);
    }
}

void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i]=new_val;
    while (i!=0 && harr[pa(i)]>harr[i])
    {
        swap(&harr[i],&harr[pa(i)]);
        i=pa(i);
    }
}

int MinHeap::extractMin()
{
    if(size<=0) return M;
    if(size==1)
    {
        size--;
        return harr[0];
    }
    int root = harr[0];
    harr[0] = harr[size-1];
    size--;
    MinHeapify(0);
    return root;
}

void MinHeap::deleteKey(int i)
{
    decreaseKey(i,M);
    extractMin();
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int small = i;
    if(l<size&&harr[l]<harr[i]) small = l;
    if(r<size&&harr[r]<harr[small]) small = r;
    if(small!=i)
    {
        swap(&harr[i],&harr[small]);
        MinHeapify(i);
    }
}

void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    
}