class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        vector<set<string> > res;

        for(auto c:responses){
            set<string> p;
            for(auto k:c)   p.insert(k);
            res.push_back(p);
            cout<<endl;
        }

        map<string,int> mp;
        for(auto c:res){
            for(auto k:c){
                mp[k]++;
            }
        }

        int mx=0;
        vector<string>  data;
        for(auto c:mp){
            mx=max(mx,c.second);
        }

        for(auto c:mp){
            if(c.second==mx){
                data.push_back(c.first);
            }
        }

        sort(data.begin(),data.end());

        return data[0];
    }
};