class Solution {

    bool isPossible(int mid,vector<int> &nums,int p) {
        int n=nums.size();
        int start=0;
        for(int end=1;end<n;) {
            if((nums[end]-nums[start])<=mid) {
                p--;
                start=end+1;
                end+=2;
            }
            else {
                start++;
                if(start==end) end++;
            }
        }

        return (p<=0);
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());

        int start=0,end=*max_element(nums.begin(),nums.end());

        while(start<end) {
            int mid=start+(end-start)/2;

            if(isPossible(mid,nums,p)) {
                end=mid;
            }
            else start=mid+1;
        }

        return start;
    }
};