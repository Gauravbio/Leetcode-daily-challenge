class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,0),cnt(n,1);
        int lis=0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(nums[i]>nums[j] && dp[i]==1+dp[j]) {
                    cnt[i]+=cnt[j];
                }
                else if(nums[i]>nums[j] && dp[i]<1+dp[j]) {
                    dp[i]=1+dp[j];
                    cnt[i]=cnt[j];
                }
            }
            lis=max(lis,dp[i]);
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==lis) ans+=cnt[i];
        }

        return ans;
    }
};