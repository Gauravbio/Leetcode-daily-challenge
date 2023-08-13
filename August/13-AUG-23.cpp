class Solution {
    bool isThreeCons(vector<int> &nums,int n,int index) {
        if((index+3)>n) return 0;

        if(nums[index]==(nums[index+1]-1) && nums[index]==(nums[index+2]-2)) return 1;
        return 0;
    }

    bool solve(vector<int> &nums,int n,int index,vector<int> &dp) {
        if(index==n) return 1;
        if(dp[index]!=-1) return dp[index];

        if((index+1)<n && nums[index]==nums[index+1]) {
            dp[index]=solve(nums,n,index+2,dp);
            if(dp[index]) return 1;

            if((index+2)<n && nums[index]==nums[index+2]) {
                dp[index]=solve(nums,n,index+3,dp);
                if(dp[index]) return 1;
            }
        }
        else if(isThreeCons(nums,n,index)) {
            dp[index]=solve(nums,n,index+3,dp);
            if(dp[index]) return 1;
        }

        return dp[index]=false;
    }
public:
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(nums,n,0,dp);
    }
};