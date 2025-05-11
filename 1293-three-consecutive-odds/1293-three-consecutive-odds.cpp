class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        
        for(int i=0;i+2<n;i++){
            int a=arr[i],b=arr[i+1],c=arr[i+2];
            if(a&1 && b&1 && c&1)   return true;
        }

        return false;
    }
};