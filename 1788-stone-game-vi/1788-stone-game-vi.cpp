class Solution {
public:
    int stoneGameVI(vector<int>& av, vector<int>& bv) {
        priority_queue<pair<int,int>>pq;
        int n=av.size();
        for(int i=0;i<av.size();i++){
            pq.push({(av[i]+bv[i]),i});
        }
        vector<int> p(n,-1);
        int alice=1;
        while(!pq.empty()){
            auto node=pq.top();
            int idx=node.second;
            p[idx]=alice;
            alice=!alice;
            pq.pop();
        }
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(p[i]==1) a+=av[i];
            else    b+=bv[i];
        }
        if(a>b) return 1;
        else if(a<b)    return -1;
        return 0;
    }
};