class Solution {
public:
    bool checkBlock(const vector<vector<char>>& board, int startRow, int startCol) {
    set<char> seen;
    
    for (int i = startRow; i < startRow + 3; ++i) {
        for (int j = startCol; j < startCol + 3; ++j) {
            char num = board[i][j];
            if (num!='.' && (num < '1' || num >'9' || seen.count(num))) {
                // cout<<"Start row "<<startRow<<" startcol "<<startCol<<endl;
                return false; 
            }
            seen.insert(num);
        }
    }
    return true;
}
    bool isValidSudoku(vector<vector<char>>& board) {
        // row check
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);.
        for(int i=0;i<9;i++)
        {
            set<char> s;
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.' && s.count(board[i][j])>0){ return false;}
                s.insert(board[i][j]);
            }
        }

        //column check
        for(int i=0;i<9;i++)
        {
            set<char> s;
            for(int j=0;j<9;j++)
            {
                if(board[j][i]!='.' && s.count(board[j][i])>0){ return false;}
                s.insert(board[j][i]);
            }
        }

        // block check
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!checkBlock(board, i, j)) {
                    // cout<<"FALSE 3";
                    return false; 
                }
            }
        }
        return true;
    }
};