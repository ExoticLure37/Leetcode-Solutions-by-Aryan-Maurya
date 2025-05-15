class Solution {
public:

    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        vector<string> res;

        int i=0;
        while(i<groups.size()){
            int j=i;
            int group=groups[i];
            while(j<groups.size() && groups[j]==groups[i]){
                j++;
            }
            string ele=words[i];
            res.push_back(ele);
            i=j;
        }

        return res; 
    }
};