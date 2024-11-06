class Solution {
public:
    vector<int> prefix_function(string s) {
        int n = (int)s.length();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        string aa=a+'#'+s;
        string bb=b+'#'+s;
        // cout<<"aa= "<<aa<<" bb="<<bb<<endl;
        vector<int> p1=prefix_function(aa);
        vector<int> p2=prefix_function(bb);
        vector<int> idx1,idx2;
        for(int i=0;i<=a.length()+s.length();i++){
            if(p1[i]==a.length())   idx1.push_back(i-(a.length())*2);
            // cout<<p1[i]<<" ";
        }
        for(int i=0;i<=b.length()+s.length();i++){
            if(p2[i]==b.length())   idx2.push_back(i-(b.length())*2);
            // cout<<p2[i]<<" ";
        }
        set<int> res;
        for(int i = 0, j = 0; i < idx1.size(); ++i){
            while(j < idx2.size() && idx1[i] > idx2[j] && abs(idx1[i] - idx2[j]) > k) j++;
            if(j < idx2.size() && abs(idx1[i] - idx2[j]) <= k) res.insert(idx1[i]);
        }
        // set<int> res;
        // for(auto c:idx1){
        //     for(auto l:idx2){
        //         if(abs(c-l)<=k) res.insert(c);
        //     }
        // }
        // cout<<endl;
        // for(auto c:idx2)    cout<<c<<" ";
        // cout<<endl;
        return vector<int> (res.begin(),res.end());
    }
};