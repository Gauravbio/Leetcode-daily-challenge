class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();

        for(int i=n-2;i>=0;i--) {
          if(nums[i]>nums[i+1]) {
            int op=ceil(double(nums[i])/nums[i+1]);
            ans+=(op-1);
            nums[i]/=op;
          }
        }

        return ans;
    }
};