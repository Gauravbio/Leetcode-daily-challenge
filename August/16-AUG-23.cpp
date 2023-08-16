class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int> mp;
        int n=nums.size();
        int i=0;
        for(i=0;i<k-1;i++) mp[nums[i]]++;
        vector<int> ans;

        int j=0;
        for(;i<n;i++) {
            mp[nums[i]]++;
            ans.push_back(mp.rbegin()->first);
            mp[nums[j]]--;
            if(mp[nums[j]]==0) mp.erase(nums[j]);
            j++;
        }

        return ans;
    }
};