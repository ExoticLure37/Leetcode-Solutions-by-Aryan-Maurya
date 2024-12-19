class Solution {
public:
    int n;
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> left;
        n=capacity.size();
        int alreadyfull=0;
        for(int i=0;i<n;i++){
            if(capacity[i]-rocks[i] == 0)   alreadyfull++;
            else    left.push_back(capacity[i]-rocks[i]);
        }
        sort(left.begin(),left.end());
        int i=0;
        while(i<left.size()){
            if(left[i]<=additionalRocks){
                additionalRocks-=left[i];
                alreadyfull++;
            }
            else{
                break;
            }
            i++;
        }
        return alreadyfull;
    }
};