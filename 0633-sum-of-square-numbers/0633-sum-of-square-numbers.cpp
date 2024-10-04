class Solution {
public:
    bool judgeSquareSum(int c) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        long long p=(long long)c;
        for(long long i=0;i*i<=p;i++)
        {
            int l=0,r=sqrt(p);
            while(l<=r)
            {
                int mid = (l+r)/2;
                long long val = mid*mid*1ll + i*i*1ll;
                if(val == p)  
                {
                    return true;
                }
                else if(val > p)
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
        }
        return false;
    }
};