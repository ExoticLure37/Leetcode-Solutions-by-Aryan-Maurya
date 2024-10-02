class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> a(arr.begin(),arr.end());
        sort(a.begin(),a.end());
        int n=arr.size();
        map<int,int> mp;
        int k=1;
        for(int i=0;i<n;i++)
        {
            if(mp.find(a[i])==mp.end())     
            {
                mp[a[i]]=k++;
            } 
        }
        vector<int> ans;
        for(auto i:arr)
        {
            ans.push_back(mp[i]);
        }
        return ans;
    }
};