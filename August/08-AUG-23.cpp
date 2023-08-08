class Solution {
public:
    int pivot(vector<int> &nums) {
        int start=0;
        int end=nums.size()-1;
        int ans=0;

        while(start<=end) {
            int mid=(start+(end-start)/2);
            if(nums[0]>nums[mid]) {
                end=mid-1;
            }
            else {
                ans=mid;
                start=mid+1;
            }
        }
        return ans;
    }

    int bs(vector<int>& nums, int target,int start,int end) {
        while(start<=end) {
            int mid=start+(end-start)/2;

            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) end=mid-1;
            else start=mid+1;
        }

        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivotIndex=pivot(nums);

        if(target>=nums[0]) {
            return bs(nums,target,0,pivotIndex);
        }
        else return bs(nums,target,pivotIndex+1,nums.size()-1);
    }
};