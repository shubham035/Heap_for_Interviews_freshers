const double maxN=1e6;
class MedianFinder {
public:
    /** initialize your data structure here. */
    
    priority_queue<int> maxh;
    priority_queue<int , vector<int>, greater<int> >minh;
    double median=-maxN;
    MedianFinder() {
        ;
    }
    // insight :  when a number is added 
    void addNum(int num) {
        if(num>=median){
            minh.push(num);
        }
        else{
            maxh.push(num);
        }
        
        // balancing the heap on both side 
        if(minh.size()==maxh.size() || (minh.size()-maxh.size())==1 || (minh.size()-maxh.size())==-1){
            ;
        }
        else{
            if(minh.size()>maxh.size()){
                int t=minh.top();
                maxh.push(t);
                minh.pop();
            }
            else{
                
                int t=maxh.top();
                minh.push(t);
                maxh.pop();
            }
        }
        
        // finding the medain after num is inserted
        
            if(maxh.size()==minh.size()){
            median=double(maxh.top()+minh.top())/2.0;
        }
        else if(maxh.size()>minh.size()){
            median= maxh.top();
        }
        else
            median= minh.top();
        
    }
    
    double findMedian() {
        // return the median because it is stored after every data is inserted
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */