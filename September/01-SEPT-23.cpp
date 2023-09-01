class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;

        for(int i=0;i<=n;i++) {
          int temp=i;
          int count=0;

          while(temp){
            int bit=temp&1;
            if(bit==1) count++;
            temp>>=1;
          }

          ans.push_back(count);
        }

        return ans;
    }
};