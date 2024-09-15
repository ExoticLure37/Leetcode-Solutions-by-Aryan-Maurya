class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int r=0;
        int c=matrix[0].size()-1;
        while(r<=matrix.size()-1 && c>=0)
        {
            if(matrix[r][c]==target)    return true;
            if(matrix[r][c]>target) --c;
            else    ++r;
        }
        return false;
    }
};