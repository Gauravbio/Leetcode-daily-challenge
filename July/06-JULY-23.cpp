class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int sum=0;
        int ans=1e9;
        int n=nums.size();
        for(int j=0;j<n;j++) {
            sum+=nums[j];

            while(i<=j && sum>=target) {
                ans=min(ans,j-i+1);
                sum-=nums[i++];
            }
        }
        if(ans==1e9) return 0;
        return ans;
    }
};