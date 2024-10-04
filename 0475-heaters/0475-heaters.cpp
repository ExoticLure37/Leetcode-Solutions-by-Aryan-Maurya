class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int l=0;
        int r=1e9+10;
        int n=houses.size();
        int m=heaters.size();
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        auto ok=[&](int mid)
        {   
            int i=0;    //heaters
            int j=0;    //houses
            while(j<n)
            {
                if(i==m)    return false;
                int r1=heaters[i]-mid;
                int r2=heaters[i]+mid;
                if(houses[j]<r1 || houses[j]>r2)
                {
                    i++;
                }
                else
                {
                    j++;
                }
            }
            return true;
        };
        int ans=1e9+10;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(ok(mid))
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