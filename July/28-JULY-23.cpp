class Solution {
    bool solve(int i,int j,int tar,int profit,vector<int>& nums) {
        if(profit>=tar) return true;
        if(i>j) return 0;
        
        return (solve(i+2,j,tar,profit+nums[i],nums) && solve(i+1,j-1,tar,profit+nums[i],nums))|| (solve(i,j-2,tar,profit+nums[j],nums) && solve(i+1,j-1,tar,profit+nums[j],nums));
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int tar=accumulate(nums.begin(),nums.end(),0)+1;
        tar/=2;
        return solve(0,n-1,tar,0,nums);
    }
};