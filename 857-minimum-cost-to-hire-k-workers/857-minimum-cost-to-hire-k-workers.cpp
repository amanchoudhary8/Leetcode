class Solution {
public:
    
    //     double mincostToHireWorkers(vector<int> &q, vector<int> &w, int K) {
    //     vector<vector<double>> workers;
    //     for (int i = 0; i < q.size(); ++i)
    //         workers.push_back({(double)(w[i]) / q[i], (double)q[i]});
    //     sort(workers.begin(), workers.end());
    //     double res = DBL_MAX, qsum = 0;
    //     priority_queue<int> pq;
    //     for (auto worker: workers) {
    //         qsum += worker[1], pq.push(worker[1]);
    //         if (pq.size() > K) qsum -= pq.top(), pq.pop();
    //         if (pq.size() == K) res = min(res, qsum * worker[0]);
    //     }
    //     return res;
    // }
    
    
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<vector<double>> v;
        int n=quality.size();
        for(int i=0;i<n;i++)
            v.push_back({(double)(wage[i])/quality[i],(double)quality[i]});
        
        sort(v.begin(),v.end());
        double ans=DBL_MAX,sum=0;
        priority_queue<double> pq;
        for(int i=0;i<n;i++){
            sum+=v[i][1];
            pq.push(v[i][1]);
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k) ans=min(ans,v[i][0]*sum);
        }
        return ans;
    }
    
};