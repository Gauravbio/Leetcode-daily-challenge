class Solution {
    int solve(string &s1,string &s2,int i,int j,vector<vector<int>> &dp) {
        if(i<0 && j<0) return 0;
        if(dp[i+1][j+1]!=-1) return dp[i+1][j+1];

        int ans=0;
        if(i>=0 && j>=0 && s1[i]==s2[j]) {
            ans=solve(s1,s2,i-1,j-1,dp);
        }
        else {
            int f=INT_MAX;
            int s=INT_MAX;
            if(i>=0) f= s1[i] + solve(s1,s2,i-1,j,dp);
            if(j>=0) s= s2[j] +solve(s1,s2,i,j-1,dp);
            ans=min(f,s);
        }
        dp[i+1][j+1]=ans;
        return ans;
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.size();
        int n=size(s2);
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(s1,s2,m-1,n-1,dp);
    }
};