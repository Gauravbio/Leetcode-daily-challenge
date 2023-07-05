class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> suf(n,0);

        suf[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--) {
            if(nums[i]==0) {
                suf[i]=0;
            }
            else {
                suf[i]=suf[i+1]+1;
            }
        }

        int ones=0;
        int ans=0;
        for(int i=0;i<n;i++) {
            if(nums[i]==0) {
                int tot_ones=ones;
                if(i<n-1)
                    tot_ones+=suf[i+1];
                ones=0;
                ans=max(ans,tot_ones);
            }
            else ones++;
        }

        if(suf[0]==n) return n-1;
        return ans;
    }
};