class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int,bool>,vector<pair<int,bool>>,greater<pair<int,bool>>> pq;
        long long ans=0;
        int n=costs.size();


        int low=min(n-1,candidates-1);
        for(int i=0;i<=low;i++) {
            pq.push({costs[i],0});
        }

        int high=max(low+1,n-candidates);
        for(int i=n-1;i>=high;i--) {
            pq.push({costs[i],1});
        }

        while(k && low<high) {
            auto top=pq.top();
            ans+=top.first;
            pq.pop();
            k--;

            if(top.second) {
                high--;
                if(low<high) pq.push({costs[high],1});
            }
            else {
                low++;
                if(low<high) pq.push({costs[low],0});
            }
        }

        while(k && !pq.empty()) {
            ans+=pq.top().first;
            pq.pop();
            k--;
        }

        return ans;
    }
};