class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long> pq;
        for(auto c:gifts){
            pq.push(c);
        }
        while(k--){
            auto c=pq.top();
            pq.pop();
            long long j=floor(sqrt(c));
            pq.push(j);
        }
        long long sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};