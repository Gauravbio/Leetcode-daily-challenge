class Solution {
  bool solve(vector<int>& stones,int index,int n,int prevJump,unordered_map<int,int> &mp,vector<vector<int>> &dp) {
    if(index==(n-1)) return 1;
    if(dp[index][prevJump]!=-1) return dp[index][prevJump];

    bool ans=0;
    int curr=stones[index];
    
    if(prevJump>1 && mp.count(curr+(prevJump-1))) {
      ans=solve(stones,mp[curr+(prevJump-1)],n,prevJump-1,mp,dp);
    }

    if(mp.count(curr+prevJump)) {
      ans=(ans || solve(stones,mp[curr+prevJump],n,prevJump,mp,dp));
    }

    if(mp.count(curr+(prevJump+1))) {
      ans=(ans || solve(stones,mp[curr+(prevJump+1)],n,prevJump+1,mp,dp));
    }

    return dp[index][prevJump]=ans;
  }

public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        unordered_map<int,int> mp;
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        for(int i=0;i<n;i++) {
          mp[stones[i]]=i;
        }
        if(!mp.count(stones[0]+1)) return 0;
        return solve(stones,1,n,1,mp,dp);
    }
};