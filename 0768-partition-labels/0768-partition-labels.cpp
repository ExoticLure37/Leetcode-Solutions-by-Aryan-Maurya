class Solution {
public:
    vector<int> partitionLabels(string s) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        map<char,int> start,ending;
        for(int i=0;i<s.length();i++)
        {
            // if(start.find(s[i])==start.end())
            start[s[i]]=i;
        }
        int mx = 0,p=0;
        vector<int> ans;
        for(int i=0 ; i<s.length(); i++)
        {
            mx = max(mx , start[s[i]]);
            if(i==mx)
            {
                ans.push_back(mx - p + 1);
                p = i+1;
            }
        }
        return ans;

    }
};