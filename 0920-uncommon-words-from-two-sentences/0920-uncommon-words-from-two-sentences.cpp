class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        map<string,int > mp;
        int i=0;
        while(i<s1.length())
        {
            string s="";
            int j=i;
            while(s1[j]!=' ' && j<s1.length())
            {
                s+=s1[j];
                j++;
            }
            mp[s]++;
            cout << s << endl;
            i=j+1;
        } 
        i=0;
        map<string,int> mp2;
        while(i<s2.length())
        {
            string s="";
            int j=i;
            while(s2[j]!=' ' && j<s2.length())
            {
                s+=s2[j];
                j++;
            }
            mp2[s]++;
            i=j+1;
        } 
        vector<string> ans;
        for(auto i:mp)
        {
            if(i.second==1 && mp2.find(i.first)==mp2.end())
            {
                ans.push_back(i.first);
            }
        }
        for(auto i:mp2)
        {
            if(i.second==1 && mp.find(i.first)==mp.end())
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};