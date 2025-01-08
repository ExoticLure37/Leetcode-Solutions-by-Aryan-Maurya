class Solution {
public:
    long long res=-1;
    int n,m;
    int dx[8]={-1,0,+1,0,+1,-1,-1,+1};
    int dy[8]={0,+1,0,-1,+1,-1,+1,-1};
    map<long long,long long> mp;
    bool valid(int x,int y){
        return x>=0 && x<n && y>=0 && y<m;
    }
    bool chk(long long num){
        for(int i=2;i*i<=num;i++){
            if(num%i==0)    return 0;
        }
        if(num>10)  return 1;
        return 0;
    }

    int mostFrequentPrime(vector<vector<int>>& mat) {
        n=mat.size();
        m=mat[0].size(); 
        int drow[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dcol[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                for(int k = 0;k<8;k++){
                    int digit = mat[i][j];
                    int row = i+drow[k];
                    int col = j+dcol[k];
                    while(row>=0 && row<n && col>=0 && col<m){
                        digit = digit*10+mat[row][col];
                        if(digit>10){
                            if(chk(digit)) mp[digit]++;
                        }
                        row += drow[k];
                        col += dcol[k];
                    }
                }
            }
        }
        if(mp.empty()) return -1;
        long long freq = 0;
        long long ans;
        for(auto it:mp){
            if(it.second>=freq){
                if(freq == it.second) ans = max(ans,it.first);
                else{
                    freq = it.second;
                    ans = it.first;
                }
            }
        }
        return ans;
    }
};