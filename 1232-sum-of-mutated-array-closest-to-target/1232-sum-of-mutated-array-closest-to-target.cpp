class Solution {
public:
    bool isValid(vector<int> &arr,int mid,int target,int &ans,int&res)
    {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=mid) sum+=arr[i];
            else    sum+=mid;
        }
        int diff = abs(sum - target);
        if(diff < ans || diff == ans && mid<res)
        {
            ans = diff;
            res = mid;
        }
        return sum>target;
    }
    int findBestValue(vector<int>& arr, int target) {
        int sum = accumulate(arr.begin(),arr.end(),0);
        int l=0,r=*max_element(arr.begin(),arr.end());
        if(sum==target) return *max_element(arr.begin(),arr.end());
        int ans = INT_MAX;
        int res = INT_MAX;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(isValid(arr,mid,target,ans,res))
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return res;
    }
};