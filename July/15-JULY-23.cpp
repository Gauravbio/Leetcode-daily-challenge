class Solution {
    private:
    int solve(vector<vector<int>>& events, int k,int index,int curr_day,int n,vector<unordered_map<int,int>> &dp){
        if(k==0) return 0;
        if(index==n) return 0;
        if(dp[k].count(curr_day)) return dp[k][curr_day];

        int include=INT_MIN;
        if(curr_day<=events[index][0]) {
            include=events[index][2]+solve(events,k-1,index+1,events[index][1]+1,n,dp);
        }

        int exclude=solve(events,k,index+1,curr_day,n,dp);

        return dp[k][curr_day]=max(include,exclude);
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        int n=events.size();
        vector<unordered_map<int,int>> dp(k+1);
        return solve(events,k,0,1,n,dp);
    }
};