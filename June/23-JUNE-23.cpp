class Solution {
public:
    int solve(vector<int> &nums,int n,int diff,int index,unordered_map<int,int> *dp) {
        cout<<index<<" "<<diff<<endl;
        if(dp[index].count(diff)) return dp[index][diff];
        int count=0;
        for(int i=index-1;i>=0;i--) {
            if(nums[index]-nums[i]==diff) {
                count++;
                index=i;
            }
        }
        dp[index][diff]=count;
        return count;
    }
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        int ans=0;
        unordered_map<int,int> dp[n+1];

        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                int diff=nums[i]-nums[j];
                int count=1;

                if(dp[j].count(diff)) {
                    count=dp[j][diff];
                }

                dp[i][diff]=1+count;
                ans=max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
};