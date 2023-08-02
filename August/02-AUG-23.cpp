class Solution {
    void solve(vector<vector<int>> &ans,vector<int> &nums,int index,int n) {
        if(index==n) {
            ans.push_back(nums);
            return;
        }

        for(int i=index;i<n;i++) {
            swap(nums[i],nums[index]);
            solve(ans,nums,index+1,n);
            swap(nums[i],nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        solve(ans,nums,0,n);
        return ans;
    }
};