class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        int n=gs.size();

        vector<vector<int> > res;
        vector<vector<int> > count(n+1);

        for(int i=0;i<n;i++){
            int person=i;
            int groupSize=gs[i];

            count[groupSize].push_back(person);

            if(count[groupSize].size()==groupSize){
                vector<int> group=count[groupSize];
                res.push_back(group);
                count[groupSize].clear();
            }
        }

        return res;
    }
};