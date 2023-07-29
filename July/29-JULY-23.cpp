class Solution {
    double solve(int a,int b,unordered_map<int,unordered_map<int,double>> &dp) {
        if(a==0 && b==0) return (0.5);
        if(a==0) return 1;
        if(b==0) return 0;
        if(dp.count(a) && dp[a].count(b)) return dp[a][b];

        double ans=0;
        int temp=0;
        for(int i=0;i<4;i++) {
            ans+=(solve(max(0,a-(100-temp)),max(b-temp,0),dp)/4.0);
            temp+=25;
        }

        dp[a][b]=ans;
        return ans;
    }
public:
    double soupServings(int n) {
        if(n>5000) return 1;
        unordered_map<int,unordered_map<int,double>> dp;
        return solve(n,n,dp);
    }
};