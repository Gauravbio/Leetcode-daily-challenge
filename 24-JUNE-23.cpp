class Solution {
public:
    int solve(vector<int>& rods,int n,int index,int diff,vector<vector<int>> &dp) {
        if(index==n) {
            if(diff==0) return 0;
            return INT_MIN;
        }
        if(dp[index][diff+5000]!=-1) return dp[index][diff+5000];

        int inc_1=rods[index]+solve(rods,n,index+1,diff+rods[index],dp);
        int inc_2=solve(rods,n,index+1,diff-rods[index],dp);
        int exc=solve(rods,n,index+1,diff,dp);

        dp[index][diff+5000]=max(inc_1,max(inc_2,exc));
        return dp[index][diff+5000];
    }
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        int sum=0;
        for(int i=0;i<n;i++) sum+=rods[i];
        vector<vector<int>> dp(n+1,vector<int>(10001,-1));
        return solve(rods,n,0,0,dp);
        // return 0;
    }
};