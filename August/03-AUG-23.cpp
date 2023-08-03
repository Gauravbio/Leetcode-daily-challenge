class Solution {
public:

    void solve(string &digits,string &s,vector<string> &ans,int index,int n,unordered_map<int,string> &map) {
        if(index==n) {
            ans.push_back(s);
            return ;
        }
        
        string str=map[digits[index]-'0'];
        cout<<str;
        for(auto c: str) {
            s.push_back(c);
            solve(digits,s,ans,index+1,n,map);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string s;
        unordered_map<int,string> mapping;
        char c='a';
        if(digits.size()==0) return ans;

        for(int i=2;i<=9;i++) {
            if(i==7 || i==9) {
                for(int j=0;j<4;j++) {
                    mapping[i]+=c;
                    c++;
                }
            }
            else {
                for(int j=0;j<3;j++) {
                    mapping[i]+=c;
                    c++;
                }
            }
        }

        solve(digits,s,ans,0,digits.size(),mapping);
        return ans;
    }
};