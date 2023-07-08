class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long> v;
        long long n=weights.size();

        for(int i=0;i<n-1;i++) {
            v.push_back(1ll*weights[i]+weights[i+1]);
        }

        long long maxi=0;
        long long mini=0;

        sort(v.begin(),v.end());
        for(int i=0;i<k-1;i++) {
            mini+=v[i];
            maxi+=v[n-2-i];
        }


        return (maxi-mini);
    }
};