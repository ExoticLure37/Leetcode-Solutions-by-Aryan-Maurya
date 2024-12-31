class Solution {
public:
    static bool cmp(pair<int,int> &a,pair<int,int> &b){
        if(a.first>b.second)return 1;
        // else if(a.first==b.first)   return a.second>b.second;
        return 0;
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n=plantTime.size();
        vector<pair<int,int> > v;
        for(int i=0;i<n;i++){
            v.push_back({growTime[i],plantTime[i]});
        }
        sort(v.begin(),v.end(),greater<pair<int,int> >());
        int curr=0,mx=0;
        for(auto c:v){
            curr+=c.second;
            mx=max(mx,curr+c.first);
        }
        return mx;
    }
};