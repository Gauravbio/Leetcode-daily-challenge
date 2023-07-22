class Solution {
    private:
    int possibility[8][8]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};

    double solve(int r,int c,int move,int n,vector<vector<vector<double>>> &dp){
        if(r<0 || c<0 || r>=n || c>=n) return 0;
        if(move==0) return 1;
        if(dp[r][c][move]!=-1) return dp[r][c][move];
        double prob=0;
        for(int i=0;i<8;i++) {
            prob+=(solve(r+possibility[i][0],c+possibility[i][1],move-1,n,dp)/8.0);
        }

        return dp[r][c][move]=prob;
    }
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        return solve(row,column,k,n,dp);
    }
};