#include <iostream>
#include<queue>
// #include<bits/stdc++.h>
using namespace std;

/*

c++ stl implementation
under the class priority_queue

function:
top,pop,push;

*/

int main() {

    // stl 
    
    // max heap
   // priority_queue<int> pq;

    // min heap
    priority_queue<int, vector<int> ,greater<int> > pq;
    
    int a[10]={5,6,17,8,19,1,11};

    // insert these in pq

    for(int i=0;i<7;i++){
        pq.push(a[i]);
    }

// check priority_queue is empty or not 

    while(!pq.empty()){
        // gives top element
        cout<<pq.top()<<" ";
        // deletes the root element
        pq.pop();
    }
    cout<<endl;

// output max heap 19 17 11 8 6 5 1 
// output min heap 1 5 6 8 11 17 19 
    return 0;
}
