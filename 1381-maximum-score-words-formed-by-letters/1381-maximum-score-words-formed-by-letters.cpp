class Solution {
public:
    vector<int> cost;
    int n;
    bool valid(string word,map<char,int> &freq){
        map<char,int> mp;
        for(auto c:word)    mp[c]++;
        for(auto& c:mp){
            if(freq[c.first]<c.second)  return false;
        }
        return true;
    }
    int solve(vector<string>&words,int idx,map<char,int> &freq,int res){
        if(idx==n)  return res;
        int tell=valid(words[idx],freq);
        int p=0,q=0,r=0;
        if(tell==true){
            int amt=0;
            string word=words[idx];
            for(auto c:word)    amt+=cost[c-'a'],freq[c]--;
            q=solve(words,idx+1,freq,res+amt);
            for(auto c:word)    freq[c]++;
            p=0+solve(words,idx+1,freq,res);
        }
        else
            r=solve(words,idx+1,freq,res);
        return max({p,q,r});
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        map<char,int> freq;
        for(auto c:letters) freq[c]++;
        cost=score;
        n=words.size();
        return solve(words,0,freq,0);
    }
};