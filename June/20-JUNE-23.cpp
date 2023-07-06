class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k==0) return nums;
        int n=nums.size();

        //neglecting answer space solution space complexity is O(1)
        vector<int> ans(n,-1);


        int totk = (n+1)/2;
        if(totk<=k) return ans;


        // reduced problem with prefixes of (2*k+1)
        // because sum of [i-k,i+k] indices can be written as [0,2*k+1]
        int temp=k;
        k=(2*k);
        long long pre=0;
        int i=0;

        //prefix calculation
        for(i=0;i<k;i++) {
            pre+=nums[i];
        }

        int ind=temp;
        int low=0;
        int total=k+1;

        // answer loop
        for(;i<n;i++) {
            pre+=nums[i];
            if(pre==0) {
                ans[ind++]=0;
            }
            else ans[ind++]=(pre/total);

            pre-=nums[low++];
        }

        return ans;
    }
};