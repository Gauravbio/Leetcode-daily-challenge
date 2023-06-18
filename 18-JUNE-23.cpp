class Solution {
public:
    int drow[4]={-1,0,0,1};
    int dcol[4]={0,-1,1,0};
    int mod=1e9+7;

    bool isValid(int r,int c,int m,int n) {
        if(r<0 || c<0 || r>=m || c>=n) return 0;
        return 1;
    }

    int dfs(vector<vector<int>>& grid,int r,int c,int m,int n,vector<vector<int>> &dp) {
        if(dp[r][c]!=-1) return dp[r][c];
        long long ans=1;
        for(int i=0;i<4;i++) {
            int nrow=drow[i]+r;
            int ncol=dcol[i]+c;
            long long curr=0;
            if(isValid(nrow,ncol,m,n) && grid[r][c]<grid[nrow][ncol]) {
                curr=dfs(grid,nrow,ncol,m,n,dp)%mod;
            }
            ans=(ans+curr)%mod;
        }

        dp[r][c]=(ans%mod);
        return ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        long long ans=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                ans=(ans+dfs(grid,i,j,m,n,dp))%mod;
            }
        }
        return (ans%mod);
    }
};