class Solution {
    private:
    int mod=1e9+7;
    long long solve(vector<vector<long long>> &combinations,vector<int> &nums) {
        int n=nums.size();
        if(n<=2) return 1;

        vector<int> left,right;

        for(int i=1;i<n;i++) {
            if(nums[0]<nums[i]) right.push_back(nums[i]);
            else left.push_back(nums[i]);
        }

        long long left_ans=solve(combinations,left)%mod;
        long long right_ans=solve(combinations,right)%mod;

        long long ans = (combinations[n-1][left.size()]*left_ans)%mod;
        ans=(ans*right_ans)%mod;
        return ans;
    }
public:
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>> combinations(n+1 , vector<long long>(n+1,1));

        for(int i = 1; i < n + 1; ++i){
            for(int j = 1; j < i; ++j){
                combinations[i][j] = (combinations[i-1][j-1] + combinations[i-1][j]) % mod;
            }
        }

        return (solve(combinations,nums)%mod-1);
    }
};