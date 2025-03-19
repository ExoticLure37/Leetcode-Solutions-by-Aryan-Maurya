class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int cnt=0;
        long long val=0;
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        pq.push(1);
        int i=0;
        while(!pq.empty() && cnt!=n){
           long long mx=pq.top();
           val=mx;
           for(int j=0;j<primes.size();j++){
               pq.push(mx*primes[j]);
           }
           while(!pq.empty()&& mx==pq.top()){
               pq.pop();
           }
           cnt++;
        }
        return val;
    }
};