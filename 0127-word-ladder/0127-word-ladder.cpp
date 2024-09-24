class Solution {
public:
    int ladderLength(string s, string e, vector<string>& b) {
        // char a[4] = {'A','C','G','T'};
        if(s==e)    return 0;
        set<string> st(b.begin(),b.end());
        map<string,int > mp;
        queue<string>q;
        q.push(s);
        mp[s]++;
        int level=1;
        while(q.size())
        {
            int n = q.size();
            while(n--)
            {
                string curr = q.front();
                q.pop();
                if(curr==e) return level;
                for(auto c:"abcdefghijklmnopqrstuvwxyz")
                {
                    for(int i=0;i<10;i++)
                    {
                        string neigh = curr;
                        neigh[i]=c;
                        if(mp[neigh]==0 && st.find(neigh)!=st.end())
                        {
                            mp[neigh]++;
                            q.push(neigh);
                        }
                    }
                }
            }
            level++;
        }
        return 0;
    }
};