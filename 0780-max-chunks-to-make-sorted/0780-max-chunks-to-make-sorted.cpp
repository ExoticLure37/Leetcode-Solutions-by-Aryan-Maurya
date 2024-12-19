class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0;
        int n=arr.size();
        if(n==1)
        {
            if(arr[0]==0) return 1;
        }
        vector<int> prefixMax(n),suffixMin(n);
        prefixMax[0] = arr[0];
        for(int i=1;i<n;i++)
        {
            prefixMax[i] = max(prefixMax[i-1] , arr[i]);
        }
        suffixMin[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffixMin[i] = min(suffixMin[i+1],arr[i]);
        }

        ans = 1;
        for(int i=0;i+1<n;i++)
        {
            if(prefixMax[i]<=suffixMin[i+1])  ans++;
        }

        return ans;

    }
};