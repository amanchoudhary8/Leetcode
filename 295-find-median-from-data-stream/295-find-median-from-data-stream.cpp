class MedianFinder {
public:
    priority_queue<int> lo;
    priority_queue<int,vector<int>,greater<int>> hi;
    MedianFinder() {
      
    }
    
    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top());
        lo.pop();
        if(hi.size()>lo.size()){
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        if(hi.size()<lo.size()) return lo.top();
        return ((double)lo.top()+(double)hi.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */