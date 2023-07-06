class Solution {
public:
    string mapping(vector<int> & row){

        string ans="";

        for(int j:row)
            ans+=to_string(j)+"#";
        
        return ans;
    }
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=0;

        // brute force
        for(int row=0;row<n;row++){
            for(int col=0;col<n; col++) {
                bool flag=1;
                for(int i=0;i<n;i++) {
                    if(grid[row][i]!=grid[i][col]) {
                        flag=0;
                        break;
                    }
                }
                if(flag) ans++;
            }
        }

        // hash-map
        unordered_map<string,int> mp;
        for(int i=0; i<n;i++)
            mp[mapping(grid[i])]++;
        

        for(int i=0; i<n;i++){

            string s="";

            for(int j=0; j<n;j++)
                s+=to_string(grid[j][i])+"#";
            
             ans+=mp[s];
        }


        return ans;
    }
};