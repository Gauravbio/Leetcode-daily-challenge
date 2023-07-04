class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<32;i++) {
            int mask=1<<i;
            int set_bits=0;
            for(int j=0;j<n;j++) {
                if(mask & nums[j]) set_bits++;
            }

            set_bits%=3;

            if(set_bits) ans|=( 1<<i ); 
        }

        return ans;
    }
};