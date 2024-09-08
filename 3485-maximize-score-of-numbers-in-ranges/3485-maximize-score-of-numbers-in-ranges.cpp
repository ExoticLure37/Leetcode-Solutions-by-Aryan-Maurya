class Solution {
public:
    int n;
    bool isValid(vector<int> &a,int mid,int d)
    {
        long long prev = a[0];
        for(int i=1;i<n;i++)
        {
            long long next = max(prev+mid,(long long)a[i]);
            if(next>a[i]+d) return false;
            prev=next;
        }
        return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        sort(start.begin(),start.end());
        n=start.size();
        int l=0;
        int h=start[n-1]+d-start[0];

        int ans=0;
        while(l<=h)
        {
            long long mid = l+(h-l)/2;
            if(isValid(start,mid,d))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        return ans;
    }
};