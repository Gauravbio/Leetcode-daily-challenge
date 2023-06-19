class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        int n=gain.size();
        int prefix=0;

        for(int i=0;i<n;i++) {
            prefix+=gain[i];
            ans=max(prefix,ans);
        }

        return ans;
    }
};