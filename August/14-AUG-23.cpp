class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int n=nums.size();
        int i=0;
        for(i=0;i<k;i++) {
            pq.push(nums[i]);
        }

        for(;i<n;i++) {
            if(pq.top()<nums[i]) {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top();
    }
};