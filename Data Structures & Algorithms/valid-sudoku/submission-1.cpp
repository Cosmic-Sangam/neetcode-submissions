class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9] = {0};
        int cols[9][9] = {0};
        int boxes[9][9] = {0};
        int n = board.size();
        int m = board[0].size();

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(board[i][j]=='.'){
                    continue;
                }

                int num = board[i][j] - '1';
                int box = (i/3)*3 + j/3;

                if(rows[i][num]|| cols[j][num] || boxes[box][num]){
                    return false;
                }
                rows[i][num] = 1;
                cols[j][num] = 1;
                boxes[box][num] = 1;
            }
        }
        return true;
    }
};
