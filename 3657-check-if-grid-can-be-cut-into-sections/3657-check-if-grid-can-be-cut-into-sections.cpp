class Solution {
public:
    bool checkValidCuts(int N, vector<vector<int>>& r) {
        int n=r.size();
        map<int,int>mp;
        for(auto c:r){
            mp[c[1]]=max(mp[c[1]],c[3]);
        }
        int st=0;
        for(auto c:mp){
            st=c.second;
            break;
        }
        int cnt=0;
        for(auto c:mp)  cout<<c.first<<" "<<c.second<<endl;
        cout<<endl;
        for(auto c:mp){
            if(c.first<st)  st=max(st,c.second);
            else{
                cnt++;
                st=max(st,c.second);
            }
            if(cnt==2)  return 1;
        }

        mp.clear();
        for(auto c:r){
            mp[c[0]]=max(mp[c[0]],c[2]);
        }
        st=0;
        for(auto c:mp){
            st=c.second;
            break;
        }
        cnt=0;
        for(auto c:mp)  cout<<c.first<<" "<<c.second<<endl;
        cout<<endl;
        for(auto c:mp){
            if(c.first<st)  st=max(st,c.second);
            else{
                cnt++;
                st=max(st,c.second);
            }
            if(cnt==2)  return 1;
        }
        //for vertical
        return 0;
    }
};