class MyCalendarTwo {
public:
    map<int,int> m;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        int s=0;
        bool fl=1;
        for(auto &[a,b]:m){
            s+=b;
            if(s==3) {
                fl=0;
                break;
            }
        }
        if(fl) return true;
        m[start]--,m[end]++;
        return false;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */