class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        vector<string> ans;
        if(n==0) return ans;
        int startIndex=0;


        for(int i=0;i<n-1;i++) {
            if((nums[i]+1)!=nums[i+1]) {
                string s;
                if(startIndex==i) {
                    s+=to_string(nums[startIndex++]);
                    ans.push_back(s);
                    continue;
                }
                
                s+=to_string(nums[startIndex]);
                s+="->";
                s+=to_string(nums[i]);
                ans.push_back(s);
                startIndex=i+1;
            }
        }

        if(n>1 && (nums[n-2]+1)==nums[n-1]) {
            string s;
            s+=to_string(nums[startIndex]);
            s+="->";
            s+=to_string(nums[n-1]);
            ans.push_back(s);
        }
        else {
            string s;
            s+=to_string(nums[n-1]);
            ans.push_back(s);
        }

        return ans;
    }
};