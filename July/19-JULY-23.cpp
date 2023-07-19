class Solution {
    bool isOverlapping(vector<int> &v1,vector<int> &v2) {
        if(v2[1]>v1[0]) return 1;
        return 0;
    }
    static bool compare(vector<int> &a,vector<int> &b) {
            return (a[1]<b[1]);
        }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        int n=intervals.size();
        int ans=0;
        vector<int> prev=intervals[0];
        for(int i=1;i<n;i++) {
            if(isOverlapping(intervals[i],prev)) {
                ans++;
            }
            else prev=intervals[i];
        }

        return ans;
    }
};