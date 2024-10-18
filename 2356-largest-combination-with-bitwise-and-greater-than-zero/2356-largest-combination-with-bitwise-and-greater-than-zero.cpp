class Solution {
public:
    int n;
    int mx=0;
    // int solve(vector<int> &c,int idx,int tmp,int len)
    // {
    //     if(idx>=n)  return (tmp>0)? mx=max(mx,len):0;
    //     int p=solve(c,idx+1,tmp&c[idx],len+1);
    //     int q=solve(c,idx+1,tmp,len);
    //     return p+q;
    // }
    int largestCombination(vector<int>& c) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        n=c.size();
        // vector<int> v(32,0);
        for(int i=0;i<32;i++)
        {
            int cnt=0;
            for(auto num:c)
            {
                if((num>>i)&1)  cnt++;
            }
            mx=max(mx,cnt);
        }
        return mx;
    }

};