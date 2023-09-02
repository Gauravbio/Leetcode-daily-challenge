class Solution {
  int solve(string &s,unordered_set<string> &dict,int index,int n,vector<int> &dp) {
    if(index==n) return 0;
    if(dp[index]!=-1) return dp[index];
    int currAns=n;
    string tempStr="";

    for(int i=index;i<n;i++) {
      tempStr+=s[i];
      int right=solve(s,dict,i+1,n,dp);

      if(dict.count(tempStr)) currAns=min(currAns,right);
      else currAns=min(currAns,(i-index+1) + right);
    }

    return dp[index]=currAns;
  }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n=s.size();
        vector<int> dp(n,-1);
        unordered_set<string> dict(dictionary.begin(),dictionary.end());
        return solve(s,dict,0,n,dp);
    }
};