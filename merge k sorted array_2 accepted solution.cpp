class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //code here
        
        int idx[k]={0};
        priority_queue<pair<int,int> ,vector<pair<int,int >>, greater<pair<int,int >> >pq;
        
        // {value , index of array}
        
        for(int i=0;i<k;i++){
           // cout<<arr[i][0]<<endl;
            pq.push({arr[i][0],i});
            
        }
    
        
        vector<int> ans;
        
        while(!pq.empty()){
           
            int val=pq.top().first;
            int index=pq.top().second;
          
            
            if(index<(k) && idx[index]<(k-1)){
                 pq.push({arr[index][idx[index]+1],index});
            }
          
            pq.pop();
            ans.push_back(val);
            
            idx[index]++;
        }
        
        return ans;
        
    }
};