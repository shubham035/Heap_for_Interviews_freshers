// #include <iostream>
// #include<queue>
// #include<vector>
// #include<functional>
 #include<bits/stdc++.h>
using namespace std;

// MERGE K SORTED ARRAY'S


int main() {

// k no of sorted array 
    int k;
    cin>>k;

    vector<vector<int> >v(k);

    for(int i=0;i<k;i++){

        int size_of_vector;
        cin>>size_of_vector;

        v[i]=vector<int>(size_of_vector);
        for(int j=0;j<size_of_vector;j++){
            cin>>v[i][j];
        }
    }

    vector<int> idx(k,0);

    // take a pair to store the minm element and which vector it belongs to 
    // as if we pop from priority queue we have to increase the index of that element
    
    // priority_queue<int , vector<int>,greater<int> > pq;
    priority_queue<pair<int,int> , vector<pair<int,int> > ,greater< pair<int,int>> >pq;

    for(int i=0;i<k;i++){
        pq.push({v[i][0],i});
    }

    vector<int> ans;

    while(!pq.empty()){

        pair<int,int > p=pq.top();
          pq.pop();
        ans.push_back(p.first);

        if(idx[p.second]+1<v[p.second].size()){
            // {element , i};
            pq.push({v[p.second][idx[p.second]+1],p.second});
        }
        // increasing the index of the ith vector element whose element is root
        
        idx[p.second]++;
      
    }

// ans conatins the sorted array

    for(auto zee:ans){
        cout<<zee<<" ";
    }
/*
3
3 1 4 6
2 2 3
3 5 6 7

1 2 3 4 5 6 6 7 
*/

    return 0;
}
