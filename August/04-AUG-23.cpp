class Solution {
public:
    bool solve(string s, vector<string>& wordDict,unordered_set<string> &set,vector<int> &dp,int start,int n) {
        if(n==start) return 1;
        if(dp[start]!=-1) return dp[start];
        
        for(int i=start;i<n;i++) {
            if(set.count(s.substr(start,i+1-start)) && solve(s,wordDict,set,dp,i+1,n)) {
                dp[start]=1;
                return 1;
            }
        }
        dp[start]=0;
        return dp[start];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(),-1);
        unordered_set<string> set(wordDict.begin(),wordDict.end());
        return solve(s,wordDict,set,dp,0,s.size());
    }
};