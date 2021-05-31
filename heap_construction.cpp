#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Heap{

    vector<int> v;
    // configuration  ie. tell whether heap is minheap or max Heap
    // if minHeap is true min heap 
    // if false then it is max Heap
    
    bool minHeap;

    bool cmp(const int a, const int b){

            if(minHeap){
                return a<b;
            }
            return a>b;
        }

    void heapify(int i){

        int left=2*i;
        int right=2*i+1;
        // assume current index  is minimum
        int minIndex=i;
        if(left<v.size() && cmp(v[left],v[i])){
            minIndex=left;
        }

        if(right<v.size() && cmp(v[right],v[minIndex])){
            minIndex=right;
        }

        if(minIndex!=i){
            swap(v[i],v[minIndex]);
            heapify(minIndex);
        }

    }


    public:

        Heap(bool type=true){
            minHeap=type;
            // block the 0th index of vector
            v.push_back(-1);
        }

    
    
    // O(log(N)) time for each operation

    void push(int data){
        // insert at last 
        v.push_back(data);
        // take the last element to restore heap property
        // restoring the heap order property
        
        int index=v.size()-1;
        int parent=index/2;
        
        // writing cmp function such that we will go into the loop if we have to swap 
        // it ie. heap is stored in wrong order by inserting the last element  
        while(index>1 && cmp(v[index],v[parent])){

            swap(v[index],v[parent]);
            index=parent;
            parent=parent/2;
        }
    }

    bool empty(){
        return v.size()==1;
    }

    int top(){
        return v[1];
    }

    // remove the top most / root element
    void pop(){
        /*
        1.Swap first and Last Node
        2. pop last Node 
        3.heapify(root) ie. Heapify(1)
         1 is the index of root 
         0(log(N)) time for each operation
        */

        int last=v.size()-1;
        swap(v[1],v[last]);
        v.pop_back();
        // heapify put the elemnt in correct place

        heapify(1);
    }


};

int main() {
    Heap h(false);
    // Heap h; min Heap;
    h.push(20);
    h.push(15);
    h.push(5);
    h.push(12);
    h.push(2);

    //cout<<h.top()<<endl;
    // 20 max Heap
    // 2 min Heap

    while(!h.empty()){
        cout<<h.top()<<" ";
        h.pop();
    }
    // 20 15 12 5 2  max heap
    
    return 0;
}
