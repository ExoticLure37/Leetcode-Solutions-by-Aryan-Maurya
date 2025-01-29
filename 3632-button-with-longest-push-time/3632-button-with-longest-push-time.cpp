class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int n = events.size();

        int start = events[0][1];

        for(int i=1;i<n;i++){
            if(events[i][1]-events[i-1][1] > start){
                start = events[i][1]-events[i-1][1];
            }
        }

        vector<int> b;

        if(events[0][1]==start) b.push_back(events[0][0]);

        for(int i=1;i<n;i++){
            if(events[i][1]-events[i-1][1] == start){
                b.push_back(events[i][0]);
            }
        }

        sort(b.begin(),b.end());
    
        return *b.begin();
    }
};