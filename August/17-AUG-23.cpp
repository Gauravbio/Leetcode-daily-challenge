class Solution {

    bool check(int r,int c,int m,int n) {
        if(r<0 || c<0 || r>=m || c>=n) return 0;
        return 1;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<vector<int>> q;
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        vector<vector<bool>> vis(m,vector<bool>(n,0));

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(mat[i][j]==0) {
                    q.push({i,j,0});
                    vis[i][j]=1;
                }
            }
        }

        int drow[4]= {-1,0,0,1};
        int dcol[4]= {0,-1,1,0};

        while(!q.empty()) {
            auto front=q.front();
            int r=front[0];
            int c=front[1];
            int steps=front[2];
            q.pop();

            for(int i=0;i<4;i++) {
                int nrow=r+drow[i];
                int ncol=c+dcol[i];

                if(check(nrow,ncol,m,n) && !vis[nrow][ncol]) {
                    vis[nrow][ncol]=1;
                    ans[nrow][ncol]=steps+1;
                    q.push({nrow,ncol,steps+1});
                }
            }
        }

        return ans;
    }
};