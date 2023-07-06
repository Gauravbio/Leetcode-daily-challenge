class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>> pq;
        // pq.push({-1e9-7,-1,-1});

        int m=nums1.size();
        int n=nums2.size();
        for(int j=0;j<min(n,k);j++) pq.push({nums1[0]+nums2[j],nums1[0],nums2[j]});

        for(int i=1;i<min(k,m);i++) {
            for(int j=0;j<min(k,n);j++) {
                if(pq.size()<k) pq.push({nums1[i]+nums2[j],nums1[i],nums2[j]});
                else {
                    auto top=pq.top();
                    if(top[0]>nums1[i]+nums2[j]) {
                        pq.pop();
                        pq.push({nums1[i]+nums2[j],nums1[i],nums2[j]});
                    }
                    else break;
                }
            }
        }

        vector<vector<int>> ans;

        while(!pq.empty()) {
            auto top=pq.top();
            pq.pop();
            ans.push_back({top[1],top[2]});
        }

        return ans;
    }
};