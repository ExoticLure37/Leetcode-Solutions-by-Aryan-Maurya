class Solution {
public:
    static bool cmp(pair<int,int> &a,pair<int,int> &b){
        if(a.first<b.first) return true;
        else if(a.first==b.first)   return a.second<b.second;
        return 0;
    }
    long long findScore(vector<int>& nums) {
        vector<pair<int,int> > a;
        int n=nums.size();
        for(int i=0;i<n;i++)    a.push_back({nums[i],i});
        sort(a.begin(),a.end(),cmp);
        set<int> s;
        int j=0;
        long long sc=0;
        while(s.size()<n){
            int sm=a[j].first,idx=a[j].second;
            if(s.count(idx)==0){
                sc+=sm;
                if(idx+1<n) s.insert(idx+1);
                s.insert(idx);
                if(idx-1>=0)    s.insert(idx-1);
            }
            else{
                j++;
            }
        }
        return sc;
    }
};