class Solution {
public:
    set<vector<int>>s;
    void solve(vector<int>& arr,int idx, int target, vector<vector<int>>&ans, vector<int>&comb)
    {
        if(idx == arr.size() || target<0)
        {
            return;
        }
        if(target == 0){
            if(s.find(comb)==s.end())
            ans.push_back(comb);
            s.insert(comb);
            
        }
        comb.push_back(arr[idx]);
        solve(arr,idx+1,target-arr[idx],ans,comb);
        solve(arr,idx,target-arr[idx],ans,comb);
        comb.pop_back();
        solve(arr,idx+1,target,ans,comb);
        

    }

    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<vector<int>>ans;
       vector<int>comb;
       solve(candidates,0,target,ans,comb);
       return ans;
    }
};