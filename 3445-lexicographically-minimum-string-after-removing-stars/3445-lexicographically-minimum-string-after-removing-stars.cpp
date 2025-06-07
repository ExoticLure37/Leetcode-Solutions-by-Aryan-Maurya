class Solution {
public:
    string clearStars(string s) {
        int n=s.length(),fl=0;
        priority_queue<char, vector<char>, greater<char>> pq;
        vector<vector<int> > idx(26,vector<int> ());
        char ch;
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                ch =pq.top();
                s[idx[ch-'a'].back()]='!';
                idx[ch-'a'].pop_back();
                if(idx[ch-'a'].size()==0){
                    pq.pop();
                }
                continue;
            }
            if (idx[s[i] - 'a'].size() == 0){  
                pq.push(s[i]);
            }
            idx[s[i] - 'a'].push_back(i);
        }

        string res = "";
        for (char c: s){
            if (c >= 'a') { 
                res += c; 
            }
        }
        return res;
    }
};