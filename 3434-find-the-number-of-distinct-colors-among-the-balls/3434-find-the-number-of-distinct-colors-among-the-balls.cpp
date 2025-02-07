class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int> color;             //{color:no.of balls}
        map<int,int> prev;              //{ball:prev.color}
        set<int> s;     

        vector<int> res;

        for(auto q:queries){
            int ball = q[0];
            int col = q[1];

            if(prev.find(ball)!=prev.end()){
                int p_col = prev[ball];
                color[p_col]--;
                if(color[p_col]==0){
                    s.erase(s.find(p_col));
                    color.erase(p_col);
                }
            }
            color[col]++;
            prev[ball]=col;
            s.insert(col);
            res.push_back(s.size());
        }

        return res;   
    }
};