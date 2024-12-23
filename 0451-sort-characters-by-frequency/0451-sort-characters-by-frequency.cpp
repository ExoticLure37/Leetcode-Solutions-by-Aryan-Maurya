class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        for(auto c:s)   mp[c]++;
        priority_queue<pair<int,char> > pq;
        for(auto c:mp)  pq.push({c.second,c.first});
        string res="";
        while(pq.size()){
            auto top=pq.top();
            int freq=top.first;
            char c=top.second;
            while(freq){
                res+=c;
                freq-=1;
            }
            pq.pop();
        }
        return res;
    }
};