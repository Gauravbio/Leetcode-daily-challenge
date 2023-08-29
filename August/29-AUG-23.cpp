class Solution {
public:
    int bestClosingTime(string customers) {
      int n=customers.size();
      int profit=0;
      int max_profit=0;
      int ans=0;

      for(int i=0;i<n;i++) {
        if(customers[i]=='Y') profit++;
        else profit--;

        if(max_profit<profit) {
          max_profit=profit;
          ans=(i+1);
        }
      }

      return ans;
    }
};