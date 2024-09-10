class Solution {
public:
    long long isValid(long long a,long long b,long long c,long long mid)
    {
        return ((mid/a)+(mid/b)+(mid/c)-(mid/lcm(a,b))-(mid/lcm(a,c))-(mid/lcm(b,c))+(mid/(lcm(a,lcm(b,c)))));
    }
    long long lcm(long long a,long long b)
    {
        return (a*b*1ll)/(__gcd(a,b));
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int l=0,r=2e9;
        int ans=0;

        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(isValid(a,b,c,mid) >=(long long)n )
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};