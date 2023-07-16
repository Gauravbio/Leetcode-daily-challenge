class Solution {
    private:
    int solve(vector<int>&skills,int curr_mask,int index,int req_mask,vector<vector<int>> &choice,vector<vector<int>> &dp) {
        if(req_mask==curr_mask) return 0;
        if(index==skills.size()) return 10000;
        if(dp[curr_mask][index]!=-1) return dp[curr_mask][index];

        int exclude=solve(skills,curr_mask,index+1,req_mask,choice,dp);
        int include=1+solve(skills,curr_mask | (skills[index]),index+1,req_mask,choice,dp);

        if(include<exclude) {
            choice[curr_mask][index]=1;
        }
        return dp[curr_mask][index]=min(include,exclude);
    }
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string,int> map;
        int n=req_skills.size();

        for(int i=0;i<n;i++){
            map[req_skills[i]]=i;
        }

        vector<int> skills;
        int p=people.size();

        for(int i=0;i<p;i++){
            int person=0;
            for(auto skill: people[i]) {
                person |= (1<<map[skill]);
            }
            skills.push_back(person);
        }

        int req_mask= (1<<n)-1;
        vector<vector<int>> choice(req_mask+1,vector<int> (p,0));
        vector<vector<int>> dp(req_mask+1,vector<int> (p,-1));
        solve(skills,0,0,req_mask,choice,dp);

        int mask=0;
        vector<int> ans;
        for(int i=0;i<p;i++) {
            if(choice[mask][i]) {
                mask |= skills[i];
                ans.push_back(i);
            }
        }

        return ans;
    }
};