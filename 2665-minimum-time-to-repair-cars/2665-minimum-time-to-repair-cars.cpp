class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long n=ranks.size();
        sort(ranks.begin(),ranks.end(),greater());
        auto valid=[&](long long m){
            long long cnt=0;
            for(int i=0;i<n;i++){
                cnt+=floor(sqrt((double)m/(double)ranks[i]));
            }
            // cout<<" m= "<<m<<" cnt="<<cnt<<endl;
            return cnt>=cars;
        };
        long long l=1;
        long long r=1e14;
        long long ans=0;        
        while(l<=r){
            long long m=l+(r-l)/2;
            // cout<<"l="<<l<<" r="<<r;
            if(valid(m)){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};