class Solution {
public:
    int countDays(int days, vector<vector<int>>& a) {
        sort(a.begin(),a.end());
        int n=a.size();
        int last=0,ans=0;
        for(int i=0;i<n;i++){
            if(last < a[i][0] ) ans+=a[i][0] - last-1;
            last = max(last,a[i][1]);
        }

        if(last < days)     ans+=days-last;
        return ans;
    }
};