class Solution {
public:

    void bfs(vector<vector<char>>&grid,vector<vector<int>>&visit,int row,int col){
        visit[row][col] = 1;

        queue<pair<int,int>>q;
        q.push({row,col});
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            row = q.front().first;
            col = q.front().second;
            q.pop();

            int delRow[] = {-1,0,1,0};
            int delCol[] = {0,1,0,-1};

            for(int i=0;i<4;i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow>=0 && nrow<n &&
                ncol>=0 && ncol<m &&
                grid[nrow][ncol]=='1' &&
                !visit[nrow][ncol])
                {
                    visit[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        int count =0;
        for(int row =0;row<n;row++){
            for(int col = 0;col<m;col++){
                if(!vis[row][col] && grid[row][col]== '1'){
                    count++;
                    bfs(grid,vis,row,col);
                }
            }
        }
        return count;
    }
};
