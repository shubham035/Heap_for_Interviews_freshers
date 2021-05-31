#include <iostream>
#include<queue>
#include<vector>
#include<functional>
// #include<bits/stdc++.h>
using namespace std;

// give cars 2d  car find k nearest/farthest
// distance 


class Car{

public:
    int x;
    int y;
    int id;
    Car(int id, int x, int y){
        this->id=id;
        this->x=x;
        this->y=y;
    }

    int dist(){
        return x*x+y*y;
    }

    void print(){
        cout<<"ID "<<id<<" ";
        cout<<" location "<<x<<" "<<y<<endl;
    }
};

// campare two cars functors

class carCompare{
 
public:
       // method to overload () operator;
    // void operator()(int a, int b)
    bool operator()(Car a,Car b){
      //  cout<<"comparing "<<a<<" and "<<b<<endl;

    // returning nearest distance
    
    // max heap
    // return a.dist()<b.dist();
    // min heap
      return a.dist()>b.dist();

    }

};

int main() {

    // carCompare cc;
    // cc( 5,9);
    // min heap
    priority_queue<Car, vector<Car>,carCompare > pq;
    
    int x[10]={5,6,7,8,11,9,4,7,0,2};
    int y[10]={1,2,0,4,6,5,1,9,1,3};


    for(int i=0;i<=9;i++){
        Car c(i,x[i],y[i]);
        pq.push(c);
    }

    while(!pq.empty()){
        Car c=pq.top();
        c.print();
        pq.pop();
    }
    /*
    nearest element;
    
    ID 8  location 0 1
ID 9  location 2 3
ID 6  location 4 1
ID 0  location 5 1
ID 1  location 6 2
ID 2  location 7 0
ID 3  location 8 4
ID 5  location 9 5
ID 7  location 7 9
ID 4  location 11 6
    */
    return 0;
}
