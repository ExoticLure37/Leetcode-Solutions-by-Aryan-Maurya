class Solution {
public:
    int mod=1e9+7;
    long long calc(long long len){
        // cout<<"l="<<len<<endl;
        long long p= (len*(len+1) * 1ll)/2;
        return p%mod;
    }
    int numSub(string s) {
        int n=s.length();
        long long l=0;
        long long res=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0'){
                res+=calc(l)%mod;
                l=0;
            }
            else    l++;
        }
        res+=calc(l)%mod;
        return res;
    }
};