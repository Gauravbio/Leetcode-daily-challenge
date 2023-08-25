class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int o = s3.size();
        
        if (m+n!=o) return false;
        
        vector<bool> dp(n + 1);
        dp[0]=true;
        
        for (int i=0;i<=m;i++) {
            for (int j=0;j<=n;j++) {
                int k=i+j-1;  
                
                if(i>0)
                    dp[j]=dp[j] && s1[i-1] == s3[k];
                if (j > 0)
                    dp[j]=dp[j] || (dp[j-1] && s2[j-1] == s3[k]);
            }
        }
        
        return dp[n];
    }
};