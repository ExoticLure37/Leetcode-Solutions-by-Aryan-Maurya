class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        set<int> s;
               
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                s.insert(grid[i][j]%x);
                if(s.size()>=2) return -1; 
            }
        }

        vector<int> nums;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                nums.push_back(grid[i][j]);
            }
        }

        sort(nums.begin(),nums.end());

        n=nums.size();
        int res=0;
        
        int median;
        if(n&1){    
            median=nums[n/2];
            // cout<<median<<endl;
            for(auto c:nums){
                res+=abs(median-c)/x;
            }
        }
        else{
            median=nums[n/2];

            int a1=0,a2=0;

            for(auto c:nums){
                a1+=abs(median-c)/x;
            }

            median=nums[n/2-1];

            for(auto c:nums){
                a2+=abs(median-c)/x;
            }

            res=min(a1,a2);
        }

        return res;
        


    }
};